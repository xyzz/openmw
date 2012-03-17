#ifndef GAME_SOUND_OPENAL_OUTPUT_H
#define GAME_SOUND_OPENAL_OUTPUT_H

#include <string>

#include "alc.h"
#include "al.h"

#include "sound_output.hpp"

namespace MWSound
{
    class SoundManager;
    class Sound_Decoder;
    class Sound;

    class OpenAL_Output : public Sound_Output
    {
        ALCdevice *Device;
        ALCcontext *Context;

        virtual bool Initialize(const std::string &devname="");
        virtual void Deinitialize();

        virtual Sound *StreamSound(const std::string &fname, std::auto_ptr<Sound_Decoder> decoder);

        OpenAL_Output(SoundManager &mgr);
        virtual ~OpenAL_Output();

        friend class SoundManager;
    };
#ifndef DEFAULT_OUTPUT
#define DEFAULT_OUTPUT OpenAL_Output
#endif
};

#endif
