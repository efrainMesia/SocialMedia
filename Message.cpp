#include "Message.h"

//Construtor
Message::Message(string text)
{
	if (isEmptyMessage(text)) {
		throw std::invalid_argument("Message cannot be empty");
	}
	_text = text;
}

string Message::getText()
{
	return _text;
}

/*
	checks if the text message which is wanted to send is empty
*/
bool Message::isEmptyMessage(std::string text)
{
	if (text.find_first_not_of(' ') != std::string::npos) {
			return false;
		}
	return true;
}

Message::~Message()
{
}

