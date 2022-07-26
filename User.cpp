#pragma once
#include "User.h"
#include "USocial.h"

/*
	Empty Constructor
*/
User::User(){
	_name = "";
	_id = 0;
	_us = nullptr;
}

/*
	Copy constructor
*/
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

unsigned long User::getId()
{
	return _id;
}

string User::getName()
{
	return _name;
}

/*
	Do some check before, if the friend whos wanted to be added its empty, or we want to add ourself or
	if we want to add someone that is already our friend.
*/
void User::addFriend(User* newFriend)
{
	if (newFriend == NULL) {
		throw std::invalid_argument("Your were trying to add someone that was remove or doesnt exist");
	}
	else if (this == newFriend) {
		throw std::invalid_argument("you cant add yourself as a friend");
	}
	else if (isFriend(newFriend)) {
		throw std::invalid_argument("This friend already in List");
	}
	else {
		_friends.push_back(newFriend->getId());
	}
}


/*
* Checks if the user we want its null(exist or not) also checks the user we want to remove is our friend.
*/
void User::removeFriend(User* remFriend)
{
	if (remFriend == NULL) {
		throw std::invalid_argument("Cant remove because user removed from US");
	}
	if (isFriend(remFriend)){
		_friends.remove(remFriend->getId());
	}
	else {
		throw std::invalid_argument("Cannot remove because he is not in your friend list");
	}
}

/*
* create new empty post, and then use the function post from Class Post.
* In Post, the function post can throw an exception if the post text is empty. part of the function is wrapped in try/catch
* and the exception is throwed to the main
*/
void User::post(string text)
{
	Post* post = new Post();
	try {
		post->post(text);
	}
	catch (const std::exception&) {
		throw;
	}
	_posts.push_back(post);

}

/*
* create new empty post, and then use the function post from Class Post.
* In Post, the function post can throw an exception if the post Media is NULL. part of the function is wrapped in try/catch
* and the exception is throwed to the main
*/
void User::post(string text, Media* media)
{
	Post* post = new Post();
	try {
		post->post(text, media);
	}
	catch (const std::exception&) {
		throw;
	}
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

/*
* Sends a message to the another user which is friends with.
* Does some checks before sending the message.
* if the user exists, also if its friends with the user we want to send the message.
* if we are friends we send otherwise we throw an exception
*/
void User::sendMessage(User* user, Message* message)
{
	if (user == NULL) {
		throw std::invalid_argument("Your were trying to add someone that was remove or doesnt exist");
	}
	else if (isFriend(user)) {
		user->receiveMessage(message);
	}
	else {
		throw std::invalid_argument("You can only send a Message to a friend");
	}

}

//prints all the received messages
void User::viewReceivedMessages()
{
	if (_receivedMsgs.empty())
	{
		std::cout << "Your inbox is empty" << std::endl;
	}
	else {
		std::cout << _name << " is reading received messages: " << std::endl;
		for (auto message : _receivedMsgs) {
			cout << message->getText() << endl;
		}
		std::cout << "_____end of inbox______" << std::endl;
	}
}

//prints all the friends post
void User::viewFriendsPosts()
{
	if (_friends.empty()) {
		std::cout << "Hi " << _name << " ,you havent added any friend yet so no posts to view" << std::endl;
	}
	else {
		std::cout << _name << " is reading friends posts:" << std::endl;
		for (auto friendUser : _friends)
		{
			//gets the User from USocial
			User* f = _us->getUserById(friendUser);		

			//iterates over the Post of the friend we found
			for (auto post : f->getPosts()) {						
				std::cout << f->getName() << "'s post:";
				std::cout << *post << std::endl; 
			}
		}
		std::cout << "_____end of friends posts______" << std::endl;
	}
}

//checks if the user is friends with another user
bool User::isFriend(User* userFriend) {
	for (auto i = _friends.begin(); i != _friends.end(); i++) {
		if (*i == userFriend->getId()) {
			return true;
		}
	}
	return false;
}


User::~User() {
	//deep destructor
	for (auto post : _posts) {
		delete post;
	}
	_posts.clear();
	//deep destructor
	for (auto message : _receivedMsgs) {
		delete message;
	}
	_receivedMsgs.clear();
	_friends.clear();
	_id = 0;
	_name = "";
}

std::ostream& operator<<(std::ostream& os, User& user)
{
	os << "Username: ";
	os << user.getName() << endl;
	os << "ID: ";
	os << user.getId() << endl;
	return os;
}


