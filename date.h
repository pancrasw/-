#ifndef DATE_H
#define DATE_H
//author:��
#include<time.h>
#include"slist.h"
#define DAY 86400

struct Date_concrete 
{
	short year;
	short month;
	short day;
};

class Date 
{
public:
	Date(short da = 0) :date(da) {};
	void set_date();//ȡ����ʱ����Ϊ����
	string get_date();//��ʽ��"YYYY-MM-DD"
	Date_concrete get_date_concrete();
	bool istoday();
	short get_short();
private:
	short date = 0;//���������ڣ�����������ʱ���ʱ���
	//char* get_date_now();
	//char* get_time_now();
};

#endif // !DATE_H
