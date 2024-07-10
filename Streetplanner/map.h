#ifndef MAP_H
#define MAP_H

#include "city.h"
#include "street.h"
#include "abstractmap.h"

class Map : public AbstractMap
{
private:
    QList<City*> vCities;
    QList<Street*> vStreets;
public:
    /**
     * @brief Map Class to store all cities and roads in QVectors as Pointers
     */
    Map();

    /**
     * @brief Adds city to map
     * @param Pointer to city to be added to map
     */
    void addCity(City*);

    /**
     * @brief Adds street to map
     * @param Pointer to street to be added to map
     * @return Returns False if failed, or True if succeded
     */
    bool addStreet(Street*);

    /**
     * @brief Redraws map on scene
     * @param QGraphicsScene Reference
     */
    void draw(QGraphicsScene& scene) const;

    /**
     * @brief Finds city based on name
     * @param QString of city name
     * @return Pointer to city
     */
    City* findCity(const QString cityName) const;

    /**
     * @brief Returns all streets connected to an city as a Vector of Pointers
     * @param Const Pointer to city to check
     * @return QVector of Pointers to steets
     */
    QVector<Street*> getStreetList(const City* city) const;

    /**
     * @brief Returns QVector of all citys on map
     * @return QVector of Pointers to cities.
     */
    QVector<City*> getCityList() const;

    /**
     * @brief Gets city on opposite end of street.
     * @param Const Pointer to Street
     * @param Const Pointer to City
     * @return Opposite City on Street
     */
    City* getOppositeCity(const Street* street, const City* city) const;

    /**
     * @brief Returns length of street
     * @param const pointer to street
     * @return Length of street as double
     */
    double getLength(const Street* street) const;

    /**
     * @brief Clears map of all Cities and Streets.
     */
    void clear();
};

#endif // MAP_H
