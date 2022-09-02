#ifndef AUDIO_NOTE_H_
#define AUDIO_NOTE_H_

namespace audio {

struct Note {
  Note(int frequency, int duration)
      : frequency(frequency), duration(duration) {}
  int frequency;
  int duration;
};

}  // namespace audio

#endif  // AUDIO_NOTE_H_
