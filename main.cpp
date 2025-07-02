#if 1
#include <iostream>
#include "String.h"
#include "airCondition.h"
#include "fraction.h"
#include "clock.h"
#include "test.h"
#include "virtual.h"
#include "lambda.h"
using std::cout;
using std::endl;
int main(int argc , char **argv){
	return 0;
}
#else
#include <iostream>
using namespace std;
class I{
public:
	virtual void show(){
		cout << "11"<<endl;
	}
	virtual void show2(){
		cout << "11"<<endl;
	}
};
class A :public I{
public:
	virtual void show(){
		cout << "22"<<endl;
	}
};
int main(){
	A a;
	A *ptr = &a;
	void (**p) () =  (void(**)())(*((void **)ptr));
	(p[1])();
	getchar();
}
#endif