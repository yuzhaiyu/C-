#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>
using std::ostream;

class String{
public:
	String();
	String(const char *s);
	String(const String &s);
	String(String &&s) noexcept;
	
	virtual ~String();
	
	String &operator=(const String &);
	bool operator==(const String &)const ;
	String operator+(const String &)const ;
	friend String operator+(const String &,const String &);
	char operator[](const int)const;
	friend ostream &operator<<(ostream &out,const String &s);
	
	int get_length();
	char *get_str();
private:
	char *m_data;
};
#endif