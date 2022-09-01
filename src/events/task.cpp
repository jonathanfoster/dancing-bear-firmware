#include "events/task.h"

namespace events {

Task::Task(void (*func)()) { _func = func; }

Task::Task(void (*func)()) { this->_func = func; }

void Task::cancel() { this->is_cancelled = true; }

void Task::run() {
  if (this->is_cancelled) {
    return;
  }

  if (this->_func) {
    this->_func();
  }
}

}  // namespace events
