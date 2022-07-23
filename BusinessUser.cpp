#pragma once
#include "BusinessUser.h"
#include "USocial.h"
BusinessUser::BusinessUser() :User()
{
}

BusinessUser::BusinessUser(User* originUser) :User(originUser)
{
}


void BusinessUser::sendMessage (User* user, Message* message)
{
	if (_us->getUserById(user->getId()) == NULL) {
		throw std::invalid_argument("Your friend was removed from UC- cant send a Message");
	}
	else {
		user->receiveMessage(message);
	}
}
