#pragma once

#include "Obj.h"
class Objet : 
	public Obj
{
public:
	Objet();
	~Objet();
	Objet(int posX, int posY, int len, int height, char* color);
	Objet(int posX, int posY, int len, int height);
	
	void defilement(int vitesse);
	void d�placementHaut();
	void d�placementBas();

private:
	int positionX;
	int positionY;
	int longueur;
	int largeur;
	char* couleur;
};

