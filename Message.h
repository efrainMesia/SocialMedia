#pragma once
#include <iostream>
using namespace std;
class Message {

private:
	string _text;

public:
	string getText();
	bool isEmptyMessage(std::string);
	//constructor
	Message(string);
	//dtor
	~Message();
};
