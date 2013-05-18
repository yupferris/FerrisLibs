#ifndef __FEL_WIN32DIRECTSOUNDAUDIODRIVER_H__
#define __FEL_WIN32DIRECTSOUNDAUDIODRIVER_H__

#include "IAudioDriver.h"

#include <Fsl.h>

#include <Windows.h>
#include <dsound.h>

namespace Fel
{
	class Win32DirectSoundAudioDriver : public IAudioDriver
	{
	public:
		Win32DirectSoundAudioDriver(int latencyMs = 60, int sampleRate = 44100, RenderCallback renderCallback = nullptr, void *userData = nullptr);
		virtual ~Win32DirectSoundAudioDriver();

		virtual void SetRenderCallback(RenderCallback renderCallback, void *userData);

		virtual void SetEnabled(bool enabled);
		virtual bool GetEnabled() const;

		virtual void SetLatencyMs(int latencyMs);
		virtual int GetLatencyMs() const;

		virtual int GetSampleRate() const;

	private:
		static DWORD WINAPI threadProc(LPVOID lpParameter);

		void createBuffers();
		void destroyBuffers();
		void recreateBuffers();

		void renderSamples(short *buffer, int numSamples);

		int latencyMs;
		int sampleRate;
		bool enabled;
		RenderCallback renderCallback;
		void *userData;

		LPDIRECTSOUND8 device;
		int bufferSizeBytes;
		float *leftBuffer, *rightBuffer;
		LPDIRECTSOUNDBUFFER buffer;
		int oldPlayCursorPos;

		Fsl::Mutex *mutex;
		HANDLE thread;
	};
}

#endif
