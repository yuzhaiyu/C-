#ifndef CLOCK_H  
#define CLOCK_H  
#include <iostream>  
using std::ostream;  
class clock{  
public:  
	clock(int h = 0, int m = 0, int s = 0); 
	virtual ~clock(void);  
	clock &operator++();  
	clock operator++(int);  
	friend std::ostream &operator<<(ostream &out,const clock &c);  
private:  
	int m_hour;  
	int m_min;  
	int m_sec;  
	void up_to();  
};  
#endif

