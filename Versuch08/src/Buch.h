/*!
 * Praktikum Informatik 1 MMXXIV
 *
 * @file Buch.h
 */

#ifndef BUCH_H_
#define BUCH_H_

#include <string>
#include <iostream>
#include "Medium.h"


/*! \brief Klasse f�r ein Buch
 *
 * Speichert ein Buch, bestehend aus Titel und Autor.
 *
 */

class Buch : public Medium
{
public:
    /*!
     * @brief Konstruktor f�r ein gegebenes Buch
     *
     * \param string titel:    gegebener Titel
     * \param string autor:  gegebener Autor
     *
     */
    Buch(std::string initTite, std::string autor);

    /*!
     * @Brief Destruktor
     */
    ~Buch(void);

    /*!
	 * @brief Ausgabefunktion
	 *
	 * Funktion gibt alle Informationen eines Mediums auf der Konsole aus
	 */
	void ausgabe() const override;


private:
    std::string autor;

};

#endif
