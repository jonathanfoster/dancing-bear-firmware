#include "events/event_loop.h"

namespace events {

EventLoop::EventLoop() {}

Task* EventLoop::createTask(void (*func)()) {
  if (_task_index > _task_max) {
    return nullptr;
  }

  Task* task = new Task(func);
  _tasks[_task_index] = new Task(func);
  _task_index++;

  return task;
}

void EventLoop::run() {
  for (size_t i = 0; i < _task_index; i++) {
    _tasks[i]->run();
  }
}

}  // namespace events
