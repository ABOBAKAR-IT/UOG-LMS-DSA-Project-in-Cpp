#include "student.h"
#include<iostream>
#include<fstream>          
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<cstring>
#include<Windows.h>
#include"time_table.h"
using namespace std;
student::student()
{       
	temp = new student_data;
	temp->s_name[20] = 'a'; temp->f_name[20] = 'a'; temp->address[20] = 'a'; temp->gender[20] = 'a'; temp->DOB[20] = 'a'; temp->mobile_no[20] = 'a'; temp->inter_marks[20] = 'a';
	temp->clas[20] = 'a'; temp->roll_no[20] = 'a'; temp->uog_mail[25] = 'a'; temp->password[20] = 'a';//Student data
	temp->GPA = 0.0, temp->CGPA = 0.0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			temp->subject[i].QUIZ[j] = 0;
			temp->subject[i].ASSIGNMENT[j] = 0;
		}
	for (int i = 0; i < 4; i++)
	{
		temp->subject[i].FINAL = 0;
		temp->subject[i].MID = 0;
		temp->subject[i].presentaton = 0;
		temp->subject[i].ATTENDENCE = 0;
		temp->subject[i].TOTAL_MARKS = 0;
		temp->subject[i].GRADE[4] = ' ';
	}
}
int student::student_management()
{
	char ch;
	do {
		system("cls");
		cout << "\t\t  **********************************************" << endl;
		cout << "\t\t  | *WELLCOME TO UOG STUDENT MANEGMENT SYSTEM* |" << endl;
		cout << "\t\t  **********************************************" << endl;
		cout << "\t\t\t************************************" << endl;
		cout << "\t\t\t|" << " Student Insert Data Press 1      |" << endl;
		cout << "\t\t\t|" << " Student Search Data Press 2      |" << endl;
		cout << "\t\t\t|" << " Student Update Data Press 3      |" << endl;
		cout << "\t\t\t|" << " Student Delete Data Press 4      |" << endl;
		cout << "\t\t\t|" << " Student Full Display Data Press 5|" << endl;
		cout << "\t\t\t|" << " BACK Press 6                     |" << endl;
		cout << "\t\t\t************************************" << endl << endl << endl;
		cout << "\t\t\t" << "Press any key to continue ::  ";

		cin >> ch;

		switch (ch)
		{
		case '1':
			student_insert_data();
			break;
		case '2':
			student_search_data();
			break;
		case '3':
			student_update_data();
			break;
		case '4':
			student_delete_data();
			break;
		case '5':
		{
			read_student_data();
			break;
		}
		case '6':
		{

			return 0;
		}

		default:
			cout << "Wrong entery" << endl;

		}

		cout << "Do You Want Again UOG STUDENT MANEGMENT SYSTEM n/y" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}//End function
void student::student_insert_data()
{
	temp = new student_data;
	static int c;
	int n;
	ifstream f;
	f.open("count.txt", ios::in);
	f >> c;
	n = c;
	f.close();
	cout << n << endl;
	cout << "    Enter Student Name" << endl << "    ";
	cin >> temp->s_name;
	cout << "    Enter Student Father Name" << endl << "    ";
	cin >> temp->f_name;
	cout << "    Enter Student Address" << endl << "    ";
	cin >> temp->address;
	cout << "    Enter Student Gender" << endl << "    ";
	cin >> temp->gender;
	cout << "    Enter Student Date of Birth" << endl << "    ";
	cin >> temp->DOB;
	cout << "    Enter Student Inter Marks" << endl << "    ";
	cin >> temp->inter_marks;
	cout << "    Enter Student Mobile number" << endl << "    ";
	cin >> temp->mobile_no;
	cout << "    Enter Student Class" << endl << "    ";
	cin >> temp->clas;
	string t_roll = "19014156-";
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
	strcpy_s(temp->roll_no, t_roll.c_str());
	cout << "   " << temp->s_name << " Roll Number   " << temp->roll_no << endl;
	string smail;
	cin.ignore();
	for (int i = 0; i < 12; i++)
		smail += temp->roll_no[i];
	for (int i = 0; i < 11; i++)
		smail += u_mail[i];
	strcpy_s(temp->uog_mail, smail.c_str());
	cout << "   " << temp->s_name << " UOG Mail   " << temp->uog_mail << endl;
	strcpy_s(temp->password, temp->roll_no);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			temp->subject[i].QUIZ[j] = 0;
			temp->subject[i].ASSIGNMENT[j] = 0;
		}
	for (int i = 0; i < 4; i++)
	{
		temp->subject[i].FINAL = 0;
		temp->subject[i].MID = 0;
		temp->subject[i].presentaton = 0;
		temp->subject[i].ATTENDENCE=0;
	}
	temp->next = NULL;
	if (head == NULL)
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
	cout << "Do you want to save n/y" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		write_student_data(tail);
	student_full_Display_data(tail);

}//End function
void student::student_full_Display_data(student_data* s1)
{
	t = s1;
	cout << "\t\t*********************************************************************************" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Student Name\t" << setw(15) << t->s_name << "\t\tFather Name\t" << setw(15) << t->f_name << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Date of Birth\t" << setw(15) << t->DOB << "\t\tGender\t\t" << setw(15) << t->gender << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Mobile Nomber\t" << setw(15) << t->mobile_no << "\t\tAddress\t\t" << setw(15) << t->address << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Inter Marks\t" << setw(15) << t->inter_marks << "\t\tDepartment\t" << setw(15) << t->clas << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Roll Nomber\t" << setw(15) << t->roll_no << "\t\tUni mail\t" << setw(15) << t->uog_mail << " |" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " GPA\t\t" << setw(15) << t->GPA << "\t\tCGPA\t\t" << setw(15) << t->CGPA << "\t\t|" << endl;
	cout << "\t\t|" << setiosflags(ios::left) << " Password\t" << setw(15) << t->password << "\t\t\t\t\t\t\t|" << endl;
	cout << "\t\t*********************************************************************************" << endl;
}//end function
void student::write_student_data(student_data* s2)
{
	t = s2;
	int n;
	ofstream fout, tout;
	ifstream fin;
	fout.open("student.txt", ios::app);
	fout.write((char*)t, sizeof(*t));
	fout.close();
	fin.open("count.txt", ios::in);
	fin >> n;
	n++;
	fin.close();
	tout.open("count.txt");
	tout << n;
	tout.close();
}//End function
void student::read_student_data()
{
	t = new student_data;
	ifstream fin;
	fin.open("student.txt", ios::in);
	fin.read((char*)t, sizeof(*t));
	while (!(fin.eof()))
	{

		student_full_Display_data(t);
		fin.read((char*)t, sizeof(*t));
	}
	fin.close();
}//End function
void student::student_search_data()
{
	t = new student_data;
	int n = 0;
	string rol;
	cout << "    Enter Student ID or Roll No" << endl << "    ";
	cin >> rol;
	ifstream fin;
	fin.open("student.txt", ios::in);
	fin.read((char*)t, sizeof(*t));
	while (!(fin.eof()))
	{
		if (rol == t->roll_no)
		{
			student_full_Display_data(t);
			n++;
		}
		fin.read((char*)t, sizeof(*t));
	}
	if (n == 0)
		cout << "Wrong Roll No" << endl;
	fin.close();
}//End function
void student::student_update_data()
{
	t = new student_data;
	int c = 0;
	char ch;
	cout << "    Enter Roll No" << endl << endl << "   ";
	string n;
	cin >> n;
	fstream f;
	f.open("student.txt", ios::in | ios::out | ios::ate);
	f.seekg(0);
	f.read((char*)t, sizeof(*t));
	while (!f.eof())
	{
		if (n == t->roll_no)
		{
			c++;
			do {
				cout << "\t\t*****************************************" << endl;
				cout << "\t\t| Enter Student Name          Press 1   | " << endl;
				cout << "\t\t| Enter Student Father Name   Press 2   | " << endl;
				cout << "\t\t| Enter Student Address       Press 3   | " << endl;
				cout << "\t\t| Enter Student Gender        Press 4   | " << endl;
				cout << "\t\t| Enter Student Date of Birth Press 5   | " << endl;
				cout << "\t\t| Enter Student Mobile number Press 6   | " << endl;
				cout << "\t\t| Enter Student Department    Press 7   | " << endl;
				cout << "\t\t| Enter Student New Password  Press 8   | " << endl;
				cout << "\t\t*****************************************" << endl;
				cout << "\t\t\t" << "Press any key to continue ::  ";


				cin >> ch;
				switch (ch)
				{
				case '1':
					cout << "\t\tEnter Student Name" << endl << "\t\t";
					cin >> t->s_name;
					break;
				case '2':
					cout << "\t\tEnter Student Father Name" << endl << "\t\t";
					cin >> t->f_name;
					break;
				case '3':
					cout << "\t\tEnter Student Address" << endl << "\t\t";
					cin >> t->address;
					break;
				case '4':
					cout << "\t\tEnter Student Gender" << endl << "\t\t";
					cin >> t->gender;
					break;
				case '5':
					cout << "\t\tEnter Student Date of Birth" << endl << "\t\t";
					cin >> t->DOB;
					break;
				case '6':
					cout << "\t\tEnter Student Mobile number" << endl << "\t\t";
					cin >> t->mobile_no;
					break;
				case '7':
					cout << "\t\tEnter Student Department" << endl << "\t\t";
					cin >> t->clas;
					break;
				case '8':
					cout << "\t\t Enter Student New Password " << endl << "\t\t";
					cin >> t->password;
					break;
				default:
					cout << "Wrong Entery" << endl;
				}
				cout << "\t\tDo You Want Again Student Update Data n/y" << endl;
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
		cout << "Wrong Roll No" << endl;
	f.close();
}//End function
void student::student_delete_data()
{
	t = new student_data;
	int c = 0;
	cout << "\t\tEnter Roll No" << endl << "\t\t";
	string n;
	cin >> n;
	ifstream fin;
	ofstream fout;
	fin.open("student.txt", ios::in);
	fout.open("temp.txt", ios::app);
	fin.read((char*)t, sizeof(*t));
	while (!(fin.eof()))
	{
		if (n != t->roll_no)
		{
			fout.write((char*)t, sizeof(*t));

		}
		if (n == t->roll_no)
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
	remove("student.txt");
	rename("temp.txt", "student.txt");
}//End function
int student::student_login(char id[20], char pwsd[20])
{
	t = new student_data;
	time_table tt;
	int n = 0;
	ifstream fin;
	fin.open("student.txt", ios::in);
	fin.read((char*)t, sizeof(*t));
	while (!(fin.eof()))
	{
		if (!(strcmp(id, t->roll_no)))
			if (!(strcmp(pwsd, t->password)))
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
			cout << "\t\t  ***********************************************" << endl;
			cout << "\t\t  |    * WELLCOME TO UOG LMS  " << t->s_name << " *\t|" << endl;
			cout << "\t\t  ***********************************************" << endl;
			cout << "\t\t\t***********************************" << endl;
			cout << "\t\t\t|" << " COURSE LIST  \t\t Press 1  |" << endl;
			cout << "\t\t\t|" << " GPA          \t\t Press 2  |" << endl;
			cout << "\t\t\t|" << " TIME TABLE   \t\t Press 3  |" << endl;
			cout << "\t\t\t|" << " MAIL         \t\t Press 4  |" << endl;
			cout << "\t\t\t|" << " Exit         \t\t Press 5  |" << endl;
			cout << "\t\t\t***********************************" << endl << endl << endl;
			cout << "\t\t\t" << "Press any key to continue ::  ";
			cin >> ch;
			switch (ch)
			{
			case '1':
			{   labal:
				system("cls");
				cout << "\t\t\t*********************************************" << endl;
				cout << "\t\t\t|  *              COURSE LIST            *  |" << endl;
				cout << "\t\t\t*********************************************" << endl;
				cout << "\t\t\t *******************************************" << endl;
				cout << "\t\t\t |" << " Data Structure and Algorithms   Press 1 |" << endl;
				cout << "\t\t\t |" << " Web Systems & Technologies      Press 2 |" << endl;
				cout << "\t\t\t |" << " Multimedia System & Design      Press 3 |" << endl;
				cout << "\t\t\t |" << " Discrete Structures             Press 4 |" << endl;
				cout << "\t\t\t *******************************************" << endl << endl << endl;
				cout << "\t\t\t" << "Press any key to continue ::  ";
				cin >> ch;
				int nn = ch - '0';
				if (nn > 4)
				{
					cout << "\t\t\t RONG ENTERY" << endl;
					Sleep(1000);
					goto labal;
				}
				else
					course_data(nn,t);
			}
					break;
			case '2':
				U_GPA(t);
				break;
			case '3':
				tt.read_time_table_data();
				break;
			case '4':
				MAIL.uog_mail_system(id);
				break;
			case '5':
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
int student::edit_student_subject_data(int s)
{
	t = new student_data;

	char ch;
	cout << "\t\tEnter Roll No" << endl << "\t\t";
	string n;
	cin >> n;
	fstream f;
	f.open("student.txt", ios::in | ios::out | ios::ate);
	f.seekg(0);
	f.read((char*)t, sizeof(*t));
	while (!f.eof())
	{
		if (n == t->roll_no)
		{
			do {
				system("cls");
				cout << "\t\t************************************************" << endl;
				cout << "\t\t| Enter Student QUIZ MARKS           Press 1  |" << endl;
				cout << "\t\t| Enter Student ASSIGNMENT Number    Press 2  |" << endl;
				cout << "\t\t| Enter Student PRESENTATION         Press 3  |" << endl;
				cout << "\t\t| Enter Student MID                  Press 4  |" << endl;
				cout << "\t\t| Enter Student FINAL                Press 5  |" << endl;
				cout << "\t\t| Enter Student Attendence           Press 6  |" << endl;
				cout << "\t\t| BACK                               Press 7  |" << endl;
				cout << "\t\t************************************************" << endl;
				cout << "\t\t\t" << "Press any key to continue ::  " << endl << "\t\t";
				cin >> ch;
				switch (ch)
				{
				case '1':
				{   do {
					system("cls");
					cout << "\t\tEnter 1 QUIZ MARKS Press 1" << endl;
					cout << "\t\tEnter 2 QUIZ MARKS Press 2" << endl;
					cout << "\t\tEnter 3 QUIZ MARKS Press 3" << endl;
					cout << "\t\tEnter 4 QUIZ MARKS Press 4" << endl;
					cout << "\t\tPress any key to continue ::  " << "\t\t";
					cin >> ch;
					switch (ch)
					{
					case '1':
						cout << "Enter 1 QUIZ MARKS" << endl << "\t\t";
						cin >> t->subject[s].QUIZ[0];
						break;
					case '2':
						cout << "Enter 2 QUIZ MARKS" << endl << "\t\t";
						cin >> t->subject[s].QUIZ[1];
						break;
					case '3':
						cout << "\t\tEnter 3 QUIZ MARKS" << endl << "\t\t";
						cin >> t->subject[s].QUIZ[2];
						break;
					case '4':
						cout << "\t\tEnter 4 QUIZ MARKS" << endl << "\t\t";
						cin >> t->subject[s].QUIZ[3];
						break;
					}//switch end
					cout << "\t\tDo you want again Edit QUIZ MARKS n/y" << endl << "\t\t";
					cin >> ch;
				} while (ch == 'y' || ch == 'Y');//do end
				break;
				}//case 1 end
				case '2':
				{
					do {
						system("cls");
						cout << "\t\tEnter 1 ASSIGNMENT MARKS Press 1" << endl;
						cout << "\t\tEnter 2 ASSIGNMENT MARKS Press 2" << endl;
						cout << "\t\tEnter 3 ASSIGNMENT MARKS Press 3" << endl;
						cout << "\t\tEnter 4 ASSIGNMENT MARKS Press 4" << endl;
						cout << "\t\tPress any key to continue ::  ";
						cin >> ch;
						switch (ch)
						{
						case '1':
							cout << "\t\tEnter 1 ASSIGNMENT MARKS" << endl << "\t\t";
							cin >> t->subject[s].ASSIGNMENT[0];
							break;
						case '2':
							cout << "\t\tEnter 2 ASSIGNMENT MARKS" << endl << "\t\t";
							cin >> t->subject[s].ASSIGNMENT[1];
							break;
						case '3':
							cout << "\t\tEnter 3 ASSIGNMENT MARKS" << endl << "\t\t";
							cin >> t->subject[s].ASSIGNMENT[2];
							break;
						case '4':
							cout << "\t\tEnter 4 ASSIGNMENT MARKS" << endl << "\t\t";
							cin >> t->subject[s].ASSIGNMENT[3];
							break;
						}//switch end
						cout << "\t\tDo you want again Edit ASSIGNMENT MARKS n/y" << endl << "\t\t";
						cin >> ch;
					} while (ch == 'y' || ch == 'Y');//do end
					break;
				}//case 2 end
				case '3':
				{
					cout << "\t\tEnter Student PRESENTATION marks" << endl << "\t\t";
					cin >> t->subject[s].presentaton;
					break;
				}
				case'4':
				{
					cout << "\t\tEnter Student MID marks" << endl << "\t\t";
					cin >> t->subject[s].MID;
					break;
				}
				case'5':
				{
					cout << "\t\tEnter Student FINAL marks" << endl << "\t\t";
					cin >> t->subject[s].FINAL;
					break;
				}
				case'6':
				{
					cout << "\t\tEnter Student Attendence" << endl << "\t\t";
					cin >> t->subject[s].ATTENDENCE;
					break;
				}
				case'7':
				{
					return 0;
					break;
				}
				}// first switch end
				cout << "\t\tDo you want again Edit Student Data n/y" << endl << "\t\t";
				cin >> ch;
			} while (ch == 'y' || ch == 'Y');//do end

			int te = 0, siz = 0, n = 0;
			n = f.tellp();
			siz = sizeof(*t);
			te = n - siz;
			f.seekp(te);
			f.write((char*)t, sizeof(*t));
			break;
		}//if end
		f.read((char*)t, sizeof(*t));
	}//while end
	f.close();
}//end funtion 
void student::course_data(int N, student_data* s3)
{
	t = new student_data;
	t = s3;
	N = N - 1;

	cout << "\t|****************************************************************************************************" << endl;
	cout << setiosflags(ios::left) << "\t|" << setw(20) << t->roll_no << setw(20) << "|   ASSIGNMENT" << setw(20) << "|       QUIZ" << setw(20) << "|   PRESENTATION " << setw(10) << " | MID " << setw(10) << " | FINAL |" << endl;
	cout << "\t|---------------------------------------------------------------------------------------------------|" << endl;
	cout << setiosflags(ios::left) << "\t|" << setw(20) << " " << setw(5) << "| A1 " << setw(5) << "| A2 |" << setw(5) << " A3 |" << setw(5) << " A4 |" << setw(5) << " Q1 |" << setw(5) << " Q2 |" << setw(5) << " Q3 |" << setw(5) << " Q4 |" << setw(20) << "      P1 " << setw(10) << "|  M1  " << setw(10) << "|  F1   |" << endl;
	cout << setiosflags(ios::left) << "\t|" << setw(20) << "Aggregate Weightage" << setw(5) << "| 10 " << setw(5) << "| 10 |" << setw(5) << " 10 |" << setw(5) << " 10 |" << setw(5) << " 5 |" << setw(5) << " 5 |" << setw(5) << " 5 |" << setw(5) << " 5 |" << setw(20) << "      10 " << setw(10) << "|  25  " << setw(10) << "|  50   |" << endl;
	cout << setiosflags(ios::left) << "\t|" << setw(20) << "Aggregate Marks" << "| " << setw(3) << t->subject[N].ASSIGNMENT[0] << "| " << setw(3) << t->subject[N].ASSIGNMENT[1] << "| " << setw(3) << t->subject[N].ASSIGNMENT[2] << "| " << setw(3) << t->subject[N].ASSIGNMENT[3] << "| " << setw(3) << t->subject[N].QUIZ[0] << "| " << setw(3) << t->subject[N].QUIZ[1] << "| " << setw(3) << t->subject[N].QUIZ[2] << "| " << setw(3) << t->subject[N].QUIZ[3] << "|     " << setw(15) << t->subject[N].presentaton << "| " << setw(8) << t->subject[N].MID << "| " << setw(6) << t->subject[N].FINAL << "|" << endl;
	cout << "\t|---------------------------------------------------------------------------------------------------|" << endl;
	cout << setiosflags(ios::left) << "\t|" << setw(20) << "Student Attendence" << setw(5) << t->subject[N].ATTENDENCE << "\t\t\t\t\t\t\t\t\t    |" << endl;
	cout << "\t|---------------------------------------------------------------------------------------------------|" << endl;


}
void student::U_GPA(student_data* s4)
{
	t = s4;
	float ass[4] = { 0.0,0.0,0.0,0.0 }, qz[4] = { 0.0,0.0,0.0,0.0 }, Credit_Hours[4] = { 0.0,0.0,0.0,0.0}, TOTAL_Credit_Hours = 0.0;
	for (int i = 0; i < 4; i++)
	{
		
		for (int j = 0; j < 4; j++)
		{

			ass[i] = ass[i] + t->subject[i].ASSIGNMENT[j];
			qz[i] = qz[i] + t->subject[i].QUIZ[j];
		}

		ass[i] = (ass[i] * 10) / 40;
		qz[i] = (qz[i] * 5) / 40;
		t->subject[i].TOTAL_MARKS = ass[i] + qz[i] + t->subject[i].presentaton + t->subject[i].MID + t->subject[i].FINAL;

		if (t->subject[i].TOTAL_MARKS <= 100.0 && t->subject[i].TOTAL_MARKS >= 84.5)
		{
			string gr = "A+";
			strcpy_s(t->subject[i].GRADE, gr.c_str());
		}
		else	if (t->subject[i].TOTAL_MARKS <= 84.0 && t->subject[i].TOTAL_MARKS >= 79.5)
		{
			string gr = "A";
			strcpy_s(t->subject[i].GRADE, gr.c_str());
		}
		else	if (t->subject[i].TOTAL_MARKS <= 79.0 && t->subject[i].TOTAL_MARKS >= 74.5)
		{
			string gr = "B+";
			strcpy_s(t->subject[i].GRADE, gr.c_str());
		}
		else	if (t->subject[i].TOTAL_MARKS <= 74.0 && t->subject[i].TOTAL_MARKS >= 69.5)
		{
			string gr = "B";
			strcpy_s(t->subject[i].GRADE, gr.c_str());
		}
		else	if (t->subject[i].TOTAL_MARKS <= 69.0 && t->subject[i].TOTAL_MARKS >= 64.5)
		{
			string gr = "B-";
			strcpy_s(t->subject[i].GRADE, gr.c_str());
		}
		else	if (t->subject[i].TOTAL_MARKS <= 64.0 && t->subject[i].TOTAL_MARKS >= 59.5)
		{
			string gr = "C+";
			strcpy_s(t->subject[i].GRADE, gr.c_str());
		}
		else	if (t->subject[i].TOTAL_MARKS <= 59.0 && t->subject[i].TOTAL_MARKS >= 54.5)
		{
			string gr = "C";
			strcpy_s(t->subject[i].GRADE, gr.c_str());
		}
		else	if (t->subject[i].TOTAL_MARKS <= 54.0 && t->subject[i].TOTAL_MARKS >= 49.5)
		{
			string gr = "D";
			strcpy_s(t->subject[i].GRADE, gr.c_str());
		}
		else
		{
			if (t->subject[i].TOTAL_MARKS < 49.5 && t->subject[i].TOTAL_MARKS > 10)
			{
				string gr = "F";
				strcpy_s(t->subject[i].GRADE, gr.c_str());
			}
			else
			{
				string gr = "0";
				strcpy_s(t->subject[i].GRADE, gr.c_str());
			}
		}
		if (t->subject[i].GRADE == "A+")
		{
			Credit_Hours[i] = 4.0 * 4.0;
		}
		else if (t->subject[i].GRADE == "A")
		{
			Credit_Hours[i] = 3.7 * 4.0;
		}
		else if (t->subject[i].GRADE == "B+")
		{
			Credit_Hours[i] = 3.4 * 4.0;
		}
		else if (t->subject[i].GRADE == "B")
		{
			Credit_Hours[i] = 3.0 * 4.0;
		}
		else if (t->subject[i].GRADE == "B-")
		{
			Credit_Hours[i] = 2.5 * 4.0;
		}
		else if (t->subject[i].GRADE == "C+")
		{
			Credit_Hours[i] = 2.0 * 4.0;
		}
		else if (t->subject[i].GRADE == "C")
		{
			Credit_Hours[i] = 1.5 * 4.0;
		}
		else if (t->subject[i].GRADE == "D")
		{
			Credit_Hours[i] = 1.0 * 4.0;
		}
		else
		{
			Credit_Hours[i] = 0.0 * 4.0;
		}

		TOTAL_Credit_Hours += Credit_Hours[i];

	}//OUTER FOR LOOP
	t->GPA = TOTAL_Credit_Hours * 4 / 72;
	t->CGPA = t->GPA;
	show_GPA(t);
}//FUNCTION END
void student::show_GPA(student_data* s5)
{
	t = s5;
	cout << "\t\t\t *************************************************************************************" << endl;
	cin.ignore();
	cout << "\t\t\t " << setiosflags(ios::left) << setw(15) << "| COURSE CODE " << setw(34) << "| SUBJECT " << setw(6) << "| MARKS " << setw(8) << " | GRADE" << setw(10) << "    | Credit Hours |" << endl;
	cout << "\t\t\t *************************************************************************************" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(15) << "| IT209  " << setw(34) << "|  Data Structure and Algorithms  " << "| " << setw(6) << setprecision(2) << t->subject[0].TOTAL_MARKS << " | " << setw(8) << t->subject[0].GRADE << " | " << setw(10) << "     3       |" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(15) << "| IT304  " << setw(34) << "|  Web Systems & Technologies    " << "| " << setw(6) << setprecision(2) << t->subject[1].TOTAL_MARKS << " | " << setw(8) << t->subject[1].GRADE << " | " << setw(10) << "     3       |" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(15) << "| IT204  " << setw(34) << "|  Multimedia System & Design   " << "| " << setw(6) << setprecision(2) << t->subject[2].TOTAL_MARKS << " | " << setw(8) << t->subject[2].GRADE << " | " << setw(10) << "     3       |" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(15) << "| CS261  " << setw(34) << "|  Discrete Structures   " << "| " << setw(6) << setprecision(2) << t->subject[3].TOTAL_MARKS << " | " << setw(8) << t->subject[3].GRADE << " | " << setw(10) << "     3       |" << endl;
	cout << "\t\t\t *************************************************************************************" << endl;
	cout << "\t\t\t " << setiosflags(ios::left) << setw(10) << "| GPA      " << setw(38) << t->GPA << setw(20) << "| CGPA" << setw(14) << t->CGPA << " |" << endl;
	cout << "\t\t\t *************************************************************************************" << endl;
}
