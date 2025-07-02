#include "fraction.h"
#include <cstdlib>
using std::cout;
using std::endl;
Fraction::Fraction(){
	numerator = 0;
	denominator = 1;
}
Fraction::Fraction(int a, int b){
	numerator = a;
	denominator = b;
	if(this->denominator == 0){
		cout<<"denominator can not be 0"<<endl;
		exit(1);
	}
	approximation();
}
Fraction::Fraction(const Fraction &f){
	this->numerator = f.numerator;
	this->denominator = f.denominator;
	approximation();
}
Fraction::~Fraction(){}

int Fraction::get_numerator() const{
	return this->numerator;
};
int Fraction::get_denominator() const{
	return this->denominator;
};
void Fraction::set_numerator(int numerator){
	this->numerator = numerator;
};
void Fraction::set_denominator(int denominator){
	this->denominator = denominator;
};

void Fraction::show() const {
	cout << this->numerator << "/" << this->denominator << endl;
}
void Fraction::approximation(){
	int temp = this->numerator>this->denominator?
		this->denominator:this->numerator;
	while(temp >1){
		if(this->numerator%temp==0 && this->denominator%temp==0){
			this->numerator = this->numerator/temp;
			this->denominator = this->denominator/temp;
			break;
		}
		temp--;
	}
}
void Fraction::scores(Fraction &f){
	int temp = this->denominator > f.denominator?
		f.denominator : this->denominator;
	while(temp > 1){
		if(this->denominator%temp ==0 && f.denominator%temp==0){
			break;
		}
		temp--;
	}
	this->denominator = this->denominator * f.denominator / temp;
	this->numerator = this->numerator * f.denominator / temp;
}
Fraction Fraction::operator+(const Fraction &f) const {
	int temp = this->denominator > f.denominator?
		f.denominator : this->denominator;
	while(temp > 1){
		if(this->denominator%temp ==0 && f.denominator%temp==0){
			break;
		}
		temp--;
	}
	int new_denominator = this->denominator * f.denominator / temp;
	int num1 = this->numerator * f.denominator / temp;
	int num2 = f.numerator * this->denominator / temp;
	Fraction c(num1+num2,new_denominator);
	return c;
}

Fraction Fraction::operator-(const Fraction &f) const {
	int temp = this->denominator > f.denominator?
		f.denominator : this->denominator;
	while(temp > 1){
		if(this->denominator%temp ==0 && f.denominator%temp==0){
			break;
		}
		temp--;
	}
	int new_denominator = this->denominator * f.denominator / temp;
	int num1 = this->numerator * f.denominator / temp;
	int num2 = f.numerator * this->denominator / temp;
	Fraction c(num1-num2,new_denominator);
	return c;
}
Fraction Fraction::operator*(const Fraction &f) const {
	int new_denominator = this->denominator * f.denominator;
	int num = this->numerator * f.numerator;
	Fraction c(num,new_denominator);
	return c;
}
Fraction Fraction::operator/(const Fraction &f) const {
	int new_denominator = this->denominator * f.numerator;
	int num = this->numerator * f.denominator;
	Fraction c(num,new_denominator);
	return c;
}
Fraction Fraction::reciprocal() const{
	int new_denominator = this->numerator;
	int num = this->denominator;
	Fraction c(num,new_denominator);
	return c;
}
bool Fraction::operator>(const Fraction &f) const {
	Fraction c(this->numerator,this->denominator);
	Fraction d(f.numerator,f.denominator);
	c.scores(d);
	d.scores(c);
	return c.numerator - d.numerator > 0;
};
bool Fraction::operator<(const Fraction &f) const{
	Fraction c(this->numerator,this->denominator);
	Fraction d(f.numerator,f.denominator);
	c.scores(d);
	d.scores(c);
	return d.numerator - c.numerator > 0;
};