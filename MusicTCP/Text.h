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

#include <string>
#include "Music.h"

#pragma once
class Text
{
public:
	Text();
	~Text();

	Music music;

	void playText(std::string text);
	std::string readFile();

private:
	std::string text;
};

