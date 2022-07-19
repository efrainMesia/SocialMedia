#pragma once
#include <iostream>
#include <map>
#include "User.h"
using namespace std;

class USocial {

private:
	map <unsigned long, User*> _users;
	unsigned long _id;

public:
	USocial();
	User* registerUser(string, bool);
	void removeUser(User*);
	User* getUserById(unsigned long);
};
