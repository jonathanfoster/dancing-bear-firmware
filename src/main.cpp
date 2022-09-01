#include <Arduino.h>

#include "controls/button.h"
#include "events/event_loop.h"
#include "logging/logger.h"

controls::Button* button;
events::EventLoop* event_loop;
logging::Logger* logger;

void checkButtonState() { button->checkState(); }

void logButtonPress() { logger->info("button pressed"); }

void setup() {
  Serial.begin(9600);
  logger = new logging::Logger("main");

  button = new controls::Button(36);
  button->onPress(logButtonPress);

  event_loop = new events::EventLoop();
  event_loop->createTask(checkButtonState);
}

void loop() { event_loop->run(); }
