#pragma once
#include "USocial.h"
#include "BusinessUser.h"

USocial::USocial()
{
	_users = map<unsigned long, User*>();
	_counterId = 1;
}

/*	Registers user, the businessUser parameter is default as false
	Creates a pointer of User and according to parameter businessUser
	it creates a businessUser or normal User.
	Since USocial is friend of class User, then Usocial is allowed to change/use private/protected functions/attributes
*/
User* USocial::registerUser(string username, bool businessUser )
{
	User* newUser;
	if (isEmptyUserName(username) == true) {
		throw std::invalid_argument("Name cant be empty");
	}
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
	delete user;
}

User* USocial::getUserById(unsigned long lookUpId)
{
	auto it = _users.find(lookUpId);
	if (it == _users.end()) {
		return NULL;
	}
	else {
		return it->second;
	}
}

USocial::~USocial()
{
	for (auto it : _users) {
		delete it.second;
	}
}


bool USocial::isEmptyUserName(std::string name) {
	if (name.find_first_not_of(' ') != std::string::npos) {
		return false;
	}
	return true;
}