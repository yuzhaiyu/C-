#include "student_sys.h"
using std::to_string;
using std::cin;
Person::Person(string name, int age, int height)
	: m_name(name), m_age(age), m_height(height) {
}
Person::Person(const Person& o)
	: m_name(o.m_name), m_age(o.m_age), m_height(o.m_height) {
}
Person::~Person() {
}
Person& Person::operator=(const Person& o) {
	if (this != &o) {
		m_name = o.m_name;
		m_age = o.m_age;
		m_height = o.m_height;
	}
	return *this;
}
void Person::showInfo() const {
	cout << "Name: " << m_name << ", Age: " << m_age << ", Height: " << m_height << endl;
}
const string& Person::name() const {
	return m_name;
}
void Person::setName(const string name) {
	m_name = name;
}
const int Person::age() const {
	return m_age;
}
void Person::setAge(const int age) {
	m_age = age;
}
const int& Person::height() const {
	return m_height;
}
void Person::setHeight(const int height) {
	m_height = height;
}

Student::Student(string sid, string name, int age, int height)
	: Person(name, age, height), m_sid(sid) {
}
Student::~Student() {
}
Student& Student::operator=(const Student& o) {
	if (this != &o) {
		Person::operator=(o);
		m_sid = o.m_sid;
	}
	return *this;
}
void Student::showInfo() const {
	Person::showInfo();
	cout << "Student ID: " << m_sid << endl;
}
ostream& operator<<(ostream& os, const Student& s) {
	os << "Student ID: " << s.m_sid << ", Name: " << s.name() << ", Age: " << s.age() << ", Height: " << s.height();
	return os;
}
bool Student::compareSid(const string sid) const {
	return m_sid == sid;
}
void Student::setSid(const string sid) {
	m_sid = sid;
}
const string& Student::sid() const {
	return m_sid;
}

Teacher::Teacher(string tid, string name, int age, int height)
	: Person(name, age, height), m_tid(tid) {
}
Teacher::~Teacher() {
}
Teacher& Teacher::operator=(const Teacher& o) {
	if (this != &o) {
		Person::operator=(o);
		m_tid = o.m_tid;
	}
	return *this;
}
void Teacher::showInfo() const {
	Person::showInfo();
	cout << "Teacher ID: " << m_tid << endl;
}
ostream& operator<<(ostream& os, const Teacher& t) {
	os << "Teacher ID: " << t.m_tid << ", Name: " << t.name() << ", Age: " << t.age() << ", Height: " << t.height();
	return os;
}
bool Teacher::operator==(const Teacher& o) const {
	return m_tid == o.m_tid && name() == o.name() && age() == o.age() && height() == o.height();
}
void Teacher::setTid(const string tid) {
	m_tid = tid;
}
const string& Teacher::tid() const {
	return m_tid;
}

