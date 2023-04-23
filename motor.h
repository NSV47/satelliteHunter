#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#define STEPMOT18DEG 0

class Mot {
  public:
	Mot(int type, int pin_step, int pin_dir);
    void drive(int pulses);
	
  private:
	int _type, _period, _pin_step, _pin_dir;
	uint32_t _timer_3, _timer_4;
	
	void _stepmot18deg(int pulses);
	void _action(int pulses);
	
};
#endif