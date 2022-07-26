#pragma once
#include <iostream>
#include <list>
#include <iterator>
#include "Post.h"
#include "Message.h"

class User {
	//allowing to Usocial to get access to private/protected functions/attribs.
	friend class USocial;
protected:
	USocial* _us;
	unsigned long _id;
	string _name;
	list<unsigned long> _friends;
	list<Post*> _posts;
	list<Message*> _receivedMsgs;
	//constructor
	User();
	User(User*);
	//deep dtor
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
	virtual void sendMessage(User*, Message*);
	void viewReceivedMessages();
	void viewFriendsPosts();
	bool isFriend(User*);
	friend std::ostream& operator<<(std::ostream& os, User& user);
};