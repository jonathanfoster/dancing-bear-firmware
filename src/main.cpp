#include <Arduino.h>

#include "events/event_loop.h"
#include "logging/logger.h"
#include "machine/button.h"
#include "machine/pin.h"

#define BUTTON_PIN 36
#define LED_PIN 12
#define MOTOR_PIN 14
#define SERIAL_BAUD 9600

machine::Button* button;
events::EventLoop* event_loop;
machine::Pin* led_pin;
machine::Pin* motor_pin;
logging::Logger* logger;

void checkButtonValue() { button->checkValue(); }

void buttonPressed(machine::Button* button) {
  led_pin->toggle();
  motor_pin->toggle();
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial.println("");
  logger = new logging::Logger("main");

  button = new machine::Button(BUTTON_PIN, HIGH);
  button->onPress(buttonPressed);

  led_pin = new machine::Pin(LED_PIN, OUTPUT);
  led_pin->off();

  motor_pin = new machine::Pin(MOTOR_PIN, OUTPUT);
  motor_pin->off();

  event_loop = new events::EventLoop();
  event_loop->createTask(checkButtonValue);

  logger->info("application started");
}

void loop() { event_loop->run(); }
