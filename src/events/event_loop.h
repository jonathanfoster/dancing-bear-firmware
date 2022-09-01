#ifndef EVENTS_EVENT_LOOP_H_
#define EVENTS_EVENT_LOOP_H_

#include <Arduino.h>
#include <LinkedList.h>

#include "events/task.h"

namespace events {

class EventLoop {
 public:
  EventLoop();
  Task* createTask(void (*f)());
  void run();
  void stop();

 private:
  bool _is_stopped = false;
  LinkedList<Task*>* _tasks;
};

}  // namespace events

#endif  // EVENTS_EVENT_LOOP_H_
