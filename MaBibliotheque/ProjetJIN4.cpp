// ProjetJIN4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Perso.h"
#include "Murs.h"
#include "Donnees.h"
#include "Bonus_Malus.h"
#include "Reponse.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "monMain.h"
#include "pugixml.hpp"

//création des murs qui font obstruction
std::vector<Murs*> generateWall(int hauteurDelacarte, int hauteurduperso, int largeur, int borddroit) {
	std::vector<Murs*> vecteur;
	srand((int)time(NULL)); //initialisation du rand
	int lahauteur = rand() % (hauteurDelacarte-hauteurduperso-5); //prend entre 0 et lahauteurdelacarte-hauteurduperso
	Objet* murduhaut = new Objet(borddroit, 0, largeur, lahauteur);
	vecteur.push_back((Murs*)murduhaut);
	Objet* murdubas = new Objet(borddroit, (lahauteur+hauteurduperso+5), largeur, (hauteurDelacarte-lahauteur-hauteurduperso - 5));
	vecteur.push_back((Murs*)murdubas);
	return vecteur;
}

//défilement des murs
void défilementDesmurs(std::vector<Murs*> vecteur, int vitesse) {
	for (auto i : vecteur) {
		i->defilement(vitesse);
	}
}

//apparition des bonus/malus
void apparitionBM();



std::string removeLastCharStr(std::string str) {
	if (str.length() == 0) {
		return str;
	}
	//return (str.substr(0, str.size() - 1));
	str.pop_back();
	return (str);
	//C++ 11 only
}


//fonction qui inverse une string
void inversion(std::string& str) {

	int n = str.length();

	for (int i = 0; i < n / 2; i++){
		std::swap(str[i], str[n - i - 1]);
	}
}

/*
//fonction qui renvoie une chaine de char 0 et 1 correspondant au nombre valeur
char* turnInBinary(int nombre) {
	char* second = (char*)malloc(sizeof(char) * 15);
	int copy = nombre;
	if (nombre == 0) {
		strcpy_s(second, (sizeof(char) * 15), "0");
		return second;
	}
	while (copy != 0) {
		if (copy%2 == 1) {
			if (strlen(second) == 0) {
				strcpy_s(second, (sizeof(char) * 15), "1");
			}
			else {
				strcat_s(second, (sizeof(char) * 15), "1");
			}
			copy--;
			copy = copy / 2;
		}
		else {
			if (strlen(second) == 0) {
				strcpy_s(second, (sizeof(char) * 15), "0");
			}
			else {
				strcat_s(second, (sizeof(char) * 15), "0");
			}
			copy = copy / 2;
		}

	}
	// on inverse car le nombre est écris à l'envers
	inversion(second);
	return second;
}
*/

//fonction qui renvoie une string de char 0 et 1 correspondant au nombre valeur
std::string turnInBinaryStr(int nombre) {
	std::string second;
	int copy = nombre;
	if (nombre == 0) {
		second = second + "0";
		return second;
	}
	while (copy != 0) {
		if (copy % 2 == 1) {
			second = second + "1";
			copy--;
			copy = copy / 2;
		}
		else {
			second = second + "0";
			copy = copy / 2;
		}

	}
	// on inverse car le nombre est écris à l'envers
	inversion(second);
	return second;
}


//fonction qui renvoie un int depuis une string de 0 et 1
int turnInDec(std::string str) {
	int somme = 0;
	int valeur;
	int len = str.length();
	int coef = (int)pow((double)2, (double)(len - 1));
	char inter;
	for (int i = 0; i < len; i++) {
		inter = str.at(i);
		valeur = atoi(&inter);
		// si valeur vaut 1, on ajoute 2^len-i-1 a la somme
		if (valeur == 1) {
			somme += coef;
		}
		coef = coef / 2;
	}
	return somme;
}



