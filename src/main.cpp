#include <Arduino.h>

#include "controls/button.h"
#include "events/event_loop.h"
#include "logging/logger.h"

controls::Button* button;
events::EventLoop* event_loop;
logging::Logger* logger;

void checkButtonState() {
  logger->info("checking button state");
  button->checkState();
}

void logButtonPress() { logger->info("button press"); }

void logLoopRun() { logger->info("running event loop"); }

void setup() {
  Serial.begin(115200);
  button = new controls::Button(12);
  button->onPress(logButtonPress);
  logger = new logging::Logger("main");
  event_loop = new events::EventLoop();
  event_loop->createTask(logLoopRun);
  event_loop->createTask(checkButtonState);
}

void loop() { event_loop->run(); }