College::College(string cid, string cname)
	: m_cid(cid), m_cname(cname) {
}
College::~College() {
}
bool College::compareCid(const string cid) const {
	return m_cid == cid;
}
void College::setCid(const string cid) {
	m_cid = cid;
}
const string& College::cid() const {
	return m_cid;
}
const string& College::cname() const {
	return m_cname;
}
void College::setCname(const string cname) {
	m_cname = cname;
}
void College::studentListAdd(const Student& s) {
	s_list.push_back(s);
}
void College::studentListDel(const string sid) {
	list<Student>::iterator it = s_list.begin();
	while (it != s_list.end()) {
		if (it->compareSid(sid)) {
			s_list.erase(it);
			return;
		}
		++it;
	}
}
Student* College::studentInfo(const string sid) const {
	list<Student>::const_iterator it = s_list.begin();
	while(it != s_list.end()) {
		if (it->compareSid(sid)) {
			return (Student*) & (*it);
		}
		++it;
	}
	return nullptr;
}
void College::showStudentList() const {
	list<Student>::const_iterator it = s_list.begin();
	cout << "Student List:=================================" << endl;
	while (it != s_list.end()) {
		cout << *it << endl;
		++it;
	}
}
void College::teacherListAdd(const Teacher& t) {
	t_list.push_back(t);
}
void College::teacherListDel(const string tid) {
	list<Teacher>::iterator it = t_list.begin();
	while (it != t_list.end()) {
		if (it->tid() == tid) {
			t_list.erase(it);
			return;
		}
		++it;
	}
}
Teacher* College::teacherInfo(const string tid)const {
	list<Teacher>::const_iterator it = t_list.begin();
	while (it != t_list.end()) {
		if (it->tid() == tid) {
			return (Teacher *)&(*it);
		}
		++it;
	}
	return nullptr;
}
void College::showTeacherList() const {
	list<Teacher>::const_iterator it = t_list.begin();
	cout << "Teacher List:=================================" << endl;
	while (it != t_list.end()) {
		cout << *it << endl;
		++it;
	}
}
bool College::operator==(const College& c)const {
	return m_cid == c.m_cid;
}
University::University(string uid, string uname, string uaddr){
	m_uid = uid;
	m_uaddr = uaddr;
	m_uname = uname;
}
University::~University() {
}
void University::setUid(const string uid) {
	m_uid = uid;
}
const string& University::uid() const {
	return m_uid;
}
void University::setUname(const string uname) {
	m_uname = uname;
}
const string& University::uname() const {
	return m_uname;
}
void University::setUaddr(const string uaddr) {
	m_uaddr = uaddr;
}
const string& University::uaddr() const {
	return m_uaddr;
}
void University::collegeListAdd(const College& c) {
	c_list.push_back(c);
}
void University::collegeListDel(const string cid) {
	list<College>::iterator it = c_list.begin();
	while (it != c_list.end()) {
		if (it->compareCid(cid)) {
			c_list.erase(it);
			return;
		}
		++it;
	}
}
void University::showAllInfo() const {
	list<College>::const_iterator it = c_list.begin();
	cout << "College List:=================================" << endl;
	while (it != c_list.end()) {
		cout << endl;
		cout << "College ID: " << it->cid() << ", College Name: " << it->cname() << endl;
		it->showStudentList();
		it->showTeacherList();
		++it;
	}
}
void University::showCollegeList() const {
	list<College>::const_iterator it = c_list.begin();
	cout << "College List:=================================" << endl;
	while (it != c_list.end()) {
		cout << endl;
		cout << "College ID: " << it->cid() << ", College Name: " << it->cname() << endl;
		++it;
	}
}
College* University::collegeInfo(const string cid) const {
	list<College>::const_iterator it = c_list.begin();
	while (it != c_list.end()) {
		if (it->compareCid(cid)) {
			return (College*)&(*it);
		}
		++it;
	}
	return nullptr;
}
void University::collegeListRemove(College& c) {
	this->c_list.remove(c);
}