//generer des calculs (vect de taille 4)
void generateCalc(std::vector<Donnees*>* genere){
	srand((int)time(NULL)); //initialisation du rand
	int premier = rand() % 255 + 1;
	srand((int)time(NULL));
	int second = (rand()*rand()) % 255 + 1;
	int calcule = rand() % 4;
	int result;
	Donnees* nouv = new Donnees(1, turnInBinaryStr(premier));
	genere->push_back(nouv);
	Donnees * nouv2;
	switch (calcule) {
	case 0:
		//calc = '+';
		nouv2 = new Donnees(2, (std::string)"+");
		result = premier + second;
		genere->push_back(nouv2);
		break;
	case 1:
		//calc = '-';
		nouv2 = new Donnees(2, (std::string)"-");
		result = premier - second;
		genere->push_back(nouv2);
		break;
	case 2:
		//calc = '*';
		nouv2 = new Donnees(2, (std::string)"x");
		result = premier * second;
		genere->push_back(nouv2);
		break;
	case 3:
		//calc = '/';
		nouv2 = new Donnees(2, (std::string)"/");
		result = premier / second;
		genere->push_back(nouv2);
		break;
	}
	//std::cout << calc;
	Donnees* nouv3 = new Donnees(3, turnInBinaryStr(second));
	genere->push_back(nouv3);
	if (result < 0) {
		result = std::abs(result);
		std::string renvoie;
		renvoie="-" + turnInBinaryStr(result);
		Donnees* nouv4 = new Donnees(4, renvoie);
		genere->push_back(nouv4);
	}
	else {
		Donnees* nouv4 = new Donnees(4, turnInBinaryStr(result));
		genere->push_back(nouv4);
	}
}


//vérification, 0 pour vraie, 1 pour faux
//first est la réponse attendu et second est la réponse donnée
//second peut etre en décimal ou en binaire

int verif(Donnees* first, Donnees* second) {
	std::string firstans = first->getdonnee();
	std::string secondans = second->getdonnee();
	if (firstans.compare(secondans)==0) {
		return 0;
	}
	int val = atoi(secondans.c_str());
	if (firstans.compare(turnInBinaryStr(val))==0) {
		return 0;
	}
	return 1;
}





