#include "events/task.h"

namespace events {

Task::Task(void (*func)()) { _func = func; }

void Task::cancel() { _is_cancelled = true; }

void Task::run() {
  if (!_is_cancelled) {
    _func();
  }
}

}  // namespace events
