#ifndef AUDIO_MELODY_H
#define AUDIO_MELODY_H

#include <Arduino.h>

#include "audio/note.h"

namespace audio {

class Melody {
 public:
  Melody(unsigned int notes[], int notes_length);
  Melody(unsigned int notes[], int notes_length, int tempo);

  Note get(int index);
  int length();

 private:
  void init(unsigned int notes[], int notes_length, int tempo);

  int duration(int note_type);
  int frequencyIndex(int note_index);
  int dividerIndex(int note_index);

  unsigned int* _notes = NULL;
  int _notes_length = 0;
  int _whole_note_duration = 0;
};

}  // namespace audio

#endif  // AUDIO_MELODY_H
