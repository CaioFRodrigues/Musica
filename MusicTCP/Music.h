#include <string>
#include "CFugueLib.h"
#include "stdafx.h"

#pragma once
class Music
{
public:
	Music();
	~Music();

	std::string convertCharacter(std::string text);
	void Music::saveMusic(std::string character, const CString pathName);
	void playMusic(std::string character);

private:
	int bpm;
	int volume;
	std::string instrument;
	int currentOctave;
};