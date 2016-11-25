/*
UFRGS – Instituto de Informática
INF01120 Técnicas de Construção de Programas

3ª Fase Trabalho Prático
Ana Paula Mello
Caio Fonseca
Guilherme Cattani de Castro

2016/2 - Turma B

Professor: Marcelo Soares Pimenta
*/

#include "stdafx.h"
#include "Music.h"
#include "CFugueLib.h"
#include <iostream>

#pragma region Constructors & Destructors
Music::Music()
{
}


Music::~Music()
{
}
#pragma endregion 

#pragma region Functions
void Music::saveMusic(std::string character, const CString pathName)
{
	CFugue::Player player;

	//CT2A Macro
	CT2A ascii(pathName);

	player.SaveAsMidiFile(CFugue::MString(character.c_str()), ascii.m_psz);
}

void Music::playMusic(std::string character)
{

	//Crazy conversion from std::string to const TCHAR* format that CFugue will understand
	const char* musicCharArray = character.c_str();
	size_t size = strlen(musicCharArray) + 1;
	wchar_t *musicTCharArray = new wchar_t[size];
	size_t newSize;
	mbstowcs_s(&newSize, musicTCharArray, size, musicCharArray, size - 1);

	CFugue::PlayMusicStringWithOpts(musicTCharArray, MIDI_MAPPER, 20);

	delete[]musicTCharArray;

}
#pragma endregion 