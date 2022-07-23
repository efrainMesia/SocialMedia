#pragma once
#include "User.h"
#include "USocial.h"
User::User(){
}
User::User(User* originUser)
{
	_name = originUser->_name;
	_id = originUser->_id;
	_us = originUser->_us;

	//deep copy of friends
	for (auto copyFriend : originUser->_friends) {
		_friends.push_back(copyFriend);
	}

	//deep copy of Posts
	for (auto copyPosts : originUser->_posts) {
		_posts.push_back(copyPosts);
	}
	//deep copy of Messages
	for (auto copyMessages : originUser->_receivedMsgs) {
		_receivedMsgs.push_back(copyMessages);
	}
}
;

unsigned long User::getId()
{
	return _id;
}

string User::getName()
{
	return _name;
}

void User::addFriend(User* newFriend)
{
	_friends.push_back(newFriend->getId());
}

void User::removeFriend(User* remFriend)
{
	_friends.remove(remFriend->getId());
}

void User::post(string text)
{
	Post* post = new Post(text);
	_posts.push_back(post);

}

void User::post(string text, Media* media)
{
	Post* post = new Post(text, media);
	_posts.push_back(post);
}

list<Post*> User::getPosts()
{
	return _posts;
}

void User::receiveMessage(Message* message)
{
	_receivedMsgs.push_back(message);
}

void User::sendMessage(User* user, Message* message)
{
	if (isFriend(user)) {
		cout << "Sending message to " << user->getName() << " " << endl;
		user->receiveMessage(message);
	}
	cout << "Sorry *" << _name <<"* you arent friend with " << user->getName() << " " << endl;

}

void User::viewReceivedMessages()
{
	std::cout << _name << "'s Messages: " << std::endl;
	for (auto message: _receivedMsgs) {
		cout << message->getText() << endl;
	}
}

void User::viewFriendsPosts()
{
	for (auto friendUser : _friends) {
		User* f = _us->getUserById(friendUser);
		std::cout << *f;
		for (auto post : f->getPosts()) {
			std::cout << *post << std::endl;
		}
	}
}

bool User::isFriend(User* userFriend) {
	for (auto i = _friends.begin(); i != _friends.end(); i++) {
		if (*i == userFriend->getId()) {
			return true;
		}
	}
	return false;
}


User::~User() {
	for (auto post : _posts) {
		delete post;
	}
	_posts.clear();

	for (auto message : _receivedMsgs) {
		delete message;
	}
	_receivedMsgs.clear();

	_friends.clear();
}

std::ostream& operator<<(std::ostream& os, User& user)
{
	os << "Username: ";
	os << user.getName() << endl;
	os << "ID: ";
	os << user.getId() << endl;
	return os;
}


