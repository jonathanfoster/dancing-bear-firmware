#include <Arduino.h>

#include "audio/audio_player.h"
#include "audio/songs.h"
#include "events/event_loop.h"
#include "logging/logger.h"
#include "machine/button.h"
#include "machine/pin.h"

#define SERIAL_BAUD 9600

#define AUDIO_PLAYER_PIN 14
#define BUTTON_PIN 36
#define LED_PIN 25
#define MOTOR_PIN 12

audio::AudioPlayer* audio_player;
machine::Button* button;
events::EventLoop* event_loop;
machine::Pin* led_pin;
machine::Pin* motor_pin;
machine::Pin* speaker_pin;

void checkButtonValue() { button->checkValue(); }

void buttonPressed(machine::Button* sender) {
  led_pin->toggle();
  motor_pin->toggle();
  if (!audio_player->isPlaying()) {
    audio_player->play(audio::merry_christmas_melody);
  } else {
    audio_player->stop();
  }
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial.println("");

  button = new machine::Button(BUTTON_PIN, HIGH);
  button->onPress(buttonPressed);

  audio_player = new audio::AudioPlayer(AUDIO_PLAYER_PIN);
  led_pin = new machine::Pin(LED_PIN, OUTPUT);
  motor_pin = new machine::Pin(MOTOR_PIN, OUTPUT);

  event_loop = new events::EventLoop();
  event_loop->createTask(checkButtonValue);

  LOG_INFO("main", "application started");
}

void loop() { event_loop->run(); }
