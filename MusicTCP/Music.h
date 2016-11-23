#include <string>
#include "CFugueLib.h"
#include "stdafx.h"

#pragma once
class Music
{
public:
	Music();
	~Music();

	void convertCharacter(std::string text);
	void saveMusic(char* text);
	void playMusic(const TCHAR* character);

private:
	int bpm;
	std::string instrument;
	int currentOctave;
};

