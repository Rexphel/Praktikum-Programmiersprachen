#ifndef CITY_H
#define CITY_H

#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "dimensions.h"

class City
{
private:
    QString name;
    Dimensions dim;
public:
    /**
     * @brief Class for Cities in Streetplaner.
     * @param Name of City
     * @param X-Coordinate. Stored in Dimensions Struct
     * @param Y-Coordinate. Stored in Dimensions Struct
     * @param Size of City. Equivilant to radius. Stored in Dimensions Struct
     */
    City(QString name, int initx, int inity, int initsize=6);
    //Deconstructor
    ~City();
    //Disable Copy Constructor
    City(const City&) = delete;

    /**
     * @brief Draws City in Scene
     * @param Reference to QGraphicsScene to draw on
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief Gets Name
     * @return City Name as QString
     */
    QString getName();

    /**
     * @brief Returns City Dimensions
     * @return Dimensions as Struct
     */
    struct Dimensions getdimensions();

    /**
     * @brief Returns the Names of all Cities in QList of City Pointers
     * @param QList of City Pointers
     * @return Qlist of QStrings of all Names
     */
    static QList<QString> getCityNames(QList<City*> cityList);
};

#endif // CITY_H
