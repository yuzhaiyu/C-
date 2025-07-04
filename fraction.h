#include <iostream>
class Fraction{
public:
	Fraction();
	Fraction(int,int);
	Fraction(const Fraction &);
	virtual ~Fraction();
	void approximation();
	void scores(Fraction &);
	Fraction reciprocal() const;
	Fraction operator+(const Fraction &) const;
	Fraction operator-(const Fraction &) const;
	Fraction operator*(const Fraction &) const;
	Fraction operator/(const Fraction &) const;
	bool operator>(const Fraction &) const;
	bool operator<(const Fraction &) const;
	bool operator==(const Fraction&) const;
	void show() const;
	int get_numerator() const;
	int get_denominator() const;
	void set_numerator(int);
	void set_denominator(int);
private:
	int numerator;
	int denominator;
};