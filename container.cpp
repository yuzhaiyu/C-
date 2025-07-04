#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include "fraction.h"
#include "container.h"
using std::vector;
using std::cout;
using std::endl;
using std::sort;
using std::map;
using std::string;
using std::multimap;
using std::to_string;
using std::pair;
using std::make_pair;
using std::list;
template<class T> void vector_show(vector<T> &v);
template<class T1, class T2> void map_show(map<T1, T2>& m);
void vector_test(void);
void map_test(void);
void list_test(void);

void container_test(void) {
	vector_test();
	//map_test();
	//list_test();
}
void list_test(void) {
	list<Fraction> li;
	li.push_back(Fraction(1, 2));
	li.push_back(Fraction(3, 4));
	li.push_back(Fraction(0, 6));
	li.push_front(Fraction(5, 8));
	li.sort();
	list<Fraction>::iterator it = li.begin();
	while (it != li.end()) {
		it->show();
		it++;
	}
}
void map_test(void) {
	map<string, Fraction> m;
	for (int i = 0; i < 10; i++) {	
		//m.insert(pair<string, Fraction>(string(to_string(i)), Fraction(i + 1, i + 2)));
		m[string(to_string(i) + ":")] = Fraction(i + 1, i + 2);
		//m.insert(make_pair(string(to_string(i) + ":"), Fraction(i + 1, i + 2)));
		//m.insert(map<string, Fraction>::value_type(string(to_string(i) + ":"), Fraction(i + 1, i + 2)));
	}
	map<string, Fraction>::iterator it = m.find("1:");
	cout << it->first << ":";
	it->second.show();
	m.erase(it);
	map_show<string, Fraction>(m);
}
template<class T1, class T2> void map_show(map < T1, T2>& m){
	typename map<T1, T2>::const_iterator it = m.begin();
	while (it != m.end()) {
		cout << it->first << ":";
		it->second.show();
		++it;
	}
	cout << "=========================" << endl;
}
void vector_test(void) {
	vector<Fraction> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(Fraction(i + 1, i + 2));
	}
	vector<Fraction>::iterator it = v.begin();
	it = v.insert(it, Fraction(33, 34));
	vector_show<Fraction>(v);
	it = v.erase(it + 3, it + 8);
	v.assign(v.begin(), v.end() - 1);
	sort(v.begin(), v.end());
	vector_show<Fraction>(v);
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;
	Fraction f1 = v[2];
	f1.show();
}
template<class T>
void vector_show(vector<T> &v) {
	typename vector<T>::const_iterator it = v.begin();
	while (it != v.end()) {
		it->show();
		++it;
	}
	cout << "========================="<<endl;
}