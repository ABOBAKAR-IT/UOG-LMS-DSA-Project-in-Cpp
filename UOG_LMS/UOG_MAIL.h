#pragma once
struct mail_data
{
	char sender_id[20], reciver_id[20];
	char massage[100];
	mail_data* next;
};
class UOG_MAIL
{
	mail_data* head, * tail, * temp, * t,*top;

	

	void write_mail_data(mail_data* d);
	void send_mail(char* id);
	void inbox_mail(char* id);
	void SEND_MAIL_TO_AN_OTHER(char* sid);
	void show_mail(mail_data* p);
	void stack();
public:
	int uog_mail_system(char* sid);
};

