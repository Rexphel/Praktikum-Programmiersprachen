/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>

#include "Liste.h"
#include "Student.h"

int main()
{
	std::vector<Student> studentenListe;
    Student student;
    std::string dateiname;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
    	std::vector<std::string> fileLines;
		std::cout << "Bitte geben sie den vollständigen Datei Namen ein: ";
		getline(std::cin, dateiname);    // ganze Zeile einlesen inklusive aller Leerzeichen
        std::ifstream infile(dateiname);
        std::string line;
        while (std::getline(infile, line))
        {
            std::istringstream iss(line);
            fileLines.push_back(line);
        }

        for (unsigned int i=0; i<fileLines.size(); i=i+4){
        	studentenListe.push_back(Student(std::stoi(fileLines[i]), fileLines[i+1], fileLines[i+2],fileLines[i+3]));
        }

        /*student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.pushBack(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.pushBack(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.pushBack(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.pushBack(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
        studentenListe.pushBack(student);
        */

    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne loeschen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
				  << "(5): Datenelement Löschen" << std::endl
				  << "(6): Datenelement vorne hinzufügen" << std::endl
				  << "(7): Datenelement hinten entfernen" <<std::endl
				  << "(8): Daten aus einer Datei einlesen" <<std::endl
				  << "(9): Daten in eine Datei sichern" <<std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.front();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for(Student s: studentenListe){
                    	s.ausgabe();
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

            // Datenbak rueckwarts auslesen
            case '4':
				if(!studentenListe.empty())
				{
					std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
					for(std::vector<Student>::reverse_iterator riter = studentenListe.rbegin();riter != studentenListe.rend(); ++riter){
						riter->ausgabe();
					}
				}
				else
				{
					std::cout << "Die Liste ist leer!\n\n";
				}
				break;

			// Daten element löschen
            case '5':
            {
				if(!studentenListe.empty())
				{
					unsigned int matNr = 0;
					std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nMat.Nr: ";
					std::cin >> matNr;
					std::cin.ignore(10, '\n');

					for(std::vector<Student>::iterator iter = studentenListe.begin();iter != studentenListe.end(); ++iter){
						if(iter->getMatNr()==matNr){
							iter->ausgabe();
							studentenListe.erase(iter);
							std::cout << "Löschen erfolgreich." << std::endl;
							break;
						}
						if(std::next(iter) == studentenListe.end()){
							std::cout << "Student mit Matr.Nr: " << matNr << " wurde nicht gefunden" << std::endl;
						}
					}
				}
				else
				{
					std::cout << "Die Liste ist leer!\n\n";
				}

            	}
				break;

			// Datenelement vorne hinzufügen
            case '6':
            {
				unsigned int matNr = 0;
				std::string name = "";
				std::string geburtstag = "";
				std::string adresse = "";

				std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
				getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

				std::cout << "Geburtsdatum: ";
				getline(std::cin, geburtstag);

				std::cout << "Adresse: ";
				getline(std::cin, adresse);

				std::cout << "Matrikelnummer: ";
				std::cin >> matNr;
				std::cin.ignore(10, '\n');

				student = Student(matNr, name, geburtstag, adresse);

				studentenListe.insert(studentenListe.begin(), student);

            	}
				break;

				// Datenelement hinten entfernen
				case '7':
					{
						if(!studentenListe.empty())
						{
							student = studentenListe.back();
							std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
							student.ausgabe();
							studentenListe.pop_back();
						}
						else
						{
							std::cout << "Die Liste ist leer!\n";
						}
					}
					break;

				// Datenelemente aus einer Datei auslesen
				case '8':
					{
						studentenListe.clear();
						if(!dateiname.empty()){
							std::string newName;
							std::cout << "Möchten sie aus einer Neuen Datei einlesen? y/n:" << std::endl;
							getline(std::cin, newName);    // ganze Zeile einlesen inklusive aller Leerzeichen
							if(newName!="n"){
								std::cout << "Bitte geben sie den vollständigen Datei Namen ein: ";
								getline(std::cin, dateiname);    // ganze Zeile einlesen inklusive aller Leerzeichen
							}
						}
						else{
							std::cout << "Bitte geben sie den vollständigen Datei Namen ein:"<< std::endl;
							getline(std::cin, dateiname);    // ganze Zeile einlesen inklusive aller Leerzeichen
						}

						std::vector<std::string> fileLines;
						std::ifstream infile(dateiname);
						std::string line;
						while (std::getline(infile, line))
						{
							std::istringstream iss(line);
							fileLines.push_back(line);
						}

						for (unsigned int i=0; i<fileLines.size(); i=i+4){
							studentenListe.push_back(Student(std::stoi(fileLines[i]), fileLines[i+1], fileLines[i+2],fileLines[i+3]));
						}
					}
					break;
					// Datenelemente aus einer Datei auslesen
			case '9':
			{
				if(!studentenListe.empty())
				{
					std::ofstream outdata;
					outdata.open("students.save");
					if(!outdata){
						std::cerr << "Error: Datei konnte nicht geöfnet werden!";
						return 1;
					}
					for(std::vector<Student>::const_iterator iter = studentenListe.cbegin();iter != studentenListe.cend(); ++iter){
						outdata << iter->getMatNr() << std::endl
								<< iter->getName() << std::endl
								<< iter->getGeburtstag() << std::endl
								<< iter->getAdresse() << std::endl;
					}
				}
				else
				{
					std::cout << "Die Liste ist leer!\n";
				}
				}
				break;

			 case '0':
				std::cout << "Das Programm wird nun beendet";
				break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
