#ifndef LOGGING_LOGGER_H_
#define LOGGING_LOGGER_H_

#include <Arduino.h>

#define LOG(level, name, message) \
  {                               \
    Serial.print(level);          \
    Serial.print(":");            \
    Serial.print(name);           \
    Serial.print(":");            \
    Serial.println(message);      \
  }

#define LOG_CRITICAL(name, message) \
  { LOG("CRITICAL", name, message) }
#define LOG_ERROR(name, message) \
  { LOG("ERROR", name, message) }
#define LOG_WARNING(name, message) \
  { LOG("WARNING", name, message) }
#define LOG_INFO(name, message) \
  { LOG("INFO", name, message) }
#define LOG_DEBUG(name, message) \
  { LOG("DEBUG", name, message) }

#endif  // LOGGING_LOGGER_H_
