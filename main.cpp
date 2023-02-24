/* Start Kit SAé BUT1-S2
    Micro Nucleo L432KC
    Mbed 5.15
    Fev-2023
    A.De Carvalho
 */

#include "lib/ComDuj10.h"
#include "mbed.h"

// prototypes
void setup();
void loop();
void serialHandler();

// Objects
RawSerial pc(SERIAL_TX, SERIAL_RX);
//
DigitalOut ledInternal(D13);
DigitalOut ledExternal(D9);
DigitalOut comBtnK(D1);
DigitalIn btnK(D2);
//
AnalogIn potentiometre(A0);
AnalogIn P0(A6);
AnalogIn P1(A5);
AnalogIn Vs(A2);
//
AnalogOut outVr(A4);
//
ComDuj10 comDuj10(&pc);

// global
float TensionVcom = 0.5864;
//
//********************
void serialHandler() {
  // TODO
}
//*****************************
void setup() {
  pc.baud(115200);
  pc.attach(&serialHandler, Serial::RxIrq);
  // TODO
}
//******************************
void loop() {
  // TODO
  thread_sleep_for(500);
}

//*****************************
int main() {
  setup();

  while (true) {
    loop();
  }
  return 0;
}
// end prog