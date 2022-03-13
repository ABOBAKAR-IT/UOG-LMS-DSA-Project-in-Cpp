#include "teacher.h"
#include"time_table.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
int teacher::teacher_management()
{
	char ch;
	do {
		system("cls");
		cout << "\t\t  **********************************************" << endl;
		cout << "\t\t  | *WELLCOME TO UOG TEACHER MANEGMENT SYSTEM* |" << endl;
		cout << "\t\t  **********************************************" << endl;

		cout << "\t\t\t************************************" << endl;
		cout << "\t\t\t|" << " Teacher Insert Data Press 1      |" << endl;
		cout << "\t\t\t|" << " Teacher Search Data Press 2      |" << endl;
		cout << "\t\t\t|" << " Teacher Update Data Press 3      |" << endl;
		cout << "\t\t\t|" << " Teacher Delete Data Press 4      |" << endl;
		cout << "\t\t\t|" << " Teacher Display Data Press 5     |" << endl;
		cout << "\t\t\t|" << " Back                 Press 6     |" << endl;
		cout << "\t\t\t************************************" << endl << endl << endl;
		cout << "\t\t\t" << "Press any key to continue ::  ";

		cin >> ch;

		switch (ch)
		{
		case '1':
			teacher_insert_data();
			break;
		case '2':
			teacher_search_data();
			break;
		case '3':
			teacher_update_data();
			break;
		case '4':
			teacher_delete_data();
			break;
		case '5':
			read_teacher_data();
			break;
		case '6':
			return 0;
			break;
		default:
			cout << "Wrong entery" << endl;
		}
		cout << "Do You Want Back  TEACHER MANEGMENT SYSTEM n/y" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}//End function
void teacher::teacher_insert_data()
{
	temp = new teacher_data;
	tail = NULL;
	head = NULL;
	static int c;
	int n;
	ifstream f;
	f.open("t_count.txt", ios::in);
	f >> c;
	n = c;
	f.close();
	cout << n << endl;
	cout << "\t\tEnter Teacher Name" << endl << "\t\t";
	cin >> temp->t_name;
	cout << "\t\tEnter Teacher Father Name" << endl << "\t\t";
	cin >> temp->tf_name;
	cout << "\t\tEnter Teacher Address" << endl << "\t\t";
	cin >> temp->t_address;
	cout << "\t\tEnter Teacher Gender" << endl << "\t\t";
	cin >> temp->t_gender;
	cout << "\t\tEnter Teacher Date of Birth" << endl << "\t\t";
	cin >> temp->t_DOB;
	cout << "\t\tEnter Teacher Qualification" << endl << "\t\t";
	cin >> temp->qualification;
	cout << "\t\tEnter Teacher Mobile number" << endl << "\t\t";
	cin >> temp->t_mobile_no;
	cout << "\t\tEnter Teacher Subject" << endl << "\t\t";
	cin >> temp->t_subject;
	string t_roll = "teacher-";
	char u_mail[11] = { '@','u','o','g','.','e','d','u','.','p','k' };
	static int t_rol[3] = { 0,0,0 };
	if (c < 9)
	{
		t_rol[2] = ++c;
		t_rol[1] = 0;
	}
	else
	{
		++c;
		t_rol[1] = c / 10;
		t_rol[2] = c % 10;
	}
	for (int i = 0; i < 3; i++)
		t_roll += t_rol[i] + '0';
	strcpy_s(temp->t_id, t_roll.c_str());

	cout << "\t\t" << temp->t_name << " Teacher ID " << temp->t_id << endl;
	string smail;
	cin.ignore();
	for (int i = 0; i < 11; i++)
		smail += temp->t_id[i];
	for (int i = 0; i < 11; i++)
		smail += u_mail[i];
	strcpy_s(temp->t_uog_mail, smail.c_str());
	cout << "\t\t" << temp->t_name << " UOG Mail " << temp->t_uog_mail << endl;
	strcpy_s(temp->t_password, temp->t_id);
	temp->next = NULL;
	if (head == NULL)
	{
		head = tail = temp;
	}
	else
	{
		this->tail->next = this->temp;
		this->tail = tail->next;
	}
	cout << "\t\tDo you want to save n/y" << endl << "\t\t";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		write_teacher_data(tail);
	teacher_full_Display_data(tail);

}//End function
void teacher::teacher_full_Display_data(teacher_data* t1)
{
	t = t1;
	cout << "\t\t*********************************************************************************" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Teacher Name\t " << setw(15) << t->t_name << "\tFather Name\t" << setw(15) << t->tf_name << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Date of Birth\t " << setw(15) << t->t_DOB << "\tGender\t\t" << setw(15) << t->t_gender << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Mobile Nomber\t " << setw(15) << t->t_mobile_no << "\tAddress\t\t" << setw(15) << t->t_address << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Qualification\t " << setw(15) << t->qualification << "\tDepartment\t" << setw(15) << t->t_subject << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " ID\t\t " << setw(15) << t->t_id << "\tUni mail\t" << setw(15) << t->t_uog_mail << "  |" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Password\t " << setw(15) << t->t_password << "\t\t\t\t\t\t|" << endl;
	cout << "\t\t*********************************************************************************" << endl;
}//end function
void teacher::write_teacher_data(teacher_data* t2)
{
	int n;
	ofstream fout, t;
	ifstream fin;
	fout.open("teacher.txt", ios::app);
	fout.write((char*)t2, sizeof(*t2));
	fout.close();
	fin.open("t_count.txt", ios::in);
	fin >> n;
	n++;
	fin.close();
	t.open("t_count.txt");
	t << n;
	t.close();
}//End function
void teacher::read_teacher_data()
{
	t = new teacher_data;
	ifstream fin;
	fin.open("teacher.txt", ios::in);
	fin.read((char*)t, sizeof(*t));
	while (!(fin.eof()))
	{

		teacher_full_Display_data(t);
		fin.read((char*)t, sizeof(*t));
	}
	fin.close();
}//End function
void teacher::teacher_search_data()
{
	t = new teacher_data;
	int n = 0;
	string rol;
	cout << "\t\tEnter Teacher ID " << endl << "\t\t";
	cin >> rol;
	ifstream fin;
	fin.open("teacher.txt", ios::in);
	fin.read((char*)t, sizeof(*t));
	while (!(fin.eof()))
	{
		if (rol == t->t_id)
		{
			n++;
			teacher_full_Display_data(t);
		}
		fin.read((char*)t, sizeof(*t));
	}
	fin.close();
	if (n == 0)
		cout << "Wrong Id" << endl;
}//End function
void teacher::teacher_update_data()
{
	t = new teacher_data;
	int c = 0;
	char ch;
	cout << "Enter Teacher ID" << endl;
	string n;
	cin >> n;
	fstream f;
	f.open("teacher.txt", ios::in | ios::out | ios::ate);
	f.seekg(0);
	f.read((char*)t, sizeof(*t));
	while (!f.eof())
	{
		if (n == t->t_id)
		{
			c++;
			do {
				system("cls");
				cout << "\t\t*****************************************" << endl;
				cout << "\t\t| Enter Teacher Name          Press 1  | " << endl;
				cout << "\t\t| Enter Teacher Father Name   Press 2  | " << endl;
				cout << "\t\t| Enter Teacher Address       Press 3  | " << endl;
				cout << "\t\t| Enter Teacher Gender        Press 4  | " << endl;
				cout << "\t\t| Enter Teacher Date of Birth Press 5  | " << endl;
				cout << "\t\t| Enter Teacher Mobile number Press 6  | " << endl;
				cout << "\t\t| Enter Teacher Department    Press 7  | " << endl;
				cout << "\t\t| Enter Teacher Subject name  Press 8  | " << endl;
				cout << "\t\t*****************************************" << endl;
				cout << "\t\t\t" << "Press any key to continue ::  ";
				cin >> ch;
				switch (ch)
				{
				case '1':
					cout << "\t\tEnter Teacher Name" << endl << "\t\t";
					cin >> t->t_name;
					break;
				case '2':
					cout << "\t\tEnter Teacher Father Name" << endl << "\t\t";
					cin >> t->tf_name;
					break;
				case '3':
					cout << "\t\tEnter Teacher Address" << endl << "\t\t";
					cin >> t->t_address;
					break;
				case '4':
					cout << "\t\tEnter Teacher Gender" << endl << "\t\t";
					cin >> t->t_gender;
					break;
				case '5':
					cout << "\t\tEnter Teacher Date of Birth" << endl << "\t\t";
					cin >> t->t_DOB;
					break;
				case '6':
					cout << "\t\tEnter Teacher Mobile number" << endl << "\t\t";
					cin >> t->t_mobile_no;
					break;
				case '7':
					cout << "\t\tEnter Teacher Qualification" << endl;
					cin >> t->qualification;
					break;
				case'8':
					cout << "\t\tEnter Teacher Subject" << endl;
					cin >> t->t_subject;
					break;
				default:
					cout << "wrong Entery" << endl;
				}
				cout << "\t\tDo You Want Again Teacher Update Data n/y" << endl;
				cin >> ch;
			} while (ch == 'y' || ch == 'Y');
			int te = 0, siz = 0, n = 0;
			n = f.tellp();
			siz = sizeof(*t);
			te = n - siz;
			f.seekp(te);
			f.write((char*)t, sizeof(*t));
			break;
		}
		f.read((char*)t, sizeof(*t));
	}
	if (c == 0)
		cout << "Wrong Id" << endl;
	f.close();

}//End function
void teacher::teacher_delete_data()
{
	t = new teacher_data;
	int c = 0;
	cout << "\t\tEnter Teacher ID for Delete" << endl << "\t\t";
	string n;
	cin >> n;
	ifstream fin;
	ofstream fout;
	fin.open("teacher.txt", ios::in);
	fout.open("temp.txt", ios::app);
	fin.read((char*)t, sizeof(*t));
	while (!(fin.eof()))
	{
		if (n != t->t_id)
		{

			fout.write((char*)t, sizeof(*t));
		}
		if (n == t->t_id)
		{
			cout << "\t\t" << n << " Data Delete" << endl;
			c = 2;
		}
		fin.read((char*)t, sizeof(*t));
	}
	if (c == 0)
		cout << "\t\t" << n << "  No Data In File" << endl;
	fin.close();
	fout.close();
	remove("teacher.txt");
	rename("temp.txt", "teacher.txt");
}//End function
int teacher::t_check_login(char id[12], char pwsd[12])
{
	t = new teacher_data;
	time_table tt;
	int n = 0;
	ifstream fin;
	fin.open("teacher.txt", ios::in);
	fin.read((char*)t, sizeof(*t));
	while (!(fin.eof()))
	{
		if (!(strcmp(id, t->t_id)))
			if (!(strcmp(pwsd, t->t_password)))
			{
				n = 10;
				break;
			}
		fin.read((char*)t, sizeof(*t));
	}
	fin.close();
	if (n == 10)
	{
		char ch;
		do {
			system("cls");
			cout << "\t\t  *********************************************" << endl;
			cout << "\t\t  | \t  *WELLCOME TO UOG LMS  " << t->t_name << " *       |" << endl;
			cout << "\t\t  *********************************************" << endl;
			cout << "\t\t\t**********************************" << endl;
			cout << "\t\t\t|" << " EDIT STUDENT DATA Press 1      |" << endl;
			cout << "\t\t\t|" << " TIME TABLE        Press 2      |" << endl;
			cout << "\t\t\t|" << " MAIL              Press 3      |" << endl;
			cout << "\t\t\t|" << " Exit              Press 4      |" << endl;
			cout << "\t\t\t**********************************" << endl << endl << endl;
			cout << "\t\t\t" << "Press any key to continue ::  ";

			cin >> ch;

			switch (ch)
			{
			case '1':
				edit_student_data();
				break;
			case '2':
				tt.read_time_table_data();
				break;
			case '3':
				UOG_MAIL m;
				m.uog_mail_system(id);
				break;
			case '4':
				return 0;
				break;
			default:
				cout << "\t\tWrong entery" << endl;
			}
			cout << "\t\tDo You Want Again UOG LMS Main Page n/y" << endl << "\t\t";
			cin >> ch;
		} while (ch == 'y' || ch == 'Y');
	}
	else
	{
		cout << "\t\tWrong ID Try Again \n";
	}
}
void teacher::edit_student_data()
{
	int n = 0;
	n = t->t_uog_mail[10] - '0';
	n = n - 1;
	edit_student_subject_data(n);
}