int monMain() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "1001, Calculez!");
	sf::Font font;
	font.loadFromFile("../../../../Downloads/arial.ttf");
	sf::Text text1; //Donnée 0 -> calc
	sf::Text text2; //Donnée 1 -> calc
	sf::Text text3; //Donnée 2 -> calc
	sf::Text text4; //Donnée 3 -> calc
	sf::Text text5; //Donnée 4 -> point

	text1.setCharacterSize(24);
	text2.setCharacterSize(24);
	text3.setCharacterSize(24);
	text4.setCharacterSize(24);
	text5.setCharacterSize(24);


	text1.setFillColor(sf::Color::White);
	text2.setFillColor(sf::Color::White);
	text3.setFillColor(sf::Color::White);
	text4.setFillColor(sf::Color::Blue);
	text5.setFillColor(sf::Color::Red);

	text1.setFont(font);
	text2.setFont(font);
	text3.setFont(font);
	text4.setFont(font);
	text5.setFont(font);
	std::vector<int> score;
	for (int q = 0; q < 3; q++) {
		score.push_back(0);
	}
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("HallOfFame.xml");
	if (!result) {
		std::cout << "Error parsing XML file";
		return 1;
	}
	int compteur = 0;
	for (auto i = doc.child("Score"); i; i = doc.next_sibling("Score")) {
		score.at(compteur) = i.attribute("valeur").as_int();
	}
	

	//window.setVerticalSyncEnabled(true);
	std::string reponse;
	int point = 0;
	int restart = 0;
	char* temp=(char*)malloc(sizeof(char)*4);
	_itoa_s(point, temp, sizeof(char) * 4, 10);
	std::string chpoint = std::string(temp);
	std::vector<Donnees*> calc;
	generateCalc(&calc);
	Donnees* reponseactuelle = new Donnees(4, reponse);
	calc.push_back(reponseactuelle);


	text1.setPosition((float)calc.at(0)->getpositionX(), (float)calc.at(0)->getpositionY());
	text2.setPosition((float)calc.at(1)->getpositionX(), (float)calc.at(1)->getpositionY());
	text3.setPosition((float)calc.at(2)->getpositionX(), (float)calc.at(2)->getpositionY());
	text4.setPosition((float)calc.at(4)->getpositionX(), (float)calc.at(4)->getpositionY());
	text5.setPosition(500, 40);

	std::cout << "Press on a number to write it in the window." << std::endl;
	std::cout << "Press M or - on the keypad to write the '-' character in the window" << std::endl;
	std::cout << "Press 'space' to validate your answer, point are marked at the top-right of the window in red" << std::endl;
	std::cout << "Your current answer is marked at the bottom in blue" << std::endl;
	std::cout << "You can use backspace to remove the last number written." << std::endl;

	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (reponse.length() < 15) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
						// 0 key is pressed: 
						reponse+= '0';
						//std::cout << "0";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
						// 1 key is pressed: 
						reponse += '1';
						//std::cout << "1";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
						// 1 key is pressed: 
						reponse += '2';
						//std::cout << "2";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
						// 1 key is pressed: 
						reponse += '3';
						//std::cout << "3";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)){
						// 1 key is pressed: 
						reponse += '4';
						//std::cout << "4";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)){
						// 1 key is pressed: 
						reponse += '5';
						//std::cout << "5";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)){
						// 1 key is pressed: 
						reponse += '6';
						//std::cout << "6";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)){
						// 1 key is pressed: 
						reponse += '7';
						//std::cout << "7";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)){
						// 1 key is pressed: 
						reponse += '8';
						//std::cout << "8";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)){
						// 1 key is pressed: 
						reponse += '9';
						//std::cout << "9";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)){
						// 1 key is pressed: 
						reponse += '0';
						//std::cout << "0";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)){
						// 1 key is pressed: 
						reponse += '1';
						//std::cout << "1";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)){
						// 1 key is pressed: 
						reponse += '2';
						//std::cout << "2";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)){
						// 1 key is pressed: 
						reponse += '3';
						//std::cout << "3";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)){
						// 1 key is pressed: 
						reponse += '4';
						//std::cout << "4";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)){
						// 1 key is pressed: 
						reponse += '5';
						//std::cout << "5";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)){
						// 1 key is pressed: 
						reponse += '6';
						//std::cout << "6";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)){
						// 1 key is pressed: 
						reponse += '7';
						//std::cout << "7";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)){
						// 1 key is pressed: 
						reponse += '8';
						//std::cout << "8";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)){
						// 1 key is pressed: 
						reponse += '9';
						//std::cout << "9";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) {
						reponse += '-';
						//std::cout << "-";
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
						reponse += '-';
						//std::cout << "-";
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
					reponse=removeLastCharStr(reponse);
					//std::cout << "Backspace";
				}
				reponseactuelle->setdonnee(reponse);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					//std::cout << reponseactuelle->getdonnee() << std::endl;
					if (verif(calc.at(3), reponseactuelle) == 0) {
						//std::cout << reponseactuelle->getdonnee() << std::endl;
						//std::cout << calc.at(3)->getdonnee() << std::endl;
						reponse = "Bonne reponse";
						point++;
						std::cout << reponse << ": You have now" << point << "point(s) !!!" << std::endl;
						_itoa_s(point, temp, sizeof(char) * 4, 10);
						chpoint = std::string(temp);
						int compt = 0;
						while (point < score.at(compt) && compt<3) {
							compt++;
						}
						if (compt == 2) {
							score.at(compt) = point;
						}
						else if (compt == 1) {
							score.at(2) = score.at(1);
							score.at(1) = point;
						}
						else if (compt == 0) {
							score.at(2) = score.at(1);
							score.at(1) = score.at(0);
							score.at(0) = point;
						}
					}
					else {
						reponse = "You Lose!";
						std::cout << reponse << std::endl << "The correcte answer was " << calc.at(3)->getdonnee() << std::endl;
						// TODO : implémenté ici le hall of fame
						point = 0;
						_itoa_s(point, temp, sizeof(char) * 4, 10);
						chpoint = std::string(temp);
					}
					restart = 1;
					//std::cout << "Space";
				}
				if (restart == 1) {
					calc.clear();
					generateCalc(&calc);
					reponse = "";
					reponseactuelle->setdonnee("");
					calc.push_back(reponseactuelle);
					restart = 0;
				}
			}
		}
		//std::cout << calc.at(1)->getdonnee();
		text1.setString(calc.at(0)->getdonnee());
		text2.setString(calc.at(1)->getdonnee());
		text3.setString(calc.at(2)->getdonnee());
		text4.setString(reponse);
		text5.setString(chpoint);

		window.clear();
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		//window.draw(shape);
		window.display();
	}
	for (auto i = doc.child("Score"); i; i = doc.child("Score")) {
		doc.remove_child("Score");
	}
	for (int s = 0; s < 3; s++) {
		_itoa_s(score.at(s), temp, sizeof(char) * 4, 10);
		doc.append_child("Score").set_value(((const pugi::char_t*)temp));
	}
	doc.save_file("HallOfFame.xml");
	

	free(temp);
	return 0;
}

