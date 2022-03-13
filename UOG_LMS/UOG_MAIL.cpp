#include "UOG_MAIL.h"
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
int a = 0;
using namespace std;
int UOG_MAIL::uog_mail_system(char sid[20])
{
	char ch;
	do
	{
		
		system("cls");
		cout << "\t\t\t  ********************************************" << endl;
		cout << "\t\t\t  |     *WELLCOME TO UOG MAIL SYSTEM*        |" << endl;
		cout << "\t\t\t  ********************************************" << endl;
		cout << "\t\t\t************************************************" << endl;
		cout << "\t\t\t|" << " INBOX MAIL             \t Press 1       |" << endl;
		cout << "\t\t\t|" << " CHECK SEND MAIL        \t Press 2       |" << endl;
		cout << "\t\t\t|" << " SEND MAIL TO AN OTHER  \t Press 3       |" << endl;
		cout << "\t\t\t|" << " Back                   \t Press 4       |" << endl;
		cout << "\t\t\t************************************************" << endl << endl << endl;
		cout << "\t\t\t" << "Press any key to continue ::  ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			inbox_mail(sid);
			break;
		case'2':
			send_mail(sid);
			break;
		case'3':
			SEND_MAIL_TO_AN_OTHER(sid);
			break;
		case'4':
			return 0;
			break;
		}
		cout << "do you again y/n" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}
void UOG_MAIL::SEND_MAIL_TO_AN_OTHER(char sid1[20])
{
	temp = new mail_data;
	tail = NULL;
	head = NULL;
	char s;
	string sms;
	int i = 0, n = 0;
	cout << "Enter Reciver mail" << endl;
	cin >> temp->reciver_id;
	strcpy_s(temp->sender_id, sid1);
	
	cout << "sender id  " << temp->sender_id << endl;
	cout << "write mail " << endl << endl;
	do {
		s = _getch();
		if (s == ' ')
		{
			sms += s;
		}
		else if (s == '\r')
		{
			break;
		}
		else
		{
			sms += s;
		}
		cout << s;
		n++;
	} while (n != 100);

	cout << endl << endl;
	strcpy_s(temp->massage, sms.c_str());
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
	write_mail_data(tail);
}
void UOG_MAIL::send_mail(char id[20])
{
	top = NULL;
	t = new mail_data;
	int n = 0;
	char send[20];
	ifstream fin;
	fin.open("uog_mail.txt", ios::in || ios::binary);
	fin.read((char*)t, sizeof(*t));

	while (!(fin.eof()))
	{
		if (!strcmp(id, t->sender_id))
		{
			mail_data* tn = new mail_data;
			tn = t;
			tn->next = top;
			top = tn;
			a = 1;
			n = 1;
			t = new mail_data;
		}

		fin.read((char*)t, sizeof(*t));
	}

	fin.close();
	if (n == 0)
		cout << "no data " << endl;
	else
	{
		//top->next = NULL;
		stack();
	}
}
void UOG_MAIL::inbox_mail(char id[20])
{
	top = NULL;
	t = new mail_data;
	int n = 0;
	char send[20];
	ifstream fin;
	fin.open("uog_mail.txt", ios::in||ios::binary);
	fin.read((char*)t, sizeof(*t));
	
		while (!(fin.eof()))
	{
		if (!strcmp(id, t->reciver_id))
		{
			mail_data* tn = new mail_data;
			tn = t;
			tn->next = top;
			top = tn;
			a = 2;
			n = 1;
			t = new mail_data;
		}

		fin.read((char*)t, sizeof(*t));
	}
	
	fin.close();
	if (n == 0)
		cout << "no data " << endl;
	else
	{
		
		stack();
	}
}
void UOG_MAIL::write_mail_data(mail_data* d)
{
	t = d;
	ofstream fout;
	fout.open("uog_mail.txt",ios::app | ios::binary);
	fout.write((char*)t, sizeof(*t));
	fout.close();
}
void UOG_MAIL::stack()
{
	mail_data* ptr;
	ptr = top;
	while (ptr != NULL) {
		show_mail(ptr);
		ptr = ptr->next;
	}
}
void UOG_MAIL::show_mail(mail_data* p)
{
	if (a == 1)
	{
		cout << "\t\t\t******************************************************" << endl;
		cout << "\t\t\tTO    " << p->reciver_id << "@uog.edu.pk" << endl << endl;
		cout << "\t\t\tMASSAGE :" << endl;
		cout << "\t\t\t" << p->massage;
		cout << endl << endl;
		cout << "\t\t\t******************************************************" << endl;
	}
	if (a == 2)
	{
		cout << "\t\t\t******************************************************" << endl;
		cout << "\t\t\tFROM   " << p->sender_id << "@uog.edu.pk" << endl << endl;
		cout << "\t\t\tMASSAGE :" << endl;
		cout << "\t\t\t" << p->massage;
		cout << endl << endl;
		cout << "\t\t\t******************************************************" << endl;
	}
}