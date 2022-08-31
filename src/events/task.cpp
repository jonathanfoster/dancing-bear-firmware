#include "events/task.h"

namespace events {

Task::Task(void (*func)()) { _func = func; }

void Task::cancel() { _cancelled = true; }

void Task::run() {
  if (!_cancelled) {
    _func();
  }
}

}  // namespace events
