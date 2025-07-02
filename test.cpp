#include "test.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

template<class T1 , class T2> class Dog{
public:
	Dog(T1 &,T2 &);
	void show();
private:
	T1 m_name;
	T2 m_age;
};
template<class T1 , class T2> 
Dog<T1 , T2>::Dog(T1 &t1 , T2 &t2){
	m_name = t1;
	m_age = t2;
}
template<class T1 , class T2>
void Dog<T1,T2>::show(){
	cout << this->m_name << ":" << this->m_age << endl;
}


template<class T1 , class T2> T1 add_func(T1 t1 , T2 t2){
	return t1 + t2;
}
template<class T> void swap(T &t1 , T &t2){
	T t3 = t1;
	t1 = t2;
	t2 = t3;
}
template<> void swap(string &s1 , string &s2){
	s1.swap(s2);
}
template<class T> T add_all(T t1) {
	return t1;
}
template<class T, class ... Args> T add_all(T t1, Args ... args) {
	return t1 + add_all(args...);
}

void test(){
	string c = "wc";
	int i = 12;
	Dog<string ,int> wc(c,i);
	cout << add_all(33.2,20) << endl;
	return;
}

