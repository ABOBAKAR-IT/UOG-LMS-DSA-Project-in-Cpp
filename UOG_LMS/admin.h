#pragma once
#include "teacher.h"
#include "student.h"
#include "time_table.h"
struct admin_data
{
	char a_name[20], af_name[20], a_address[20], a_gender[20], a_DOB[20], a_mobile_no[20], a_qualification[20];
	char a_id[20], a_uog_mail[25], a_password[20];//Admin data
	admin_data* next;
};
class admin : protected teacher
{

	admin_data* head, * tail, * temp, * t;
	int admin_managment();
	void admin_insert_data();
	void admin_search_data();
	void admin_update_data();
	void admin_full_Display_data(admin_data* t1);
	void write_admin_data(admin_data* t2);
	void read_admin_data();
public:
	void check_login(char id[12], char pwsd[12]);
	int uni_manegment_systam(admin_data* t3);
};

