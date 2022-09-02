#ifndef AUDIO_SONGS_H_
#define AUDIO_SONGS_H_

#include "audio/melody.h"
#include "audio/pitches.h"

namespace audio {

unsigned int merry_christmas_notes[] = {
    NOTE_C5, 4, NOTE_F5,  4, NOTE_F5, 8, NOTE_G5,  8, NOTE_F5, 8, NOTE_E5,  8,
    NOTE_D5, 4, NOTE_D5,  4, NOTE_D5, 4, NOTE_G5,  4, NOTE_G5, 8, NOTE_A5,  8,
    NOTE_G5, 8, NOTE_F5,  8, NOTE_E5, 4, NOTE_C5,  4, NOTE_C5, 4, NOTE_A5,  4,
    NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5,  8, NOTE_F5, 4, NOTE_D5,  4,
    NOTE_C5, 8, NOTE_C5,  8, NOTE_D5, 4, NOTE_G5,  4, NOTE_E5, 4, NOTE_F5,  2,
    NOTE_C5, 4, NOTE_F5,  4, NOTE_F5, 8, NOTE_G5,  8, NOTE_F5, 8, NOTE_E5,  8,
    NOTE_D5, 4, NOTE_D5,  4, NOTE_D5, 4, NOTE_G5,  4, NOTE_G5, 8, NOTE_A5,  8,
    NOTE_G5, 8, NOTE_F5,  8, NOTE_E5, 4, NOTE_C5,  4, NOTE_C5, 4, NOTE_A5,  4,
    NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5,  8, NOTE_F5, 4, NOTE_D5,  4,
    NOTE_C5, 8, NOTE_C5,  8, NOTE_D5, 4, NOTE_G5,  4, NOTE_E5, 4, NOTE_F5,  2,
    NOTE_C5, 4, NOTE_F5,  4, NOTE_F5, 4, NOTE_F5,  4, NOTE_E5, 2, NOTE_E5,  4,
    NOTE_F5, 4, NOTE_E5,  4, NOTE_D5, 4, NOTE_C5,  2, NOTE_A5, 4, NOTE_AS5, 4,
    NOTE_A5, 4, NOTE_G5,  4, NOTE_C6, 4, NOTE_C5,  4, NOTE_C5, 8, NOTE_C5,  8,
    NOTE_D5, 4, NOTE_G5,  4, NOTE_E5, 4, NOTE_F5,  2, NOTE_C5, 4, NOTE_F5,  4,
    NOTE_F5, 8, NOTE_G5,  8, NOTE_F5, 8, NOTE_E5,  8, NOTE_D5, 4, NOTE_D5,  4,
    NOTE_D5, 4, NOTE_G5,  4, NOTE_G5, 8, NOTE_A5,  8, NOTE_G5, 8, NOTE_F5,  8,
    NOTE_E5, 4, NOTE_C5,  4, NOTE_C5, 4, NOTE_A5,  4, NOTE_A5, 8, NOTE_AS5, 8,
    NOTE_A5, 8, NOTE_G5,  8, NOTE_F5, 4, NOTE_D5,  4, NOTE_C5, 8, NOTE_C5,  8,
    NOTE_D5, 4, NOTE_G5,  4, NOTE_E5, 4, NOTE_F5,  2, NOTE_C5, 4, NOTE_F5,  4,
    NOTE_F5, 4, NOTE_F5,  4, NOTE_E5, 2, NOTE_E5,  4, NOTE_F5, 4, NOTE_E5,  4,
    NOTE_D5, 4, NOTE_C5,  2, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_G5,  4,
    NOTE_C6, 4, NOTE_C5,  4, NOTE_C5, 8, NOTE_C5,  8, NOTE_D5, 4, NOTE_G5,  4,
    NOTE_E5, 4, NOTE_F5,  2, NOTE_C5, 4, NOTE_F5,  4, NOTE_F5, 8, NOTE_G5,  8,
    NOTE_F5, 8, NOTE_E5,  8, NOTE_D5, 4, NOTE_D5,  4, NOTE_D5, 4, NOTE_G5,  4,
    NOTE_G5, 8, NOTE_A5,  8, NOTE_G5, 8, NOTE_F5,  8, NOTE_E5, 4, NOTE_C5,  4,
    NOTE_C5, 4, NOTE_A5,  4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5,  8,
    NOTE_F5, 4, NOTE_D5,  4, NOTE_C5, 8, NOTE_C5,  8, NOTE_D5, 4, NOTE_G5,  4,
    NOTE_E5, 4, NOTE_F5,  2, NOTE_C5, 4, NOTE_F5,  4, NOTE_F5, 8, NOTE_G5,  8,
    NOTE_F5, 8, NOTE_E5,  8, NOTE_D5, 4, NOTE_D5,  4, NOTE_D5, 4, NOTE_G5,  4,
    NOTE_G5, 8, NOTE_A5,  8, NOTE_G5, 8, NOTE_F5,  8, NOTE_E5, 4, NOTE_C5,  4,
    NOTE_C5, 4, NOTE_A5,  4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5,  8,
    NOTE_F5, 4, NOTE_D5,  4, NOTE_C5, 8, NOTE_C5,  8, NOTE_D5, 4, NOTE_G5,  4,
    NOTE_E5, 4, NOTE_F5,  2, REST,    4};

Melody* merry_christmas_melody = new Melody(
    merry_christmas_notes, sizeof(merry_christmas_notes) / sizeof(int), 140);

}  // namespace audio

#endif  // AUDIO_SONGS_H_
