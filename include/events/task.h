#ifndef EVENTS_TASK_H_
#define EVENTS_TASK_H_

class Task {
 public:
  Task(void (*func)());
  void cancel();
  void run();

 private:
  bool _cancelled = false;
  void (*_func)();
};

#endif  // EVENTS_TASK_H_
