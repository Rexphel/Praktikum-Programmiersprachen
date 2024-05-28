/*
 * Magazin.h
 *
 *  Created on: May 28, 2024
 *      Author: rexphel
 */

#ifndef SRC_DVD_H_
#define SRC_DVD_H_


#include <string>
#include <iostream>
#include "Medium.h"
#include "Datum.h"


/*! \brief Klasse f�r eine DVD
 *
 * Speichert eine DVD, bestehend aus Titel, Altersfreigabe und Genre.
 *
 */

class DVD : public Medium
{
public:
    /*!
     * @brief Konstruktor f�r ein gegebenes Buch
     *
     * \param string initTitel:    gegebener Titel
     * \param int initAltersfreigabe:  gegebene Altersfreigabe
     * \param string initGenre:	gegebenes Genre
     *
     */
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

    /*!
     * @Brief Destruktor
     */
    ~DVD(void);

    /*!
	 * @brief Ausgabefunktion
	 *
	 * Funktion gibt alle Informationen einer DVD auf der Konsole aus
	 */
	void ausgabe() const override;

	/*!
	 * @brief Ausleihen-Funktion
	 *
	 * \param Person person: Person die die DVD ausleihen m�chte
	 * \param Datum ausleihdatum: Datum an dem die DVD ausgeliehen wird
	 *
	 * \return bool: true,  wenn die Ausleihbeschr�nkungen erf�llt sind und das Medium ausgeliehen werden kann
	 *               false, wenn die Ausleihbeschr�nkungen nicht erf�llt sind und das Medium nicht ausgeliehen werden kann
	 */
	bool ausleihen(Person person, Datum ausleihdatum) override;


private:
    int Altersfreigabe;
    std::string Genre;

};



#endif /* SRC_DVD_H_ */
