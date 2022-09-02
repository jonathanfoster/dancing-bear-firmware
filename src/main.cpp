#include <Arduino.h>

#include "events/event_loop.h"
#include "logging/logger.h"
#include "machine/button.h"
#include "machine/pin.h"

#define BUTTON_PIN 36
#define MOTOR_PIN 0
#define SERIAL_BAUD 9600

machine::Pin* button_pin;
machine::Pin* motor_pin;
events::EventLoop* event_loop;
logging::Logger* logger;

void buttonChange(machine::Pin* pin) {
  logger->info(
      (String("button changed:value=") + String(pin->value())).c_str());
}

void checkPinValue() { button_pin->checkValue(); }

void logButtonPress() {
  logger->info("button pressed: toggling motor");
  motor_pin->toggle();
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial.println("");
  logger = new logging::Logger("main");

  button_pin = new machine::Pin(BUTTON_PIN, INPUT, HIGH);
  button_pin->onChange(buttonChange);

  motor_pin = new machine::Pin(MOTOR_PIN, OUTPUT);

  event_loop = new events::EventLoop();
  event_loop->createTask(checkPinValue);

  logger->info("application started");
}

void loop() { event_loop->run(); }
