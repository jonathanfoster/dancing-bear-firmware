#ifndef AUDIO_AUDIO_H
#define AUDIO_AUDIO_H

#include <Arduino.h>

#include "audio/melody.h"

namespace audio {

class AudioPlayer {
 public:
  AudioPlayer(uint8_t pin_id);
  ~AudioPlayer();

  bool isPlaying();

  void play(Melody* melody);
  void stop();

 private:
  static void playMelodyTask(void* parameter);

  Melody* _melody = NULL;
  bool _is_playing = false;
  uint8_t _pin_id = 0;
  TaskHandle_t _play_melody_task_handle = NULL;
};

}  // namespace audio

#endif  // AUDIO_AUDIO_H
