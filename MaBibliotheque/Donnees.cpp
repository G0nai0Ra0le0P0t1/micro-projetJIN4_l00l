#include "stdafx.h"
#include "Donnees.h"
#include <string.h>
#include <cstdlib>
#include <iostream>

Donnees::Donnees()
{
}

Donnees::~Donnees()
{
}
// 4 position possible :
// 50-50, 200-50, 300-50 et 200-200
Donnees::Donnees(int i, std::string str) {
	switch (i) {
	case 1 :
		donnee = str;
		positionX = 50;
		positionY = 50;
		break;
	case 2:
		donnee = str;
		positionX = 200;
		positionY = 50;
		break;
	case 3:
		donnee = str;
		positionX = 300;
		positionY = 50;
		break;
	case 4:
		donnee = str;
		positionX = 200;
		positionY = 200;
		break;
	}
}


std::string Donnees::getdonnee() {
	return donnee;
}

void Donnees::setdonnee(std::string str) {
	donnee = str;
}

int Donnees::getpositionX() {
	return positionX;
}

int Donnees::getpositionY() {
	return positionY;
}
