#include "melody.h"

#include "logging/logger.h"

namespace audio {

Melody::Melody(unsigned int notes[], int notes_length) {
  this->init(notes, notes_length, 60);
}

Melody::Melody(unsigned int notes[], int notes_length, int tempo) {
  this->init(notes, notes_length, tempo);
}

Note Melody::get(int index) {
  int frequency_index = this->frequencyIndex(index);
  int frequency = this->_notes[frequency_index];

  int divider_index = this->dividerIndex(index);
  int divider = this->_notes[divider_index];
  int duration = this->duration(divider);

  return Note(frequency, duration);
}

int Melody::length() { return this->_notes_length / 2; }

int Melody::duration(int divider) {
  if (divider > 0) {
    return this->_whole_note_duration / divider;
  } else if (divider < 0) {
    return this->_whole_note_duration / abs(divider) * 1.5;
  } else {
    return 0;
  }
}

int Melody::frequencyIndex(int note_index) {
  if (note_index > 0) {
    return note_index * 2;
  } else {
    return 0;
  }
}

int Melody::dividerIndex(int note_index) {
  return this->frequencyIndex(note_index) + 1;
}

void Melody::init(unsigned int *notes, int notes_length, int tempo) {
  this->_notes = notes;
  this->_notes_length = notes_length;
  this->_whole_note_duration = (60000 * 4) / tempo;
}

}  // namespace audio
