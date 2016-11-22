#include <string>

#pragma once
class Music
{
public:
	Music();
	~Music();

	void convertCharacter(char character);
	void saveMusic(char* text);

private:
	int bpm;
	std::string instrument;
	int currentOctave;
};

