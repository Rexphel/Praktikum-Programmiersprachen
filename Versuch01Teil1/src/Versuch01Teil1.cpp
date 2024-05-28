//============================================================================
// Name        : Versuch01Teil1.cpp
// Author      : Philip Rexroth
// Version     :
// Copyright   : @2024 Philip Rexroth
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

void Aufgaben1bis3();
void Aufgaben4bis7();
int getAlphabetPosition(int iASCIICode);

int main() {

	int iAufgabe;

	std::cout << "Welche aufgabe? (1-7 default=all)" << std::endl;
	std::cin >> iAufgabe;
	switch (iAufgabe){
		case 1 ... 3:
			Aufgaben1bis3();
			break;
		case 4 ... 7:
			Aufgaben4bis7();
			break;
		default:
			Aufgaben1bis3();
			Aufgaben4bis7();
			break;
	}

	return 0;
}

void Aufgaben1bis3(){
	int iErste;
	int iZweite;
	int iSumme;
	int iQuotient;
	double dSumme;
	double dQuotient;
	double dSummeCast;
	double dQuotientCast;


	std::cout << "Bitte Erste Zahl eingeben." << std::endl;
	std::cin >> iErste;
	std::cout << "Bitte Zweite Zahl eingeben." << std::endl;
	std::cin >> iZweite;

	iSumme = iErste + iZweite;
	iQuotient= iErste / iZweite;
	dSumme = iErste + iZweite;
	dQuotient = iErste / iZweite;
	dSummeCast = (double) iErste + (double) iZweite;
	dQuotientCast = (double) iErste / (double) iZweite;

	std::cout << "Die Summe von " << iErste << " und " << iZweite << " lautet (int) " << iSumme << " oder (double) " << dSumme << " oder (double mit Type Cast) " << dSummeCast << std::endl;
	std::cout << "Der Quotient von " << iErste << " durch " << iZweite << " lautet (int) " << iQuotient << " oder (double) " << dQuotient << " oder (double mit Type Cast) " << dQuotientCast << std::endl;

	return;
}

void Aufgaben4bis7(){
	std::string sVorname;
	std::string sNachname;
	std::string sVornameName;
	std::string sNameVorname;

	std::cout << "Bitte Vorname eingeben:" << std::endl;
	std::cin >> sVorname;
	std::cout << "Bitte Nachname eingeben:" << std::endl;
	std::cin >> sNachname;

	sVornameName = sVorname+" "+sNachname;
	sNameVorname = sNachname+", "+sVorname;

	std::cout << "VornameName: " << sVornameName << " NameVorname: " << sNameVorname << std::endl;
	{
		int iFeld[2] = {1,2};
		int spielfeld[2][3] = {{1,2,3},{4,5,6}};

		std::cout << "Spielfeld: " << std::endl;

		for (int y=0; y<2; y++){
			for (int x=0; x<3; x++){
				std::cout << spielfeld[y][x] << " ";
			}
			std::cout << std::endl;
		}

		int iZweite = 1;
		std::cout << "Zweite: " << iZweite << std::endl;
	}
	//std::cout << "Zweite Nr.2: " <<iZweite << std::endl;

	int iASCII1 = sVorname[0];
	int iASCII2 = sVorname[1];

	std::cout << iASCII1 << iASCII2 << std::endl;

	int iAlphabetNr1 = getAlphabetPosition(iASCII1);
	int iAlphabetNr2 = getAlphabetPosition(iASCII2);

	if(!iAlphabetNr1 || !iAlphabetNr2){
		std::cout << "Eingabe nicht vollständig im Alphabet." << std::endl;
	}
	else{
		std::cout << "Erster Buchstabe Nr. " << iAlphabetNr1 << " Zeiter Buchstabe Nr. " <<iAlphabetNr2 << std::endl;
	}

	return;

}

int getAlphabetPosition(int iASCIICode){

	int iPos = 0;

	switch (iASCIICode){
		case 65 ... 90:
			iPos = iASCIICode - 64;
			break;
		case 97 ... 122:
			iPos = iASCIICode - 96;
			break;
	}
	return iPos;
}


