#include "stdafx.h"
#include "Music.h"
#include "CFugueLib.h"


Music::Music()
{
}


Music::~Music()
{
}



void Music::convertCharacter(std::string text)
{
	size_t i = 0;
	std::string musicString;

	int octave = 5;	//Default octave
	int instrument = 0;	//Default instrument (piano)
	char* note;

	for (i = 0; i < text.size(); i++) {

		if (text[i] == '!') {
			instrument = 6; //Harpischord
			musicString.append(" I[").append(std::to_string(octave)).append("] ");
		}
			
		if (text[i] == '?') {
			octave++;
		}

		if (text[i] == 'A') {
			note = "A";
			musicString.append(note).append("[").append(std::to_string(octave)).append("]");
		}


			
	}

	//Crazy conversion from std::string to const TCHAR* format that CFugue will understand
	// TODO: Turn this into its own conversion function (end result must be musicTCharArray)
	const char* musicCharArray = musicString.c_str();
	size_t size = strlen(musicCharArray) + 1;
	wchar_t *musicTCharArray = new wchar_t[size];
	size_t newSize;
	mbstowcs_s(&newSize, musicTCharArray, size, musicCharArray, size - 1);
	playMusic(musicTCharArray);

	delete[]musicTCharArray;
}

void Music::saveMusic(char * text)
{
}

void Music::playMusic(const TCHAR * character)
{
	CFugue::PlayMusicStringWithOpts(character, MIDI_MAPPER, 20);
}
