#ifndef __FEL_IAUDIODRIVER_H__
#define __FEL_IAUDIODRIVER_H__

namespace Fel
{
	class IAudioDriver
	{
	public:
		typedef void (* RenderCallback)(float *leftBuffer, float *rightBuffer, int numSamples, void *userData);

		virtual ~IAudioDriver();

		virtual void SetRenderCallback(RenderCallback renderCallback, void *userData) = 0;

		virtual void SetEnabled(bool enabled) = 0;
		virtual bool GetEnabled() const = 0;

		virtual void SetLatencyMs(int latencyMs) = 0;
		virtual int GetLatencyMs() const = 0;

		virtual int GetSampleRate() const = 0;
	};
}

#endif
