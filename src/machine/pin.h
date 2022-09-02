#ifndef MACHINE_PIN_H_
#define MACHINE_PIN_H_

#include <Arduino.h>

namespace machine {

class Pin {
 public:
  Pin(uint8_t id);
  Pin(uint8_t id, uint8_t mode);
  Pin(uint8_t id, uint8_t mode, uint8_t pull);

  void init(uint8_t mode);
  void init(uint8_t mode, uint8_t pull);

  int debounce();
  void debounce(int new_value);
  uint8_t mode();
  void mode(uint8_t new_value);
  uint8_t pull();
  void pull(uint8_t new_value);
  uint8_t value();
  void value(uint8_t new_value);

  void on();
  void off();
  void toggle();

  void low();
  void high();

  bool checkValue();
  uint8_t readValue();
  void onChange(void (*handler)(Pin*));

 private:
  void (*_change_handler)(Pin*) = NULL;
  int _debounce = 20;
  unsigned long _last_debounce = 0;
  uint8_t _id = 0;
  uint8_t _mode = LOW;
  uint8_t _pull = LOW;
  uint8_t _value = 0;
  uint8_t _last_value = 0;
};

}  // namespace machine

#endif  // MACHINE_PIN_H_
