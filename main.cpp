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


	if (AccountManageSystem::sign_out())
	{
		std::cout << "User " << AccountManageSystem::get_current_user_name() << " logout" << std::endl;
	}
	else
	{
		std::cout << "User " << AccountManageSystem::get_current_user_name() << " logout failed" << std::endl;
	}


	auto users_name = AccountManageSystem::get_all_users_name();

	for (auto i : users_name)
		std::cout << i << std::endl;
	AccountManageSystem::end();
}