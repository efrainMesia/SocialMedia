#pragma once
#include <iostream>
#include "Media.h"
#include "Video.h"
#include "Audio.h"
#include "Photo.h"
using namespace std;

class Post {
private:
	string _text;
	Media* _media;

public:
	Post(string);
	Post(string,Media*);
	void post(string);
	void post(string, Media*);
	string getText();
	Media* getMedia();
};