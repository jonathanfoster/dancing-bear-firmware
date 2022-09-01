#include <Arduino.h>

#include "controls/button.h"
#include "events/event_loop.h"
#include "logging/logger.h"

#define BUTTON_PIN 36
#define SERIAL_BAUD 9600

controls::Button* button;
events::EventLoop* event_loop;
logging::Logger* logger;

void checkButtonState() { button->checkState(); }

void logButtonPress() { logger->info("button pressed"); }

void setup() {
  Serial.begin(SERIAL_BAUD);
  logger = new logging::Logger("main");

  button = new controls::Button(BUTTON_PIN);
  button->onPress(logButtonPress);

  event_loop = new events::EventLoop();
  event_loop->createTask(checkButtonState);

  logger->info("application started");
}

void loop() { event_loop->run(); }
