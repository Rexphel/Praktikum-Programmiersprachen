#include "city.h"

City::City(QString name, int initx, int inity, int initsize): name(name), dim(Dimensions{initx, inity, initsize}) {}

City::~City()=default;

void City::draw(QGraphicsScene& scene){

    QPen pen;
    pen.setWidth(dim.size);
    pen.setColor(Qt::red);

    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);

    scene.addEllipse(dim.x, dim.y, dim.size, dim.size, pen, brush);

    QGraphicsTextItem* cityName = new QGraphicsTextItem ;
    cityName -> setPos(dim.x+dim.size , dim.y+dim.size) ; // Position des Textes
    cityName -> setPlainText(name) ; // Text
    scene.addItem(cityName);

    qDebug() << "Draw City at x: " << dim.x << " y: " << dim.y;
}

QString City::getName(){
    return name;
}

struct Dimensions City::getdimensions(){
    return dim;
}

QList<QString> City::getCityNames(QList<City*> cityList){
    QList<QString> cityNames;
    for(qsizetype i = 0; i < cityList.size(); i++){
        cityNames.append(cityList.at(i)->getName());
    }
    return cityNames;
}
