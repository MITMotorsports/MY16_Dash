#ifndef RTD_HANDLER_H
#define RTD_HANDLER_H

#include <Debouncer.h>
#include <PciManager.h>

#include "Can_Controller.h"
#include "Rtd_Controller.h"
#include "Led_Controller.h"

#include "Can_Ids.h"
#include "Pins.h"

class Rtd_Handler {
  public:
    Rtd_Handler();
    enum Motor {RightMotor, LeftMotor, MOTORS_LENGTH};
    void begin();
    void handleMessage(Frame& message);
  private:
    int16_t speeds[MOTORS_LENGTH];
    void processVcuMessage(Frame& message);
    void processSpeedMessage(Frame& message);
    void processSocMessage(Frame& message);
    void processInsaneModeMessage(Frame& message);
    int16_t averageSpeed(Frame& message, int16_t motor_speed);
};

// Have to have a bunch of non-member functions cause reasons
void sendEnableRequest();
void sendDisableRequest();
bool sendEnableRequestWrapper(Task*);
void pressRtdButton();
void releaseRtdButton(unsigned long);

#endif // RTD_HANDLER_H
