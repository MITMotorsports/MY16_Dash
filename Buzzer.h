#ifndef BUZZER_H
#define BUZZER_H

#include <DelayRun.h>

const bool BUZZER_ENABLED = true;

class Buzzer {
  public:
    void begin();
    void trigger(int ms);

  private:
    bool enabled = BUZZER_ENABLED;
};

#endif // BUZZER_H
