#include "events/event_loop.h"

#include <LinkedList.h>

namespace events {

EventLoop::EventLoop() { this->_tasks = new LinkedList<Task*>(); }

Task* EventLoop::createTask(void (*func)()) {
  Task* task = new Task(func);
  this->_tasks->add(task);
  return task;
}

void EventLoop::run() {
  if (this->_is_stopped) {
    return;
  }

  for (int i = 0; i < this->_tasks->size(); i++) {
    this->_tasks->get(i)->run();
  }
}

void EventLoop::stop() { this->_is_stopped = true; }

}  // namespace events
