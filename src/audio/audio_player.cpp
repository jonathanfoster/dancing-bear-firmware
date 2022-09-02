#include "audio/audio_player.h"

#include <Arduino.h>

#include "audio/melody.h"
#include "audio/note.h"
#include "logging/logger.h"

namespace audio {

AudioPlayer::AudioPlayer(uint8_t pin_id) { this->_pin_id = pin_id; }

bool AudioPlayer::isPlaying() { return this->_is_playing; }

bool AudioPlayer::repeat() { return this->_is_repeat; }

void AudioPlayer::repeat(bool new_value) { this->_is_repeat = new_value; }

void AudioPlayer::pause() {
  // TODO: Stop playing song, don't reset frame index
  this->_is_playing = false;
}

void AudioPlayer::play(Melody* melody) {
  // TODO: Play song
  this->_melody = melody;
  this->_is_playing = true;

  LOG_DEBUG("audio_player", "starting melody");
  LOG_DEBUG(
      "audio_player",
      (String("melody.length()=") + String(this->_melody->length())).c_str());

  for (int i = 0; i < this->_melody->length(); i++) {
    Note note = this->_melody->get(i);
    LOG_DEBUG("audio_player",
              (String("playing note:note.frequency=") + String(note.frequency) +
               String(":note.duration=") + String(note.duration))
                  .c_str());
    tone(this->_pin_id, note.frequency, note.duration * 0.9);
    delay(note.duration);
    noTone(this->_pin_id);
  }

  LOG_DEBUG("audio_player", "melody complete");
}

void AudioPlayer::stop() {
  // TODO: Stop playing song, reset frame index
  this->_melody = NULL;
  this->_is_playing = false;
}

}  // namespace audio
