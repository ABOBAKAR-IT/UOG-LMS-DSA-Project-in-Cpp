#pragma once
#include"UOG_MAIL.h"
struct subject_marks
{
	float QUIZ[4];
	float ASSIGNMENT[4];
	float MID;
	float FINAL;
	float presentaton;
	int ATTENDENCE;
	float TOTAL_MARKS;
	float MARKS;
	char GRADE[4];
};

struct student_data
{
	char s_name[20], f_name[20], address[20], gender[20], DOB[20], mobile_no[20], inter_marks[20];
	char clas[20], roll_no[20], uog_mail[25], password[20];//Student data
	float GPA = 0.0, CGPA = 0.0;
	subject_marks subject[4];
	student_data *next;
};
class student
{
	student_data* head, * tail, * temp, * t;
	

	UOG_MAIL MAIL;
	void student_insert_data();
	void student_search_data();
	void student_update_data();
	void student_delete_data();
	void student_full_Display_data(student_data *s1);
	void write_student_data(student_data* s2);
	void read_student_data();
	void course_data(int N, student_data* s3);
	void U_GPA(student_data* s4);
	void show_GPA(student_data* s5);
protected:
	int edit_student_subject_data(int s);
public:
	student();
	int student_management();
	int student_login(char id[20], char pwsd[20]);
};

