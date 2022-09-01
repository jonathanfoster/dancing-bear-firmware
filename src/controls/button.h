#ifndef CONTROLS_BUTTON_H_
#define CONTROLS_BUTTON_H_

#include <Arduino.h>

namespace controls {

class Button {
 public:
  Button(uint8_t pin);
  Button(uint8_t pin, int default_pin_state);
  void checkState();
  unsigned long debounce();
  void debounce(unsigned long value);
  void onPress(void (*handler)());

 private:
  bool checkIsPressed();
  void setup();

  unsigned long _debounce = 50;
  unsigned long _last_debounce = 0;
  bool _is_pressed = false;
  bool _last_is_pressed = false;
  uint8_t _pin;
  int _default_pin_state = HIGH;
  void (*_press_handler)();
};

}  // namespace controls

#endif  // CONTROLS_BUTTON_H_
