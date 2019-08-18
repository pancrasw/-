//#define _CRT_SECURE_NO_WARNINGS
#include"head_file.h"
using std::cout;


int main()
{

	AccountManageSystem::init();
	AccountManageSystem::new_account("wpx", "1234567");
	AccountManageSystem::new_account("wqh", "1234567");



	if (AccountManageSystem::sign_in("wpx", "1234567"))
	{
		std::cout << "User " << AccountManageSystem::get_current_user_name() << " login" << std::endl;
	}
	else
	{
		std::cout << "User login failed" << std::endl;
	}

	AccountManageSystem::ar->add_new_word(0);
	AccountManageSystem::ar->add_new_word(1);
	cout << AccountManageSystem::ar->wl_new.count_total();
	AccountManageSystem::ar->create_daily_wordlist();
	cout << AccountManageSystem::ar->wl_new.count_total();
	cout << AccountManageSystem::ar->wl_daily.count_total();
	cout << AccountManageSystem::ar->wl_daily.count_new() << endl;
	Wordnode a = AccountManageSystem::ar->wl_daily.pop();
	cout << a.id << endl << char(a.st + '0') << endl << char(a.ti + '0') << endl;
	AccountManageSystem::ar->wl_daily.check(false);
	a = AccountManageSystem::ar->wl_daily.pop();
	cout << a.id << endl << char(a.st + '0') << endl << char(a.ti + '0') << endl;
	AccountManageSystem::ar->wl_daily.check(true);
	a = AccountManageSystem::ar->wl_daily.pop();
	cout << a.id << endl << char(a.st + '0') << endl << char(a.ti + '0') << endl;
	AccountManageSystem::sign_out();
	AccountManageSystem::end();
}