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

#include <string>
#include "CFugueLib.h"
#include "stdafx.h"

#pragma once
class Music
{
public:
	Music();
	~Music();
	void Music::saveMusic(std::string character, const CString pathName);
	void playMusic(std::string character);

private:
	int bpm;
	int volume;
	std::string instrument;
	int currentOctave;
};