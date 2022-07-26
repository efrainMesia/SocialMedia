#pragma once
#include <map>
#include <iostream>
class User;

class USocial{
private:
	std::map <unsigned long, User* > _users;

public:
	unsigned long _counterId;
	USocial();
	User* registerUser(std::string username , bool businessUser = false);
	void removeUser(User*);
	bool isEmptyUserName(std::string);

	User* getUserById(unsigned long);
	~USocial();
};
