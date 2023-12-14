#include "insertStu.h"
#include"mainwidget.h"
StudentManager::StudentManager()
{
	con = mysql_init(NULL);
	//设置字符编码
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

	if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
	{
		std::cout << "Failed to conncet" << std::endl;
		exit(1);
	}

}

StudentManager::~StudentManager()
{
	mysql_close(con);
}

bool StudentManager::insert_student(Student& stu)
{
	char sql[1024];
	sprintf(sql, "insert into student (student_id,student_name,class_id,student_sex,student_age,student_phone,student_mail,student_grade,student_password) values('%d','%s','%s','%s','%d','%s','%s','%d','%s')",
		stu.student_id, stu.student_name.c_str(), stu.class_id.c_str(),
		stu.student_sex.c_str(), stu.student_age, stu.student_phone.c_str(),
		stu.student_mail.c_str(), stu.student_grade, stu.student_password.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to insert data : Error:%s\n", mysql_error(con));
		return false;
	}

	return true;
}

bool StudentManager::update_student(Student& stu)
{
	char sql[1024];
	sprintf(sql, "UPDATE students SET student_name ='%s',class_id = '%s',student_sex='%s',student_age='%d',student_phone='%s',student_mail='%s',student_grade='%d',student_password='%s' "
		"where student_id = %d", stu.student_name.c_str(), stu.class_id.c_str(), stu.student_sex.c_str(),
		stu.student_age, stu.student_phone.c_str(), stu.student_mail.c_str(),
		stu.student_grade, stu.student_password.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to update data : Error:%s\n", mysql_error(con));
		return false;
	}

	return true;
}

bool StudentManager::delete_student(int student_id)
{
	char sql[1024];
	sprintf(sql, "DELETE FROM student WHERE student_id =%d", student_id);

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to delete data : Error:%s\n", mysql_error(con));
		return false;
	}

	return true;
}

vector<Student> StudentManager::get_students(string condition)
{
	vector<Student> stuList;

	char sql[1024];
	sprintf(sql, "SELECT * FROM student %s ", condition.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to selete data : Error:%s\n", mysql_error(con));
		return {};
	}
	MYSQL_RES* res = mysql_store_result(con);

	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Student stu;
		stu.student_id = atoi(row[0]);
		stu.student_name = row[1];
		stu.student_sex = row[2];
		stu.class_id = row[3];
		stu.student_age = atoi(row[4]);
		stu.student_grade = atoi(row[5]);
		stu.student_mail = row[6];
		stu.student_password = row[7];
		stu.student_phone = row[8];

		stuList.push_back(stu);

	}
	return stuList;
}

void StudentManager::showAll()
{
	vector<Student> ret = StudentManager::GetInstance()->get_students();

	for (auto& t : ret)
	{
		cout << t.student_id << ' ' << t.student_name << ' ' << t.student_sex << ' ' << t.class_id << ' ' <<
			t.student_age << ' ' << t.student_grade << ' ' << t.student_mail << ' ' << t.student_password << ' ' << t.student_phone << endl;
	}
}
