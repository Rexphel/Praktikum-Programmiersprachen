//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Funktion zum berechnen der Länge eines Vektors.
 *
 * @return Länge des Vektors.
 */

double Vektor::laenge() const{
	return std::sqrt(this->x*this->x+this->y*this->y+this->z*this->z);
}

/**
 * @brief Funktion zum subtrahieren zweier Vektoren.
 *
 * @param input Vektor welcher subtrahiert werden soll.
 * @return Sutrahierter Vektor (neues Objekt).
 */

Vektor Vektor::sub(const Vektor& input) const{
	return Vektor(this->x-input.x,this->y-input.y, this->z-input.z);
}

/**
 * @brief Funktion zum addieren zweier Vektoren.
 *
 * @param input Vektor welcher addiert werden soll.
 * @return Addierter Vektor (neues Objekt).
 */

Vektor Vektor::add(const Vektor& input) const{
	return Vektor(this->x+input.x,this->y+input.y, this->z+input.z);
}

/**
 * @brief Funktion zum berechnen des Skalarproduktes zweier Vektoren.
 *
 * @param input Vektor mit dem zusammen das Skalarprodukt berechnet werden soll
 * @return Berechnetes Skalarprodukt.
 */
double Vektor::skalarProd(const Vektor& input) const {
	return this->x * input.x + this->y * input.y + this->z * input.z;
}

/**
 * @brief Funktion zum berechnen des Winkels zwischen zwei Vektoren.
 *
 * @param input	Vektor mit dem zusammen der Winkel berechnet werden soll.
 * @return Berechneter Winkel
 */
double Vektor::winkel(const Vektor& input) const{
	return std::acos((this->skalarProd(input))/(this->laenge()*input.laenge()));
}

/**
 * @brief Funktion zum Rotieren eines Vektors um die x3 Achse. Mit der Entsprechenden Rotationsachse.
 *
 * 	(cos(alpha)	-sin(alpha)	0)
 * 	(sin(alpha)	cos(alpha) 	0)
 * 	(0			0			1)
 *
 * @param rad	Winkel, um den Rotiert werden soll.
 */
void Vektor::rotiereUmZ(const double rad){
	this->x = std::cos(rad)*this->x-std::sin(rad)*this->y;
	this->y = std::sin(rad)*this->x+std::cos(rad)*this->y;
}
