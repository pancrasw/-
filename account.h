#ifndef ACCOUNT_H
#define ACCOUNT_H
#include"md5_encode.h"
#include<cstring>
#include"wordlist.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<cstdio>
#define ACCOUNT_WORD 4
#define ACCOUNT_NAME 21
//@author:��
using std::vector;
using std::string;

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
	short go = 50;//ÿ��Ŀ��
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
	int	 known_t();//�ѻᵥ�ʹ���
	void create_daily_wordlist();
	int  learning_t();//����ѧ����
	int  word_goal();//Ŀ�굥��
	int  word_rest();//ʣ�൥��
	int  word_new();//�´ʸ���
	bool complete();//��
	bool iscomplete();//���մ����
	int  complete_t();//������ͳ��
	void add_new_word(short);//��ӵ������û�Ŀ�굥��
	void save();	
	void read_dl();
	void save_dl();
private:
	
	friend class AccountManageSystem;
};

class AccountManageSystem 
{
public:
	static Account_running* ar;//�������е��û�
	static vector<Account> account_list;//�û���
	static string path;//�����ļ���·��
	static void           init();
	static void           save();
	static bool           sign_in(char,string);//��֤����
	static bool           new_account(string,string);
	static string         showname(char);
	static bool           sign_out();                                        //�ǳ�
	static bool           sign_in(std::string account, std::string password);//��¼
	static bool           delete_current_account();                          //ɾ����ǰ�û�
	static string         get_current_user_name();                           //��ȡ��ǰ�û�����
	static vector<string> get_all_users_name();//��ȡ�����û�����
	static bool           setpassword(string);
	static bool           setgoal(short); 
	static bool           end();
private:
	static bool           delete_account(char);
	static char           getindex(char);
};

#endif // !ACCOUNT_H