#ifndef DATE_H
#define DATE_H
//author:��
#include<time.h>
#include"slist.h"
#define DAY 86400

class Date 
{
public:
	Date(short da = 0) :date(da) {};
	void set_date();//ȡ����ʱ����Ϊ����
	char* get_date();//��ʽ��"YYYY-MM-DD"
	bool istoday();
	short get_short();
private:
	short date = 0;//���������ڣ�����������ʱ���ʱ���
	//char* get_date_now();
	//char* get_time_now();
};

class DateList:public Slist<Date>
{
	
};

#endif // !DATE_H
