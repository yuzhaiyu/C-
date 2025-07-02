#include "virtual.h"
#include <iostream>
using std::cout;
using std::endl;
Cat::Cat(int i = 0, const char* s = "lili") : Animal(i){
	m_name = s;
}
void Cat::eat() {
	cout << this->m_name << "is eating" << endl;
}