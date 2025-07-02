#include "lambda.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
// lambda 表达式  匿名函数
// [captrue_method](args...) opt -> return_type {}
void lambda_test() {
	int a = 0, b = 1;
	string s1 = "hello";
	string s2 = s1 + " you";
	auto fp = [&, b]() -> int {
		return a + b;
	};
	[&] ()-> void {
		s2.swap(s1);
		s2 = s2 + s1;
	}();
	cout << s2 << endl;
}