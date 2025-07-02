#include "clock.h"  
#include <iostream>  
using std::ostream;  

clock::clock(int h, int m, int s) {  
	m_hour = h;  
	m_min = m;  
	m_sec = s;  
	up_to();  
}  

clock::~clock(void) {
}  

clock& clock::operator++() {  
	m_sec = m_sec + 1;  
	up_to();  
	return *this;  
}  

clock clock::operator++(int) {  
	clock temp = *this;  
	++(*this);  
	return temp;  
}  

void clock::up_to() {  
	if (m_sec >= 60) {  
		m_min = m_sec / 60 + m_min;  
		m_sec = m_sec % 60;  
	}  
	if (m_min >= 60) {  
		m_hour = m_min / 60 + m_hour;  
		m_min = m_min % 60;  
	}  
	m_hour = m_hour % 24;  
}  

std::ostream& operator<<(std::ostream& out, const clock& c) {  
	out << c.m_hour << ":" << c.m_min << ":" << c.m_sec;  
	return out;  
}
