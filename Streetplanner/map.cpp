#include "map.h"

Map::Map() {}

void Map::addCity(City* ptrCity){
    QString name = ptrCity->getName();
    qDebug() << "Added " << name << " to Map";
    vCities.push_back(ptrCity);
    return;
}

bool Map::addStreet(Street* ptrStreet){
    QList<City*> sCities = ptrStreet->getCities();
    int found = 0;
    for(qsizetype i = 0; i < sCities.size(); i++){
        for(qsizetype j = 0; j < vCities.size(); j++){
            if(sCities.at(i)->getName()==vCities.at(j)->getName()){
                found++;
            }
        }
    }
    if(found < 2) {
        qDebug() << "Error: Could not find Cities of Street on Map";
        return false;
    }
    if(found > 2) {
        qDebug() << "Error: Found too many Cities with same name. Abort!";
        return false;
    }
    qDebug() << "Added Street between " << sCities.at(0)->getName() << " and " << sCities.at(1)->getName() << " to Map";
    vStreets.push_back(ptrStreet);
    return true;
}

void Map::draw(QGraphicsScene& scene)const{

    for(qsizetype i = 0; i < vStreets.size(); i++){
        vStreets.at(i)->draw(scene);
    }
    for(qsizetype i = 0; i < vCities.size(); i++){
        vCities.at(i)->draw(scene);
    }
    return;
}

City* Map::findCity(const QString cityName) const{
    for(qsizetype i = 0; i < vCities.size(); i++){
        if(vCities.at(i)->getName()==cityName) return vCities.at(i);
    }
    return nullptr;
}


QVector<Street*> Map::getStreetList(const City* city) const{
    QVector<Street*> tempStreets;
    for(qsizetype i = 0; i < vStreets.size(); i++){
        QList<City*> cities = vStreets.at(i)->getCities();
        if(cities[0]==city||cities[1]==city) tempStreets.push_back(vStreets.at(i));
    }
    return tempStreets;
}

QVector<City*> Map::getCityList() const{
    return vCities;
}


City* Map::getOppositeCity(const Street* street, const City* city) const{
    QList<City*> cities = street->getCities();

    if(cities[0]==city){
        return cities[1];
    }
    else if(cities[1] == city){
        return cities[0];
    }
    return nullptr;
}

double Map::getLength(const Street* street) const{

    QList<City*> cities = street->getCities();
    Dimensions dim0 = cities[0]->getdimensions();
    Dimensions dim1 = cities[1]->getdimensions();

    double xDist = std::abs(dim1.x-dim0.x);
    double yDist = std::abs(dim1.y-dim0.y);

    return std::sqrt(xDist*xDist+yDist*yDist);

}

void Map::clear(){
    vCities.clear();
    vStreets.clear();
}
