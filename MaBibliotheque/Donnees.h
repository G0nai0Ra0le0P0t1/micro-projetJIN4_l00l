#pragma once

#include <string.h>
#include <cstdlib>
#include <iostream>
class Donnees 
{
public:
	Donnees();
	~Donnees();

	Donnees(int i, std::string str);

	std::string getdonnee();

	void setdonnee(std::string str);

	int getpositionX();

	int getpositionY();

	std::string donnee;
	int positionX;
	int positionY;
	int calcul;
};

