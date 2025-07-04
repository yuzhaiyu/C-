#pragma once
#ifndef VIRTUAL_H
#define VIRTUAL_H
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
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

class I {
public:
	virtual void show() {
		cout << "11" << endl;
	}
	virtual void show2() {
		cout << "11" << endl;
	}
};
class A :public I {
public:
	virtual void show() {
		cout << "22" << endl;
	}
};
#endif // !VIRTUAL_H