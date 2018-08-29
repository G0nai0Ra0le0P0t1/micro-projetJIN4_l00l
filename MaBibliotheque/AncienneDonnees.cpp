#include "stdafx.h"
#include "AncienneDonnees.h"


AncienneDonnees::AncienneDonnees()
{
}


AncienneDonnees::~AncienneDonnees()
{
}


AncienneDonnees::AncienneDonnees(int i, std::string str) {
	switch (i) {
	case 1:
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


std::string AncienneDonnees::getdonnee() {
	return donnee;
}

void AncienneDonnees::setdonnee(std::string str) {
	donnee = str;
}

int AncienneDonnees::getpositionX() {
	return positionX;
}

int AncienneDonnees::getpositionY() {
	return positionY;
}