//查找学院信息并显示
void University::showCollegeInfo(const string cid) const {
	College* co = collegeInfo(cid);
	if (!co) {
		cout <<"未找到ID为"<<cid<<"的学院"<< endl;
		return;
	}
	cout << "College ID: " << co->cid() << ", College Name: " << co->cname() << endl;
	co->showStudentList();
	co->showTeacherList();
	return;
}
//修改学院信息
void University::alterCollegeInfo(const string cid) {
	College* co = collegeInfo(cid);
	if (!co) {
		cout << "未找到ID为" << cid << "的学院" << endl;
		return;
	}
	cout << "College ID: " << co->cid() << ", College Name: " << co->cname() << endl;
	cout << "请输入要修改后的ID" << endl;
	string c_cid;
	cin >> c_cid;
	cout << "请输入要修改后的名称" << endl;
	string c_name;
	cin >> c_name;
	co->setCid(c_cid);
	co->setCname(c_name);
	cout << "修改成功" << endl;
	return;
}
//查找学生
Student* University::findStudent(const string sid) {
	list<College>::const_iterator it = c_list.begin();
	int flag = 1;
	Student* s = nullptr;
	while (flag && it != c_list.end()) {
		s = it->studentInfo(sid);
		if (s) {
			flag = 0;
		}
		++it;
	}
	return s;
}
//修改学生
void University::alterStudent(const string sid) {
	Student* s = findStudent(sid);
	if (!s) {
		cout << "未找到ID为" << sid << "的学生" << endl;
		return;
	}
	int age;
	int height;
	string name;
	string m_sid;
	cout << "请输入要修改后的ID" << endl;
	cin >> m_sid;
	cout << "请输入要修改后的名称" << endl;
	cin >> name;
	cout << "请输入要修改后的身高" << endl;
	cin >> height;
	cout << "请输入要修改后的年龄" << endl;
	cin >> age;
	s->setSid(m_sid);
	s->setAge(age);
	s->setHeight(height);
	s->setName(name);
	cout << "修改成功" << endl;

}
//添加学生
void University::addStudent(const string cid) {
	College* co = collegeInfo(cid);
	if (!co) {
		cout << "未找到ID为" << cid << "的学院" << endl;
		return;
	}
	int age;
	int height;
	string name;
	string m_sid;
	cout << "请输入要学生的ID" << endl;
	cin >> m_sid;
	cout << "请输入要学生的名称" << endl;
	cin >> name;
	cout << "请输入要学生的年龄" << endl;
	cin >> age;
	cout << "请输入要学生的身高" << endl;
	cin >> height;
	Student s1(m_sid, name, age, height);
	co->studentListAdd(s1);
	cout << "添加成功" << endl;
}
//删除学生
void University::delStudent(const string sid) {
	list<College>::iterator it = c_list.begin();
	int flag = 1;
	Student* s = nullptr;
	while (flag && it != c_list.end()) {
		s = it->studentInfo(sid);
		if (s) {
			flag = 0;
			it->studentListDel(sid);
			cout << "删除成功" << endl;
			return;
		}
		++it;
	}
	cout << "未找到ID为" << sid << "的学生" << endl;
	return;
}
//查找教师
Teacher* University::findTeacher(const string tid) {
	list<College>::const_iterator it = c_list.begin();
	int flag = 1;
	Teacher* t = nullptr;
	while (flag && it != c_list.end()) {
		t = it->teacherInfo(tid);
		if (t) {
			flag = 0;
		}
		++it;
	}
	return t;
}
//修改教师
void University::alterTeacher(const string tid) {
	Teacher* t = findTeacher(tid);
	if (!t) {
		cout << "未找到ID为" << tid << "的教师" << endl;
		return;
	}
	int age;
	int height;
	string name;
	string m_tid;
	cout << "请输入要修改后的ID" << endl;
	cin >> m_tid;
	cout << "请输入要修改后的名称" << endl;
	cin >> name;
	cout << "请输入要修改后的身高" << endl;
	cin >> height;
	cout << "请输入要修改后的年龄" << endl;
	cin >> age;
	t->setTid(m_tid);
	t->setAge(age);
	t->setHeight(height);
	t->setName(name);
	cout << "修改成功" << endl;

}
//添加教师
void University::addTeacher(const string cid) {
	College* co = collegeInfo(cid);
	if (!co) {
		cout << "未找到ID为" << cid << "的学院" << endl;
		return;
	}
	int age;
	int height;
	string name;
	string m_tid;
	cout << "请输入要教师的ID" << endl;
	cin >> m_tid;
	cout << "请输入要教师的名称" << endl;
	cin >> name;
	cout << "请输入要教师的年龄" << endl;
	cin >> age;
	cout << "请输入要教师的身高" << endl;
	cin >> height;
	Teacher t1(m_tid, name, age, height);
	co->teacherListAdd(t1);
	cout << "添加成功" << endl;
}
//删除教师
void University::delTeacher(const string tid) {
	list<College>::iterator it = c_list.begin();
	int flag = 1;
	Teacher* t = nullptr;
	while (flag && it != c_list.end()) {
		t = it->teacherInfo(tid);
		if (t) {
			flag = 0;
			it->teacherListDel(tid);
			cout << "删除成功" << endl;
			return;
		}
		++it;
	}
	cout << "未找到ID为" << tid << "的教师" << endl;
	return;
}
void init_University(University& sys) {
	College c1("C1001", "计算机学院");
	Student s1("S1001", "张三", 20, 175);
	Student s2("S1002", "李四", 21, 180);
	Teacher t1("T1001", "陈老师", 35, 170);
	Teacher t2("T1002", "刘老师", 40, 165);
	c1.studentListAdd(s1);
	c1.studentListAdd(s2);
	c1.teacherListAdd(t1);
	c1.teacherListAdd(t2);
	College c2("C1002", "电子信息学院");
	Student s3("S1003", "王五", 22, 178);
	Student s4("S1004", "赵六", 19, 172);
	Teacher t3("T1003", "张老师", 38, 168);
	Teacher t4("T1004", "李老师", 45, 175);
	c2.studentListAdd(s3);
	c2.studentListAdd(s4);
	c2.teacherListAdd(t3);
	c2.teacherListAdd(t4);
	sys.collegeListAdd(c1);
	sys.collegeListAdd(c2);
}

