#ifndef WORDLIST_H
#define WORDLIST_H
#include<string>
#include"slist.h"
#include"date.h"
//@author:��

struct Wordnode 
{
	short id;//�������к�
	enum {wrong,undone,right,done };
	enum {none,first,second,third,fourth,fifth};
	char st=undone;//����״̬
	char ti = none;//���Ĵ���
	Date da;//����
	Wordnode() {};
	Wordnode(short wid, char state, char time, Date date) :
		id(wid),
		st(state),
		ti(time),
		da(date)
	{}
};

class WordList :public Slist<Wordnode>
{
public:
	WordList();
	~WordList();
	void addword(short,char,char,short);//��ӵ���
	void addword(Wordnode);
	Wordnode pop();//��ȡ���ʱ��е�һ������
	int count_total();
	int count_undone();
	int count_done();
	int count_wrong();
	int count_right();
protected:
	int undone_t=0;//���컹û��ʼ����
	int done_t = 0;//�Ѿ������˵�
	int wrong_t = 0;//�����˵�
	int right_t = 0;//������ֻ������һ�ε�
private://���õĺ���
	void plusmerge() {};
	void show() {};
	void operator+() {};
};

class WordList_daily:public WordList
{
public:
	void check(bool);
	Date da;
private:
	void put_tail();//�����ʷŵ�ĩβ
};

#endif