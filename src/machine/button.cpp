#include "machine/button.h"

#include <Arduino.h>

namespace machine {

Button::Button(uint8_t id) { this->init(id, HIGH); }

Button::Button(uint8_t id, uint8_t pull) { this->init(id, pull); }

Button::~Button() {
  if (this->_check_value_task_handle) {
    vTaskDelete(this->_check_value_task_handle);
  }
}

int Button::debounce() { return this->_pin->debounce(); }

void Button::debounce(int new_value) { this->_pin->debounce(new_value); }

bool Button::checkValue() {
  bool value_changed = this->_pin->checkValue();

  if (value_changed) {
    if (this->_pin->value() == this->_pin->pull()) {
      if (this->_press_handler) {
        this->_press_handler(this);
      }
    }
  }

  return value_changed;
}

void Button::onPress(void (*handler)(Button*)) {
  this->_press_handler = handler;
}

void Button::init(uint8_t id, uint8_t pull) {
  this->_pin = new Pin(id, INPUT, pull);

  char task_name_format[] = "Button %d Check Value";
  char task_name_arg = this->_pin->id();
  int task_name_size = snprintf(NULL, 0, task_name_format, task_name_arg) + 1;
  char task_name[task_name_size];
  snprintf(task_name, 0, task_name_format, task_name_arg);

  xTaskCreate(this->checkValueTask, task_name, configMINIMAL_STACK_SIZE * 1.5,
              this, 1, &this->_check_value_task_handle);
}

void Button::checkValueTask(void* parameter) {
  Button* button = (Button*)parameter;

  for (;;) {
    button->checkValue();
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

}  // namespace machine
