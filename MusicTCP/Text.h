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
#include "Music.h"

#pragma once
class Text
{
public:
	Text();
	~Text();

	std::string convertCharacter(std::string text);

private:
	std::string text;
};

