#ifndef EVENTS_TASK_H_
#define EVENTS_TASK_H_

namespace events {

class Task {
 public:
  Task(void (*func)());
  void cancel();
  void run();

 private:
  bool _is_cancelled = false;
  void (*_func)();
};

}  // namespace events

#endif  // EVENTS_TASK_H_
