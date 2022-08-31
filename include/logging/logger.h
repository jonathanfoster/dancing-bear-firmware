#ifndef LOGGING_LOGGER_H_
#define LOGGING_LOGGER_H_

#include <Arduino.h>

namespace logging {

enum LogLevel {
  Critical = 50,
  Error = 40,
  Warning = 30,
  Info = 20,
  Debug = 10,
  NotSet = 0
};

class Logger {
 public:
  Logger(const char* name);
  Logger(const char* name, LogLevel level);

  void setLevel(LogLevel level);

  void critical(const char* message);
  void error(const char* message);
  void warning(const char* message);
  void info(const char* message);
  void debug(const char* message);
  void log(LogLevel level, const char* message);

 private:
  LogLevel _level = NotSet;
  const char* _name = "";

  bool isEnabledFor(LogLevel level);
  static const char* getLevelName(LogLevel level);
};

}  // namespace logging

#endif  // LOGGING_LOGGER_H_
