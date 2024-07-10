#include "wayfinder.h"
#include "ui_wayfinder.h"
#include "dijkstra.h"

WayFinder::WayFinder(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WayFinder)
{
    ui->setupUi(this);
}

QVector<Street*> WayFinder::search(const AbstractMap &map, QGraphicsScene& scene){

    QVector<Street*> streets;

    if(ui->startLineEdit->text().isEmpty() || ui->destinationLineEdit->text().isEmpty()){
        qDebug() << "Error: Input Empty";
        return streets;
    }

    streets = Dijkstra::search(map, ui->startLineEdit->text(), ui->destinationLineEdit->text());

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
