#include "logger.h"

#include <Arduino.h>
#include <stdio.h>

namespace logging {

Logger::Logger(const char* name) { _name = name; }

Logger::Logger(const char* name, LogLevel level) {
  _level = level;
  _name = name;
}

void Logger::setLevel(LogLevel level) { _level = level; }

void Logger::critical(const char* message) { log(LogLevel::Critical, message); }

void Logger::error(const char* message) { log(LogLevel::Error, message); }

void Logger::warning(const char* message) { log(LogLevel::Warning, message); }

void Logger::info(const char* message) { log(LogLevel::Info, message); }

void Logger::debug(const char* message) { log(LogLevel::Debug, message); }

void Logger::log(LogLevel level, const char* message) {
  if (!isEnabledFor(level)) {
    return;
  }

  const char* level_name = getLevelName(level);
  size_t len = strlen(level_name) + strlen(_name) + strlen(message);
  char str[len + 3];  // 2 separators plus \0
  sprintf(str, "%s:%s:%s", level_name, _name, message);
  Serial.println(str);
}

bool Logger::isEnabledFor(LogLevel level) { return level >= _level; }

const char* Logger::getLevelName(LogLevel level) {
  switch (level) {
    case Critical:
      return "CRITICAL";
    case Error:
      return "ERROR";
    case Warning:
      return "WARNING";
    case Info:
      return "INFO";
    case Debug:
      return "DEBUG";
    case NotSet:
      return "NOTSET";
    default:
      return "";
  }
}

}  // namespace logging
