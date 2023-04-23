#include "motor.h"

//Public methods

Mot::Mot(int type, int pin_step, int pin_dir){
	//Constructor
	_type = type;
	_period = 1500;
	_pin_step = pin_step;
	_pin_dir = pin_dir;
	_timer_3 = 0;
	pinMode(_pin_step, OUTPUT);
	pinMode(_pin_dir, OUTPUT);
}

void Mot::drive(int pulses) {
	switch (_type) {
		case STEPMOT18DEG:
			_stepmot18deg(pulses);
			break;
  }
}

void Mot::_stepmot18deg(int pulses) {
	_action(pulses);
}

void Mot::_action(int pulses){
	int copy_period = _period;
	int copy_pulses = pulses;
	bool state_pin_step = LOW;
	while(pulses){
		if(micros()-_timer_3>=copy_period){
			_timer_3 = micros();
			pulses--;
			digitalWrite(_pin_step, HIGH);
			digitalWrite(_pin_step, LOW);
		}
	}
}
