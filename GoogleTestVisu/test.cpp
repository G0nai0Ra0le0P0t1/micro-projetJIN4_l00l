#include "pch.h"
#include <iostream>
#include "pugixml.hpp"
#include "../MaBibliotheque/ProjetJIN4.cpp"

/*
TEST(toto, tata) {
	ASSERT_FALSE(false);
}

//test de removeLastCharStr(std::)
TEST(TestReadXML, TestChar1) {
	std::string test;
	test = removeLastCharStr(test);
	const char* testchar = test.c_str();
	ASSERT_EQ(*testchar, NULL);
	std::string test1 = "0101";
	test1 = removeLastCharStr(test1);
	if (test1 == "010")
		ASSERT_EQ(0, 0);
	else
		ASSERT_NE(0, 0);
}

//test de inversion(char* chaine)
TEST(TestReadXML, TestChar2) {
	std::string test;
	inversion(test);
	const char* testchar = test.c_str();
	ASSERT_EQ(*testchar, NULL);
	std::string test1 = "4201";
	inversion(test1);
	if (test1 == "1024")
		ASSERT_EQ(1, 1);
	else
		ASSERT_NE(1, 1);
	//ASSERT_EQ(test1, "1024");
	std::string test2 = "0101";
	inversion(test2);
	inversion(test2);
	//ASSERT_EQ(test2, "0101");
	if (test2 == "0101")
		ASSERT_EQ(2, 2);
	else
		ASSERT_NE(2, 2);
	std::string test3 = "201";
	inversion(test3);
	//ASSERT_EQ(test3, "102");

}


//test turnInBinary(int nombre)
TEST(TestReadXML, TestChar3) {
	std::string test1 = turnInBinaryStr(0);
	std::string test2 = turnInBinaryStr(5);
	std::string test3 = turnInBinaryStr(114);
	std::string test4 = turnInBinaryStr(247);
	//ASSERT_EQ(test1, '0');
	if (test2 == "101")
		ASSERT_EQ(3, 3);
	else
		ASSERT_NE(3, 3);
	//ASSERT_EQ(test2, '101');
	//ASSERT_EQ(test3, "1110010");
	ASSERT_EQ(test4, "11110111");
	if (test4 == "11110111")
		ASSERT_EQ(4, 4);
	else
		ASSERT_NE(4, 4);
}



//test turnInDec(char* chaine)
TEST(TestReadXML, TestChar4) {
	int test1 = turnInDec("0");
	int test2 = turnInDec("101");
	std::string pipo = "101";
	int test3 = turnInDec("1110010");
	int test4 = turnInDec("11110111");
	ASSERT_EQ(test1, 0);
	ASSERT_EQ(test2, 5);
	ASSERT_EQ(test3, 114);
	ASSERT_EQ(test4, 247);
}


//test generateCalc(std::vector<Donnees*>* genere)
TEST(TestReadXML, TestVect1) {
	std::vector<Donnees*> genere;
	//ASSERT_EQ(genere, NULL);
	generateCalc(&genere);
	ASSERT_EQ(genere.size(), 4);
	//ASSERT_NE(genere.at(0), NULL);
	//ASSERT_NE(genere.at(1), NULL);
	//ASSERT_NE(genere.at(2), NULL);
	//ASSERT_NE(genere.at(3), NULL);
}

//test verif(Donnees* first, Donnees* second)
TEST(TestReadXML, Donnees1) {
	Donnees* test1 = new Donnees(1, "100");
	Donnees* test2 = new Donnees(1, "100");
	Donnees* test3 = new Donnees(1, "4");
	Donnees* test4 = new Donnees(1, "101");
	ASSERT_EQ(verif(test1, test2), 0);
	ASSERT_EQ(verif(test1, test3), 0);
	ASSERT_EQ(verif(test1, test4), 1);
}*/