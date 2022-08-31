#include <Arduino.h>

#include "events/event_loop.h"
#include "logging/logger.h"

events::EventLoop* event_loop;
logging::Logger* logger;

void log() { logger->info("running loop"); }

void setup() {
  Serial.begin(115200);
  logger = new logging::Logger("main");
  event_loop = new events::EventLoop();
  event_loop->createTask(log);
}

void loop() { event_loop->run(); }
