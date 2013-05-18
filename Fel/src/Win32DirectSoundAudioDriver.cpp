#include <Fel/Win32DirectSoundAudioDriver.h>

using namespace Fsl;

namespace Fel
{
	Win32DirectSoundAudioDriver::Win32DirectSoundAudioDriver(int latencyMs, int sampleRate, RenderCallback renderCallback, void *userData)
	{
		this->latencyMs = latencyMs;
		this->sampleRate = sampleRate;
		enabled = true;
		this->renderCallback = renderCallback;
		this->userData = userData;

		DirectSoundCreate8(0, &device, 0);
		device->SetCooperativeLevel(GetForegroundWindow(), DSSCL_NORMAL);

		createBuffers();

		mutex = Mutex::Create();
		mutex->Lock();
		thread = CreateThread(0, 0, threadProc, (LPVOID)this, 0, 0);
		SetThreadPriority(thread, THREAD_PRIORITY_HIGHEST);
		mutex->Unlock();
	}

	Win32DirectSoundAudioDriver::~Win32DirectSoundAudioDriver()
	{
		mutex->Lock();
		TerminateThread(thread, 0);
		mutex->Unlock();
		delete mutex;

		destroyBuffers();

		device->Release();
	}

	void Win32DirectSoundAudioDriver::SetRenderCallback(RenderCallback renderCallback, void *userData)
	{
		mutex->Lock();
		this->renderCallback = renderCallback;
		this->userData = userData;
		mutex->Unlock();
	}

	void Win32DirectSoundAudioDriver::SetEnabled(bool enabled)
	{
		mutex->Lock();
		this->enabled = enabled;
		mutex->Unlock();
	}

	bool Win32DirectSoundAudioDriver::GetEnabled() const
	{
		mutex->Lock();
		auto ret = enabled;
		mutex->Unlock();
		return ret;
	}

	void Win32DirectSoundAudioDriver::SetLatencyMs(int latencyMs)
	{
		mutex->Lock();
		this->latencyMs = latencyMs;
		recreateBuffers();
		mutex->Unlock();
	}

	int Win32DirectSoundAudioDriver::GetLatencyMs() const
	{
		mutex->Lock();
		auto ret = latencyMs;
		mutex->Unlock();
		return ret;
	}

	int Win32DirectSoundAudioDriver::GetSampleRate() const
	{
		mutex->Lock();
		auto ret = sampleRate;
		mutex->Unlock();
		return ret;
	}

	DWORD WINAPI Win32DirectSoundAudioDriver::threadProc(LPVOID lpParameter)
	{
		auto driver = (Win32DirectSoundAudioDriver *)lpParameter;

		while (true)
		{
			driver->mutex->Lock();

			int playCursorPos;
			driver->buffer->GetCurrentPosition((LPDWORD)&playCursorPos, 0);
			int bytesToRender = playCursorPos - driver->oldPlayCursorPos;
			if (bytesToRender)
			{
				if (bytesToRender < 0) bytesToRender += driver->bufferSizeBytes;
				short *p1, *p2;
				int b1, b2;
				driver->buffer->Lock(driver->oldPlayCursorPos, bytesToRender, (LPVOID *)&p1, (LPDWORD)&b1, (LPVOID *)&p2, (LPDWORD)&b2, 0);
				driver->renderSamples(p1, b1 / sizeof(short));
				if (b2) driver->renderSamples(p2, b2 / sizeof(short));
				driver->buffer->Unlock(p1, b1, p2, b2);
				driver->oldPlayCursorPos = playCursorPos;
			}

			driver->mutex->Unlock();

			Sleep(3);
		}
	}

	void Win32DirectSoundAudioDriver::createBuffers()
	{
		int channels = 2;
		int bitsPerSample = 16;
		int bytesPerSample = bitsPerSample / 8;
		int blockAlign = channels * bytesPerSample;
		int bytesPerSec = sampleRate * blockAlign;

		int floatBuffersSize = sampleRate * channels * latencyMs / 1000;
		leftBuffer = new float[floatBuffersSize];
		rightBuffer = new float[floatBuffersSize];

		bufferSizeBytes = floatBuffersSize * bytesPerSample;
		WAVEFORMATEX bufferFormat =
		{
			WAVE_FORMAT_PCM,
			channels,
			sampleRate,
			bytesPerSec,
			blockAlign,
			bitsPerSample,
			0
		};
		DSBUFFERDESC bufferDesc =
		{
			sizeof(DSBUFFERDESC),
			DSBCAPS_GLOBALFOCUS | DSBCAPS_GETCURRENTPOSITION2,
			bufferSizeBytes,
			0,
			&bufferFormat,
			GUID_NULL
		};
		device->CreateSoundBuffer(&bufferDesc, &buffer, 0);

		oldPlayCursorPos = 0;
		buffer->Play(0, 0, DSBPLAY_LOOPING);
	}

	void Win32DirectSoundAudioDriver::destroyBuffers()
	{
		delete leftBuffer;
		delete rightBuffer;

		buffer->Stop();
		buffer->Release();
	}

	void Win32DirectSoundAudioDriver::recreateBuffers()
	{
		destroyBuffers();
		createBuffers();
	}

	void Win32DirectSoundAudioDriver::renderSamples(short *buffer, int numSamples)
	{
		if (renderCallback && enabled)
		{
			int numFloatSamples = numSamples / 2;
			renderCallback(leftBuffer, rightBuffer, numFloatSamples, userData);
			for (int i = 0; i < numSamples; i++)
			{
				int sample = (int)((i & 1 ? rightBuffer : leftBuffer)[i / 2] * 32767.0f);
				if (sample < -32768) sample = -32768;
				if (sample > 32767) sample = 32767;
				buffer[i] = (short)sample;
			}
		}
		else
		{
			memset(buffer, 0, sizeof(short) * numSamples);
		}
	}
}
