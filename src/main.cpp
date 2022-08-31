#include <Arduino.h>

#include "logger.h"

logging::Logger* logger;

void setup() {
  Serial.begin(115200);
  logger = new logging::Logger("main");
}

void loop() { logger->info("running loop"); }
