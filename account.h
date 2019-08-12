#ifndef ACCOUNT_H
#define ACCOUNT_H
#include"md5_encode.h"
#include<cstring>
#include"wordlist.h"
#include<iostream>
#include<fstream>
#include<vector>
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
	WordList_daily wl_daily;//��������ʻ��
	Account_running(Account);
	~Account_running();
	void setpassword(string);//�޸�����
	void setgoal(int);//����ÿ��Ŀ��
	int known_t();//�ѻᵥ�ʹ���
	int learning_t();//����ѧ����
	int word_goal();//Ŀ�굥��
	int word_rest();//ʣ�൥��
	int word_new();//�´ʸ���
	bool complete();//���մ����
	int complete_t();//������ͳ��
};

class AccountManageSystem 
{
public:
	static Account_running* ar;//�������е��û�
	static vector<Account> account_list;//�û���
	AccountManageSystem();
	~AccountManageSystem();
	bool sign_in(char,string);//��֤����
	void new_account(string,string);
	string showname(char);
};

#endif // !ACCOUNT_H
