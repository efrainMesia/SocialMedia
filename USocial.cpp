#pragma once
#include "USocial.h"
#include "BusinessUser.h"
using namespace std;

USocial::USocial()
{
	_users = map<unsigned long, User*>();
	_counterId = 1;
}

User* USocial::registerUser(string username, bool businessUser )
{
	User* newUser;

	if (businessUser == true){
		newUser = new BusinessUser();
	}
	else {
		newUser = new User();
	}

	newUser->_name = username;
	newUser->_id = _counterId;
	newUser->_us = this;

	_users.insert(pair<unsigned long, User*>(_counterId++,newUser));
	
	return newUser;
}
//Remove user from MAP and also from friends in each user
void USocial::removeUser(User* user)
{
	User* userFound = getUserById(user->getId());
	//User exists in MAP
	if (userFound != NULL){

		//from user's friends list
		for (auto it = _users.begin(); it != _users.end(); it++)
		{
			if ((*it->second).isFriend(user)) //it->first (Checking if its friend..)
			{
				cout << "Removing " << user->getName() << " from " << it->second->getName() << " friends" << endl;
				(*it->second).removeFriend(user);
			}
		}
	}
	_users.erase(user->getId());
	_counterId--;
}

User* USocial::getUserById(unsigned long lookUpId)
{
	auto it = _users.find(lookUpId);
	if (it == _users.end()) {
		cout << "ID: " << lookUpId << " doesn't exist" << endl;
		return NULL;
	}
	else {
		return it->second;
	}
}
