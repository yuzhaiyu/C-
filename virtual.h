#pragma once
#ifndef VIRTUAL_H
#define VIRTUAL_H
#include <string>
using std::string;
class Animal {
public:
	Animal(int i = 0) {
		m_age = i;
	}
	virtual ~Animal() {
	}
	virtual void eat() = 0;
private:
	int m_age;
};

class Cat : public Animal {
public:
	Cat(int i, const char* s);
	virtual ~Cat() {
	}
	virtual void eat();
private:
	string m_name;
};
#endif // !VIRTUAL_H