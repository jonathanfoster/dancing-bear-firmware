#ifndef EVENTS_EVENT_LOOP_H_
#define EVENTS_EVENT_LOOP_H_

#include <Arduino.h>

#include "events/task.h"

namespace events {

class EventLoop {
 public:
  EventLoop();
  Task* createTask(void (*f)());
  void run();

 private:
  int32_t _task_max = 100;
  int32_t _task_index = 0;
  Task* _tasks[100];
};

}  // namespace events

#endif  // EVENTS_EVENT_LOOP_H_
