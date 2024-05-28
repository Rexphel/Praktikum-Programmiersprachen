/*!
 * Praktikum Informatik 1
 *
 *
 * @file Magazin.cpp
 */

#include "DVD.h"

#include <string>
#include <iostream>


DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre): Medium(initTitel), Altersfreigabe(initAltersfreigabe), Genre(initGenre){}

DVD::~DVD(void)
{
}

void DVD::ausgabe() const
{
    Medium::ausgabe();

    std::cout << "Altersfreigabe: " << Altersfreigabe << std::endl;
    std::cout << "Genre: " << Genre << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	if ( ausleihdatum - person.getGeburtsdatum() < Altersfreigabe*365 ){
	    	std::cout << "Die Person \"" << person.getName() << "\" ist zum Ausleihtermin noch nicht alt genug!" << std::endl;
	    	return false;
	}
	return Medium::ausleihen(person, ausleihdatum);
}
