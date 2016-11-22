#include <string>
#include "Music.h"

#pragma once
class Text
{
public:
	Text();
	~Text();

	Music music;

	void playText(std::string text);
	std::string readFile();

private:
	std::string text;
};

