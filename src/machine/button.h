#ifndef MACHINE_BUTTON_H_
#define MACHINE_BUTTON_H_

#include <Arduino.h>

#include "machine/pin.h"

namespace machine {

class Button {
 public:
  Button(uint8_t id);
  Button(uint8_t id, uint8_t pull);
  bool checkValue();
  void onPress(void (*handler)(Button*));

 private:
  Pin* _pin = NULL;
  void (*_press_handler)(Button*) = NULL;
};

}  // namespace machine

#endif  // MACHINE_BUTTON_H_
