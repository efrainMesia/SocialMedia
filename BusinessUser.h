#pragma once
#include <iostream>
#include "User.h"



class BusinessUser :public User 
{
public:
	BusinessUser();
	BusinessUser(User*);
	void sendMessage (User*, Message*) override;
};