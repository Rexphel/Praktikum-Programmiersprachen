#include "street.h"
#include "dimensions.h"

Street::Street(City* tempCityA, City* tempCityB): cA(tempCityA), cB(tempCityB) {}

void Street::draw(QGraphicsScene& scene){
    struct Dimensions dimA = cA->getdimensions();
    struct Dimensions dimB = cB->getdimensions();

    scene.addLine(dimA.x+dimA.size/2, dimA.y+dimA.size/2, dimB.x+dimB.size/2, dimB.y+dimB.size/2);
}

void Street::drawred(QGraphicsScene& scene){
    struct Dimensions dimA = cA->getdimensions();
    struct Dimensions dimB = cB->getdimensions();

    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);

    scene.addLine(dimA.x+dimA.size/2, dimA.y+dimA.size/2, dimB.x+dimB.size/2, dimB.y+dimB.size/2, pen);
}

QList<City*> Street::getCities()const{
    QList<City*> cities;
    cities.push_back(cA);
    cities.push_back(cB);
    return cities;
}
