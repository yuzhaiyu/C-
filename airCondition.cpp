#include "airCondition.h"
using std::cout;
using std::endl;
airCondition::airCondition(const char *a,const char *b,int c,int d){
		for(int i = 0 ; i < 10 ; i++){
			this->brand[i] = *(a+i);
			if(*(a+i) == '\0') break;
		}
		for(int i = 0 ; i < 10 ; i++){
			this->color[i] = *(b+i);
			if(*(b+i) == '\0') break;
		}
		this->power = c;
		this->temperature = d;
		this->switch_status = false;
	}


airCondition::~airCondition(void){
}

void airCondition::turn_switch(){
	this->switch_status = !this->switch_status;
}
void airCondition::up_tmpt(int a){
	this->temperature = this->temperature + a;
}
void airCondition::down_tmpt(int a){
	this->temperature = this->temperature - a;
}
void airCondition::show_stat(){
	const char * s = this->switch_status?"开":"关";
	cout << "开关状态:" << s << "," << "温度:" << this->temperature << endl;
}
