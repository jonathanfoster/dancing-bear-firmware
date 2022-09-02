#include <Arduino.h>

#include "events/event_loop.h"
#include "logging/logger.h"
#include "machine/button.h"
#include "machine/pin.h"

#define BUTTON_PIN 36
#define SERIAL_BAUD 9600

machine::Button* button;
events::EventLoop* event_loop;
logging::Logger* logger;

void checkValue() { button->checkValue(); }

void buttonPressed(machine::Button* button) { logger->info("button pressed"); }

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial.println("");
  logger = new logging::Logger("main");

  button = new machine::Button(BUTTON_PIN, HIGH);
  button->onPress(buttonPressed);

  event_loop = new events::EventLoop();
  event_loop->createTask(checkValue);

  logger->info("application started");
}

void loop() { event_loop->run(); }
