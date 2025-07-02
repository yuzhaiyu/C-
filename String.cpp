#include "String.h"
#include <cstring>
using std::cout;
String::String(){
	this->m_data = new char[1];
	this->m_data = 0;
}
String::String(const char *s){
	int count = strlen(s) + 1;
	this->m_data = new char[count];
	memcpy(this->m_data , s , count);
}
String::String(const String &s){
	int count = strlen(s.m_data) + 1;
	this->m_data = new char[count];
	memcpy(this->m_data , s.m_data , count);
}
String::String(String &&s)noexcept {
	this->m_data = s.m_data;
	s.m_data = nullptr;
}
String::~String(){
	delete [] m_data;
}
String &String::operator=(const String &s){
	int count = strlen(s.m_data) + 1;
	delete [] m_data;
	this->m_data = new char[count];
	memcpy(this->m_data , s.m_data , count);
	return *this;
}
bool String::operator==(const String &s) const {
	return strcmp(this->m_data,s.m_data) == 0;
}
String String::operator+(const String &s)const{
	int length1 = strlen(this->m_data);
	int length2 = strlen(s.m_data);
	int count = length1 + length2 + 1;
	char *arr = new char[count];
	memcpy(arr,this->m_data,length1);
	memcpy(arr+length1,s.m_data,length2 + 1);
	String temp(arr);
	delete [] arr;
	return temp;
}
String operator+(const String &s1,const String &s){
	int length1 = strlen(s1.m_data);
	int length2 = strlen(s.m_data);
	int count = length1 + length2 + 1;
	char *arr = new char[count];
	memcpy(arr,s1.m_data,length1);
	memcpy(arr+length1,s.m_data,length2 + 1);
	String temp(arr);
	delete [] arr;
	return temp;
}

char String::operator[](const int i)const{
	int count = strlen(this->m_data);
	if(i > count){
		cout << "out of index";
		return '\0';
	}
	return *(this->m_data+i);
}
ostream &operator<<(ostream &out,const String &s){
	out << s.m_data;
	return out;
}

int String::get_length(){
	return strlen(this->m_data);
}
char *String::get_str(){
	return this->m_data;
}