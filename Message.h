#pragma once
#include <iostream>
using namespace std;
class Message {

private:
	string _text;

public:
	Message(string);
	string getText();
};