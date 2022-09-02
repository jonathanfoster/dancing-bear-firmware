#ifndef AUDIO_AUDIO_H
#define AUDIO_AUDIO_H

#include <Arduino.h>

#include "audio/melody.h"

namespace audio {

class AudioPlayer {
 public:
  AudioPlayer(uint8_t pin_id);

  bool isPlaying();
  bool repeat();
  void repeat(bool new_value);

  void pause();
  void play(Melody* melody);
  void stop();

 private:
  Melody* _melody = NULL;
  bool _is_playing = false;
  uint8_t _pin_id = 0;
  bool _is_repeat = false;
};

}  // namespace audio

#endif  // AUDIO_AUDIO_H
