#ifndef MACHINE_BUTTON_H_
#define MACHINE_BUTTON_H_

#include <Arduino.h>

#include "machine/pin.h"

namespace machine {

class Button {
 public:
  Button(uint8_t id);
  Button(uint8_t id, uint8_t pull);
  ~Button();

  int debounce();
  void debounce(int new_value);
  bool checkValue();
  void onPress(void (*handler)(Button*));

 private:
  void init(uint8_t id, uint8_t pull);
  static void checkValueTask(void* parameter);

  TaskHandle_t _check_value_task_handle = NULL;
  bool _is_pressed = false;
  Pin* _pin = NULL;
  void (*_press_handler)(Button*) = NULL;
};

}  // namespace machine

#endif  // MACHINE_BUTTON_H_
