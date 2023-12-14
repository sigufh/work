#pragma once
#include<mysql.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;

typedef struct Student
{
	long student_id;
	string student_name;
	string class_id;
	string student_sex;
	int student_age;
	string student_phone;
	string student_mail;
	int student_grade;
	string student_password;
	bool operator==(const struct Student& W)
	{
		return W.student_id == this->student_id
			&& W.student_name == this->student_name
			&& W.class_id == this->class_id
			&& W.student_sex == this->student_sex
			&& W.student_age == this->student_age
			&& W.student_phone == this->student_phone
			&& W.student_mail == this->student_mail
			&& W.student_grade == this->student_grade
			&& W.student_password == this->student_password;
	}
}Student;

class StudentManager
{
	StudentManager();
	~StudentManager();
public:
	static StudentManager* GetInstance()
	{
		static StudentManager StudentManager;
		return &StudentManager;
	}
public:
	void reset(Student& stu);
	void showAll();

	bool insert_student(Student& t);
	bool update_student(Student& t);
	bool delete_student(int student_id);
	vector<Student> get_students(string condition = "");
private:
	MYSQL* con;
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* pw = "20050306Xt";
	const char* database_name = "person_manager";
	const int port = 3306;
};

#pragma once
