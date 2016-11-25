/*
UFRGS � Instituto de Inform�tica
INF01120 T�cnicas de Constru��o de Programas

3� Fase Trabalho Pr�tico
Ana Paula Mello
Caio Fonseca
Guilherme Cattani de Castro

2016/2 - Turma B

Professor: Marcelo Soares Pimenta
*/

#include "stdafx.h"
#include "Text.h"
#include <string>
#include "Music.h"

#pragma region Constructors & Destructors
Text::Text()
{
}

Text::~Text()
{
}
#pragma endregion

#pragma region Functions
std::string Text::convertCharacter(std::string text)
{
	size_t i = 0;
	std::string musicString;

	int octave = 5;	//Default octave
	int volume = 70; //Default volume
	int instrument = 0;	//Default instrument (piano)
	char previousChar;
	bool previousCharWasNote = false;
	bool instrumentChanged = false;
	bool volumeChanged = false;

	musicString += "X[VOLUME_COARSE]=" + std::to_string(volume) + " ";
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
			//If it's volume changes	
		case 'I':
		case 'i':
		case 'U':
		case 'u':
			volume += int(volume*0.1);
			previousCharWasNote = false;
			volumeChanged = true;
			break;
			//Special case spacebar
		case ' ':
			volume = volume * 2;
			previousCharWasNote = false;
			volumeChanged = true;
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
		if (volumeChanged) {
			if (volume > 120)
				volume = 120;
			musicString += "X[VOLUME_COARSE]=" + std::to_string(volume) + " ";
			volumeChanged = false;
		}
	}

	return musicString;
}

#pragma endregion