void test_student_sys() {
	//University sys("U1001","四川大学","成都市一环路南一段24号");
	University* pt = University::getUniversity("U1001", "四川大学", "成都市一环路南一段24号");
	University sys = *pt;
	init_University(sys);
	int flag = 0;
	while (flag != 15) {
		cout << "=========================================================" << endl;
		cout << "欢迎访问学校管理系统，请选择要进行的操作(输入序号并回车):" << endl;
		cout << "1.显示所有学校信息." << endl;
		cout << "2.学院列表" << endl;
		cout << "3.查找学院信息" << endl;
		cout << "4.修改学院信息" << endl;
		cout << "5.添加学院" << endl;
		cout << "6.删除学院" << endl;
		cout << "7.查找学生信息" << endl;
		cout << "8.修改学生信息" << endl;
		cout << "9.添加学生" << endl;
		cout << "10.删除学生" << endl;
		cout << "11.查找教师信息" << endl;
		cout << "12.修改教师信息" << endl;
		cout << "13.添加教师" << endl;
		cout << "14.删除教师" << endl;
		cout << "15.退出系统" << endl;
		cin >> flag;
		switch (flag) {
		case 1: {
			sys.showAllInfo();
			break;
		}
		case 2: {
			sys.showCollegeList();
			break;
		}
		case 3: {
			cout << "请输入学院id" << endl;
			string cid;
			cin >> cid;
			sys.showCollegeInfo(cid);
			break;
		}
		case 4: {
			cout << "请输入要修改学院的id" << endl; 
			string cid;
			cin >> cid;
			sys.alterCollegeInfo(cid);
			break;
		}
		case 5: {
			string cid;
			string cname;
			cout << "请输入要添加学院的id" << endl;
			cin >> cid;
			cout << "请输入要添加学院的名称" << endl;
			cin >> cname;
			College c1(cid, cname);
			sys.collegeListAdd(c1);
			cout << "添加成功" << endl;
			break;
		}
		case 6: {
			cout << "请输入要删除学院的id" << endl;
			string cid;
			cin >> cid;
			sys.collegeListDel(cid);
			cout << "删除成功" << endl;
			break;
		}
		case 7: {
			cout << "请输入要学生id" << endl;
			string sid;
			cin >> sid;
			Student* s =sys.findStudent(sid);
			if (s) {
				s->showInfo();
			}else {
				cout << "未找到ID为" << sid << "的学生" << endl;
			}
			break;
		}
		case 8: {
			cout << "请输入要修改学生的id" << endl;
			string sid;
			cin >> sid;
			sys.alterStudent(sid);
			break;
		}
		case 9: {
			cout << "请输入要添加学生的学院id" << endl;
			string cid;
			cin >> cid;
			sys.addStudent(cid);
			break;
		}
		case 10: {
			cout << "请输入要删除学生的id" << endl;
			string sid;
			cin >> sid;
			sys.delStudent(sid);
			break;
		}
		case 11: {
			cout << "请输入要教师id" << endl;
			string sid;
			cin >> sid;
			Teacher* t = sys.findTeacher(sid);
			if (t) {
				t->showInfo();
			}
			else {
				cout << "未找到ID为" << sid << "的教师" << endl;
			}
			break;
		}
		case 12: {
			cout << "请输入要修改教师的id" << endl;
			string tid;
			cin >> tid;
			sys.alterTeacher(tid);
			break;
		}
		case 13: {
			cout << "请输入要添加教师的学院id" << endl;
			string tid;
			cin >> tid;
			sys.addTeacher(tid);
			break;
		}
		case 14: {
			cout << "请输入要删除教师的id" << endl;
			string tid;
			cin >> tid;
			sys.delTeacher(tid);
			break;
		}
		default: {
			cout << "无效操作，请重新选择" << endl;
			break;
		}
		}
	}
}