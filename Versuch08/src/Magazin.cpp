/*!
 * Praktikum Informatik 1
 *
 *
 * @file Magazin.cpp
 */

#include "Magazin.h"

#include <string>
#include <iostream>


Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte): Medium(initTitel), DatumAusgabe(initDatumAusgabe), Sparte(initSparte){}

Magazin::~Magazin(void)
{
}

void Magazin::ausgabe() const
{
    Medium::ausgabe();

    std::cout << "Datum der Ausgabe: " << DatumAusgabe << std::endl;
    std::cout << "Sparte: " << Sparte << std::endl;
}

bool Magazin::ausleihen(Person person,Datum ausleihdatum)
{
    if ( ausleihdatum-DatumAusgabe <= 30){
    	std::cout << "Das Magazin \"" << titel << "\" ist noch nicht alt genug!" << std::endl;
    	return false;
    }

    return Medium::ausleihen(person, ausleihdatum);
}
