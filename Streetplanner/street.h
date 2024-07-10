#ifndef STREET_H
#define STREET_H

#include "city.h"

class Street
{
private:
    City* cA;
    City* cB;
public:
    /**
     * 0@brief Class for streets on map. Connects between two cities.
     */
    Street(City*, City*);

    /**
     * @brief Draws street on QGraphicsScene
     * @param QGraphicsScene Reference
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief Draws street on QGraphicsScene just red and slightly thicker.
     * @param QGraphicsScene Reference
     */
    void drawred(QGraphicsScene& scene);

    /**
     * @brief Returns cities on the ends of the road.
     * @return QList of Pointers to 2 cities
     */
    QList<City*> getCities()const;
};

#endif // STREET_H
