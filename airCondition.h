#ifndef AIRCONDITION_H
#define AIRCONDITION_H
#include <iostream>
#include <cstring>
class airCondition{
public:
	airCondition(const char *,const char *,const int,const int);
	virtual ~airCondition();

	void turn_switch();
	void up_tmpt(int);
	void down_tmpt(int);
	void show_stat();

	char *get_brand(){
		return this->brand;
	}
	char *get_color(){
		return this->color;
	}
	int get_power(){
		return this->power;
	}
	bool get_switch_status(){
		return this->switch_status;
	}
	int get_temperature(){
		return this->temperature;
	}
private:
	char brand[10];
	char color[10];
	int power;
	bool switch_status;
	int temperature;
};
#endif

