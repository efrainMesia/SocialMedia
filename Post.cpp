#include "Post.h"

Post::Post(string text)
{
	_text = text;
}

//Contructor
Post::Post(string text , Media* media)
{
	_text = text;
	_media = media;
}

//Post new post with only text
void Post::post(string text)
{
	_text = text;
}

//Post new post with text and media
void Post::post(string text, Media* media)
{
	_text = text;
	_media = media;
}

string Post::getText()
{
	return _text;
}

Media* Post::getMedia()
{
	return _media;
}


std::ostream& operator<<(std::ostream& os, Post&  post)
{
	os << post.getText();
	os << "Media: ";
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