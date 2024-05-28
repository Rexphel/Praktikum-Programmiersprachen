/*!
 * Praktikum Informatik 1
 *
 *
 * @file Medium.cpp
 */

#include "Buch.h"

#include <string>
#include <iostream>


Buch::Buch(std::string initTite, std::string autor): Medium(initTite), autor(autor){}

Buch::~Buch(void)
{
}

void Buch::ausgabe() const
{
    Medium::ausgabe();

    std::cout << "Autor: " << autor << std::endl;
}
