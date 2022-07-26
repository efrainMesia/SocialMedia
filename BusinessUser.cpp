#pragma once
#include "BusinessUser.h"
#include "USocial.h"
BusinessUser::BusinessUser() :User()
{
}

BusinessUser::BusinessUser(User* originUser) :User(originUser)
{
}

/*
* Override the function sendMessage from User.
* as a businessUser you can send a message to anyone on Usocial
*/
void BusinessUser::sendMessage (User* user, Message* message) 
{
	if (user == NULL) {
		throw std::invalid_argument("Your were trying to add someone that was remove or doesnt exist");
	}
	if (_us->getUserById(user->getId()) == NULL) {
		throw std::invalid_argument("Your friend was removed from UC- cant send a Message");
	}
	else {
		user->receiveMessage(message);
	}
}
