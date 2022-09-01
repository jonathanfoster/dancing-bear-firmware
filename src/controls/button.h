#ifndef CONTROLS_BUTTON_H_
#define CONTROLS_BUTTON_H_

#include <Arduino.h>

namespace controls {

class Button {
 public:
  Button(uint8_t pin);
  Button(uint8_t pin, int default_state);
  void checkState();
  unsigned long debounce();
  void debounce(unsigned long value);
  void onPress(void (*handler)());

 private:
  void setup();

  unsigned long _debounce = 50;
  unsigned long _last_debounce = 0;
  int _state = LOW;
  int _last_state = LOW;
  uint8_t _pin;
  int _default_state = HIGH;
  void (*_press_handler)();
};

}  // namespace controls

#endif  // CONTROLS_BUTTON_H_
