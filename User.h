#pragma once
#include "Post.h"
#include "Message.h"
#include <iostream>
#include <list>
#include <iterator>
#include "USocial.h"
using namespace std;


class User {
protected:
	USocial* us;
	unsigned long id;
	string name;
	list<unsigned long> friends;
	list<Post*> posts;
	list<Message*> receivedMsgs;

	User();
	~User();

public:
	unsigned long getId();
	string getName();
	void addFriend(User*);
	void removeFriend(User*);
	void post(string);
	void post(string, Media*);
	list<Post*> getPosts();
	void receiveMessage(Message*);
	void sendMessage(User*, Message*);
	void viewReceivedMessages();

};