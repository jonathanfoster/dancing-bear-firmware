#include "events/event_loop.h"

namespace events {

EventLoop::EventLoop() {}

Task* EventLoop::createTask(void (*func)()) {
  if (this->_task_index > this->_task_max) {
    return NULL;
  }

  Task* task = new Task(func);
  this->_tasks[_task_index] = new Task(func);
  this->_task_index++;

  return task;
}

void EventLoop::run() {
  if (this->_is_stopped) {
    return;
  }

  for (size_t i = 0; i < this->_task_index; i++) {
    this->_tasks[i]->run();
  }
}

void EventLoop::stop() { this->_is_stopped = true; }

}  // namespace events
