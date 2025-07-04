#pragma once
#include <string>
#include <iostream>
#include <list>
using std::cout;
using std::endl;	
using std::ostream;
using std::string;
using std::list;
class Person {
public:
	Person(string name , int age , int height);
	Person(const Person& o);
	virtual ~Person();
	Person& operator=(const Person& o);
	virtual void showInfo() const;
	const string& name() const;
	void setName(const string name);
	const int age() const;
	void setAge(const int age);
	const int& height() const;
	void setHeight(const int height);
private:
	int m_age;
	int m_height;
	string m_name;
};
class Student  : public Person  {
public:
	Student(string sid, string name, int age, int height);
	~Student();
	virtual void showInfo() const override;
	Student& operator=(const Student& o);
	friend ostream& operator<<(ostream& os, const Student& s);
	bool compareSid(const string sid)const;
	void setSid(const string sid);
	const string& sid() const;
private:
	string m_sid;
};
class Teacher : public Person {
public:
	Teacher(string tid, string name, int age, int height);
	~Teacher();
	virtual void showInfo() const override;
	Teacher& operator=(const Teacher& o);
	friend ostream& operator<<(ostream& os, const Teacher& t);
	bool operator==(const Teacher& o) const;
	void setTid(const string tid);
	const string& tid() const;
private:
	string m_tid;
};
class College {
public:
	College(string cid, string cname);
	~College();
	bool compareCid(const string cid) const;
	void setCid(const string cid);
	bool operator==(const College& c)const;
	const string& cid() const;
	void setCname(const string cname);
	const string& cname() const;

	void studentListAdd(const Student& s);
	void studentListDel(const string sid);
	Student* studentInfo(const string sid) const;
	void showStudentList() const;

	void teacherListAdd(const Teacher& t);
	void teacherListDel(const string tid);
	Teacher* teacherInfo(const string tid) const;
	void showTeacherList() const;
private:
	string m_cid;
	string m_cname;
	list<Student> s_list;
	list<Teacher> t_list;
};
class University {
public:
	//����ģʽ
	static University* getUniversity(string uid, string uname, string uaddr) {
		static University university(uid, uname, uaddr);
		return &university;
	}
	~University();
	void setUid(const string uid);
	const string& uid() const;
	void setUname(const string uname);
	const string& uname() const;
	void setUaddr(const string uaddr);
	const string& uaddr() const;

	void collegeListAdd(const College& c);
	void collegeListDel(const string cid);
	void showAllInfo() const;
	void showCollegeList() const;
	College* collegeInfo(const string cid) const;
	void collegeListRemove(College& c);

	//����ѧԺ��Ϣ����ʾ
	void showCollegeInfo(const string cid) const;
	//�޸�ָ��ѧԺ��Ϣ
	void alterCollegeInfo(const string cid);
	//����ѧ��
	Student* findStudent(const string sid);
	//�޸�ѧ��
	void alterStudent(const string sid);
	//���ѧ��
	void addStudent(const string sid);
	//ɾ��ѧ��
	void delStudent(const string sid);
	//���ҽ�ʦ
	Teacher* findTeacher(const string tid);
	//�޸Ľ�ʦ
	void alterTeacher(const string tid);
	//��ӽ�ʦ
	void addTeacher(const string tid);
	//ɾ����ʦ
	void delTeacher(const string tid);
private:
	string m_uid;
	string m_uname;
	string m_uaddr;
	list<College> c_list;
	University(string uid, string uname, string uaddr);
};
void test_student_sys();