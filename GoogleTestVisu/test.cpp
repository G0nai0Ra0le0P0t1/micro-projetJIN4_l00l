#include "pch.h"
#include <iostream>
#include "pugixml.hpp"


TEST(toto, tata) {
	ASSERT_FALSE(false);
}
/*
//test de removeLastChar(char* chaine)
TEST(TestReadXML, TestChar1) {
	char* test;
	removeLastChar(test);
	ASSERT_EQ(*test, NULL);
	char* test1 = (char*)"0101";
	removeLastChar(test1);
	ASSERT_EQ(*test, "010");
}*/
/*
//test de inversion(char* chaine)
TEST(TestReadXML, TestChar2) {
	char* test;
	inversion(test);
	ASSERT_EQ(*test, NULL);
	char* test1 = (char*)"0101";
	inversion(test1);
	ASSERT_EQ(*test, "1010");
	char* test2 = (char*)"0101";
	inversion(test2);
	inversion(test2);
	ASSERT_EQ(*test, "0101");
}*/

/*
//test turnInBinary(int nombre)
TEST(TestReadXML, TestChar3) {
	char* test1 = turnInBinary(0);
	char* test2 = turnInBinary(5);
	char* test3 = turnInBinary(114);
	char* test4 = turnInBinary(247);
	ASSERT_EQ(*test1, '0');
	ASSERT_EQ(*test2, '101');
	ASSERT_EQ(*test3, "1110010");
	ASSERT_EQ(*test4, "11110111");
}*/


/*
//test turnInDec(char* chaine)
TEST(TestReadXML, TestChar4) {
	int test1 = turnInDec("0");
	int test2 = turnInDec("101");
	int test3 = turnInDec("1110010");
	int test4 = turnInDec("11110111");
	ASSERT_EQ(test1, 0);
	ASSERT_EQ(test2, 5);
	ASSERT_EQ(test3, 114);
	ASSERT_EQ(test4, 247);
}*/

/*
//test generateCalc(std::vector<Donnees*>* genere)
TEST(TestReadXML, TestVect1) {
	std::vector<Donnees*> genere;
	ASSERT_EQ(genere, NULL);
	generateCalc(&genere);
	ASSERT_EQ(genere.size(), 4);
	ASSERT_NE(genere.at(0), NULL);
	ASSERT_NE(genere.at(1), NULL);
	ASSERT_NE(genere.at(2), NULL);
	ASSERT_NE(genere.at(3), NULL);
}*/
/*
//test verif(Donnees* first, Donnees* second)
TEST(TestReadXML, Donnees1) {
	Donnees* test1 = new Donnees(1, "100");
	Donnees* test2 = new Donnees(1, "100");
	Donnees* test3 = new Donnees(1, "4");
	Donnees* test4 = new Donnees(1, "101");
	ASSERT_EQ(verif(test1, test2), 0);
	ASSERT_EQ(verif(test1, test3), 0);
	ASSERT_EQ(verif(test1, test4), 1);
}
*/