#include "audio/audio_player.h"

#include <Arduino.h>

#include "audio/melody.h"
#include "audio/note.h"

namespace audio {

AudioPlayer::AudioPlayer(uint8_t pin_id) { this->_pin_id = pin_id; }

AudioPlayer::~AudioPlayer() {
  if (this->_play_melody_task_handle) {
    vTaskDelete(this->_play_melody_task_handle);
  }
}

bool AudioPlayer::isPlaying() { return this->_is_playing; }

void AudioPlayer::play(Melody* melody) {
  this->_melody = melody;
  this->_is_playing = true;
  xTaskCreate(this->playMelodyTask, "Play Melody", configMINIMAL_STACK_SIZE,
              this, 2, &this->_play_melody_task_handle);
}

void AudioPlayer::stop() {
  this->_is_playing = false;
  if (this->_play_melody_task_handle) {
    vTaskDelete(this->_play_melody_task_handle);
  }
}

void AudioPlayer::playMelodyTask(void* parameter) {
  AudioPlayer* player = (AudioPlayer*)parameter;
  if (!player->_melody) {
    vTaskDelete(NULL);
    return;
  }

  for (int i = 0; i < player->_melody->length(); i++) {
    Note note = player->_melody->get(i);

    tone(player->_pin_id, note.frequency, note.duration * 0.9);
    vTaskDelay(note.duration / portTICK_PERIOD_MS);
    noTone(player->_pin_id);

    if (!player->_is_playing) {
      break;
    }
  }

  vTaskDelete(NULL);
}

}  // namespace audio
