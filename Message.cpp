#include "Message.h"

//Construtor
Message::Message(string text)
{
	_text = text;
}

string Message::getText()
{
	return _text;
}
