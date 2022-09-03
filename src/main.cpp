#include <Arduino.h>

#include "audio/audio_player.h"
#include "audio/songs.h"
#include "config.h"
#include "logging/logger.h"
#include "machine/button.h"
#include "machine/pin.h"

audio::AudioPlayer* audio_player;
machine::Button* button;
machine::Pin* led_pin;
machine::Pin* motor_pin;
machine::Pin* speaker_pin;

void buttonPressed(machine::Button* sender) {
  LOG_INFO("main", "button pressed");
  LOG_INFO("main", "toggling led");
  led_pin->toggle();
  LOG_INFO("main", "toggling motor");
  motor_pin->toggle();
  if (!audio_player->isPlaying()) {
    LOG_INFO("main", "playing melody");
    audio_player->play(audio::merry_christmas_melody);
  } else {
    LOG_INFO("main", "stopping melody");
    audio_player->stop();
  }
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial.print(LOGO);

  LOG_INFO("main", "initializing application");

  button = new machine::Button(BUTTON_PIN, HIGH);
  button->onPress(buttonPressed);

  audio_player = new audio::AudioPlayer(AUDIO_PLAYER_PIN);
  led_pin = new machine::Pin(LED_PIN, OUTPUT);
  motor_pin = new machine::Pin(MOTOR_PIN, OUTPUT);

  LOG_INFO("main", "application started");
}

void loop() {}
