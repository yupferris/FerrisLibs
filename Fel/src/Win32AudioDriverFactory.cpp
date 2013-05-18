#include <Fel/AudioDriverFactory.h>

#include <Fel/Win32DirectSoundAudioDriver.h>

namespace Fel
{
	IAudioDriver *AudioDriverFactory::CreateDefault()
	{
		return new Win32DirectSoundAudioDriver();
	}
}
