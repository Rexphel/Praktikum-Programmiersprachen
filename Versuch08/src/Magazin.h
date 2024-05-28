/*
 * Magazin.h
 *
 *  Created on: May 28, 2024
 *      Author: rexphel
 */

#ifndef SRC_MAGAZIN_H_
#define SRC_MAGAZIN_H_


#include <string>
#include <iostream>
#include "Medium.h"
#include "Datum.h"


/*! \brief Klasse f�r ein Magazin
 *
 * Speichert ein Buch, bestehend aus Titel, Datum der Ausgabe und Sparte.
 *
 */

class Magazin : public Medium
{
public:
    /*!
     * @brief Konstruktor f�r ein gegebenes Buch
     *
     * \param string initTitel:    gegebener Titel
     * \param Datum initDatumAusgabe:  gegebenes Datum der Ausgabe
     * \param string initSparte:	gegebene Sparte
     *
     */
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

    /*!
     * @Brief Destruktor
     */
    ~Magazin(void);

    /*!
	 * @brief Ausgabefunktion
	 *
	 * Funktion gibt alle Informationen eines Magazins auf der Konsole aus
	 */
	void ausgabe() const override;

	/*!
	 * @brief Ausleihen-Funktion
	 *
	 * \param Person person: Person die das Magazin ausleihen m�chte
	 * \param Datum ausleihdatum: Datum an dem das Magazin ausgeliehen wird
	 *
	 * \return bool: true,  wenn die Ausleihbeschr�nkungen erf�llt sind und das Medium ausgeliehen werden kann
	 *               false, wenn die Ausleihbeschr�nkungen nicht erf�llt sind und das Medium nicht ausgeliehen werden kann
	 */
	bool ausleihen(Person person, Datum ausleihdatum) override;


private:
    Datum DatumAusgabe;
    std::string Sparte;

};



#endif /* SRC_MAGAZIN_H_ */
