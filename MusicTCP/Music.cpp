#include "stdafx.h"
#include "Music.h"
#include "CFugueLib.h"
#include <iostream>


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
	char previousChar;
	bool previousCharWasNote = false;
	bool instrumentChanged = false;

	for (i = 0; i < text.size(); i++) {

		switch (text[i]) {
			//If it's instruments
			//		Figure out a better way to append this part to the music string
		case '!':
			instrument = 6; //Harpischord
			previousCharWasNote = false;
			instrumentChanged = true;
			break;
		case '\n':
			instrument = 14; //Tubular bells
			previousCharWasNote = false;
			instrumentChanged = true;
			break;
		case ';':
			instrument = 75; //Pan flute
			previousCharWasNote = false;
			instrumentChanged = true;
			break;
		case ',':
			instrument = 19; //Church organ
			previousCharWasNote = false;
			instrumentChanged = true;
			break;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			instrument = instrument + text[i];
			if (instrument > 127)
				instrument -= 127;
			previousCharWasNote = false;
			instrumentChanged = true;
			break;
		//If it's octave changes	
		case '?':
		case '.':
			octave++;
			if (octave > 10)
				octave = 5;
			previousCharWasNote = false;
			break;
		//If it's note
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
			musicString = musicString + text[i] + "[" + std::to_string(octave) + "] ";
			previousCharWasNote = true;
			previousChar = text[i];
			break;
		//Special cases
		default:
			if (previousCharWasNote) {
				musicString = musicString + previousChar + "[" + std::to_string(octave) + "] ";
			}
			else {
				musicString = musicString + text[i];
			}
			previousCharWasNote = false;
			break;
		}

		if (instrumentChanged) {
			musicString = musicString + "I[" + std::to_string(instrument) + "] ";
			instrumentChanged = false;
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
	//playMusic(_T("C R D"));

	delete[]musicTCharArray;
}

void Music::saveMusic(const CString character, const CString pathName)
{
	CFugue::Player player;

	//CT2A Macro
	CT2A ascii(pathName);

	player.SaveAsMidiFile(CFugue::MString(character), ascii.m_psz);
}

void Music::playMusic(const TCHAR * character)
{
	CFugue::PlayMusicStringWithOpts(character, MIDI_MAPPER, 20);
}
