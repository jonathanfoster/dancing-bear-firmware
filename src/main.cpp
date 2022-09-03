#include <Arduino.h>

#include "audio/audio_player.h"
#include "audio/songs.h"
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
machine::Pin* led_pin;
machine::Pin* motor_pin;
machine::Pin* speaker_pin;

void buttonCheckValueTask(void* parameter) {
  for (;;) {
    button->checkValue();
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void buttonPressed(machine::Button* sender) {
  led_pin->toggle();
  motor_pin->toggle();
  audio_player->play(audio::merry_christmas_melody);
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial.println("");

  button = new machine::Button(BUTTON_PIN, HIGH);
  button->onPress(buttonPressed);

  audio_player = new audio::AudioPlayer(AUDIO_PLAYER_PIN);
  led_pin = new machine::Pin(LED_PIN, OUTPUT);
  motor_pin = new machine::Pin(MOTOR_PIN, OUTPUT);

  xTaskCreate(buttonCheckValueTask, "Button Check Value", 1024, NULL, 1, NULL);

  LOG_INFO("main", "application started");
}

void loop() {}
