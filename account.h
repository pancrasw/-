#ifndef ACCOUNT_H
#define ACCOUNT_H
#include"md5_encode.h"
#include<cstring>
#include"wordlist.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<cstdio>
#define WORD 4
#define NAME 21
//@author:��
using std::vector;
class Account
{
public:
	Account() {};
	~Account();
protected:
	char vid;//���к�
	string na;//���֣��޶��ַ���
	string md5;//����md5
	static Md5Encode encode_obj;//md5������
	Account(char, string, string);
protected:
	short go;//ÿ��Ŀ��
	friend class AccountManageSystem;
};

class Account_running :public Account//����ʱ���û�
{
public:
	WordList wl_done;//�ѱ��Ĵʻ��
	vector<Wordnode>** wv_undone;//δ���Ĵʻ��
	WordList wl_new;//�µ���
	WordList_daily wl_daily;//��������ʻ��
	Slist<Date> date_list;//������
	Account_running(Account);
	~Account_running();
	void setpassword(string);//�޸�����
	void setgoal(int);//����ÿ��Ŀ��
	int known_t();//�ѻᵥ�ʹ���
	void create_daily_wordlist();
	int learning_t();//����ѧ����
	int word_goal();//Ŀ�굥��
	int word_rest();//ʣ�൥��
	int word_new();//�´ʸ���
	void complete();//��
	bool iscomplete();//���մ����
	int complete_t();//������ͳ��
};

class AccountManageSystem 
{
public:
	static Account_running* ar;//�������е��û�
	static vector<Account> account_list;//�û���
	static string path;//�����ļ���·��
	AccountManageSystem();
	~AccountManageSystem();
	bool sign_in(char,string);//��֤����
	bool new_account(string,string);
	void delete_account(char);
	string showname(char);
private:
	char getindex(char);
};

#endif // !ACCOUNT_H
