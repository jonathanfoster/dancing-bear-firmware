#ifndef CONTROLS_BUTTON_H_
#define CONTROLS_BUTTON_H_

#include <Arduino.h>

namespace controls {

class Button {
 public:
  Button(uint8_t pin);
  void checkState();
  void onPress(void (*handler)());

 private:
  unsigned long _debounce_delay = 10;
  unsigned long _last_debounce_time = 0;
  int _state = LOW;
  int _last_state = LOW;
  uint8_t _pin;
  void (*_press_handler)();
};

}  // namespace controls

#endif  // CONTROLS_BUTTON_H_
