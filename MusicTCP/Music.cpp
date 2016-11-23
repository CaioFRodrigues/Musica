#include "stdafx.h"
#include "Music.h"
#include "CFugueLib.h"


Music::Music()
{
}


Music::~Music()
{
}



void Music::convertCharacter()
{
}

void Music::saveMusic(char * text)
{
}

void Music::playMusic(const TCHAR * character)
{
	CFugue::PlayMusicStringWithOpts(character, MIDI_MAPPER, 20);
}
