/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

struct Person{
	std::string sNachname;
	std::string sVorname;
	int iGebrtsutag;
	int iAlter;
};

void vUserDisplay(Person user);

int main()
{
	Person nBenutzer;
	std::string sNachname;
	std::string sVorname;
	int iGeburtstag;
	int iAlter;
	std::cout << "Bitte Nachname eingeben:" << std::endl;
	std::cin >> sNachname;
	std::cout << "Bitte Vorname eingeben:" << std::endl;
	std::cin >> sVorname;
	std::cout << "Bitte Geburtstag eingeben:" << std::endl;
	std::cin >> iGeburtstag;
	std::cout << "Bitte Alter eingeben:" << std::endl;
	std::cin >> iAlter;

	nBenutzer.sNachname=sNachname;
	nBenutzer.sVorname=sVorname;
	nBenutzer.iGebrtsutag=iGeburtstag;
	nBenutzer.iAlter=iAlter;

	vUserDisplay(nBenutzer);

	Person nKopieEinzeln;
	nKopieEinzeln.sNachname=nBenutzer.sNachname;
	nKopieEinzeln.sVorname=nBenutzer.sVorname;
	nKopieEinzeln.iGebrtsutag=nBenutzer.iGebrtsutag;
	nKopieEinzeln.iAlter=nBenutzer.iAlter;

	Person nKopieGesammt = nBenutzer;

	std::cout << "Kopie Einzeln: " << std::endl;
	vUserDisplay(nKopieEinzeln);
	std::cout << "Kopie Gesammt: " << std::endl;
	vUserDisplay(nKopieGesammt);


    return 0;
    
}

void vUserDisplay(Person user){
	std::cout << "Nutzer: " << user.sNachname << ", " << user.sVorname << std::endl;
	std::cout << "Geburtstag: " << user.iGebrtsutag << " Alter: " << user.iAlter << std::endl;

	return;
}



