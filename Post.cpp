#include "Post.h"

Post::Post()
{
	_text = "";
	_media = nullptr;
}

//Post new post with only text
void Post::post(string text)
{
	if (isEmptyText(text)) {
		throw std::invalid_argument("Post's text cannot be empty, add text or add media");
	}
	else {
		_text = text;
	}
}

//Post new post with text and media
void Post::post(string text, Media* media)
{
	_text = text;
	if (media == NULL) {
		throw std::invalid_argument("Media not initialized ");
	}
	else {
		_media = media;
	}

}

string Post::getText()
{
	return _text;
}

Media* Post::getMedia()
{
	return _media;
}

//Check if the Input text is empty
bool Post::isEmptyText(string text)
{
	if (text.find_first_not_of(' ') != std::string::npos) {
			return false;
	}
	return true;	
}


std::ostream& operator<<(std::ostream& os, Post&  post)
{
	os << post.getText();
	os << " Media: ";
	Media* m = post.getMedia();
	if (m != NULL) {
		m->display();
	}
	else {
		os << "No Media";
	}
	return os;
}

Post::~Post() {
	delete _media;
}