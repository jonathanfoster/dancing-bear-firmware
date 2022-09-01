#include "events/task.h"

namespace events {

Task::Task(void (*func)()) { this->_func = func; }

void Task::cancel() { this->_is_cancelled = true; }

void Task::run() {
  if (this->_is_cancelled) {
    return;
  }

  if (this->_func) {
    this->_func();
  }
}

}  // namespace events
