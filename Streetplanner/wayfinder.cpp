#include "wayfinder.h"
#include "ui_wayfinder.h"
#include "dijkstra.h"

WayFinder::WayFinder(QWidget *parent, QList<City*> cityList)
    : QDialog(parent)
    , ui(new Ui::WayFinder)
    , cities(cityList)
{
    ui->setupUi(this);

    ui->startBox->clear();
    ui->startBox->insertItems(0, City::getCityNames(cityList));
    ui->startBox->setCurrentIndex(0);
    ui->destinationBox->clear();
    ui->destinationBox->insertItems(0, City::getCityNames(cities.sliced(1)));
    ui->destinationBox->setCurrentIndex(0);
}

QVector<Street*> WayFinder::search(const AbstractMap &map, QGraphicsScene& scene){

    QVector<Street*> streets;

    if(ui->startBox->currentText().isEmpty() || ui->destinationBox->currentText().isEmpty()){
        qDebug() << "Error: Input Empty";
        return streets;
    }

    streets = Dijkstra::search(map, ui->startBox->currentText(), ui->destinationBox->currentText());

    if(streets.length()==0){
        qDebug() << "No connection found";
        return streets;
    }

    for(qsizetype i = 0; i < streets.size(); i++){
        streets.at(i)->drawred(scene);
    }

    qDebug() << "Connection found with " << (int)streets.length() << " Streets between";
    return streets;

}

WayFinder::~WayFinder()
{
    delete ui;
}

void WayFinder::on_startBox_currentIndexChanged(int index)
{
    ui->startBox->setCurrentIndex(index);
    ui->destinationBox->clear();
    QList<City*> tempList = cities;
    tempList.removeAt(index);
    ui->destinationBox->insertItems(0, City::getCityNames(tempList));

}

