#pragma once
#include "BusinessUser.h"

BusinessUser::BusinessUser() :User()
{
}

BusinessUser::BusinessUser(User* originUser) :User(originUser)
{
}


void BusinessUser::sendMessage (User* user, Message* message)
{
	user->receiveMessage(message);
}
