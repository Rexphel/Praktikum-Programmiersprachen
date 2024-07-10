#include "inputstreet.h"
#include "ui_inputstreet.h"

InputStreet::InputStreet(QWidget *parent, QList<City*> cityList)
    : QDialog(parent)
    , ui(new Ui::inputStreet)
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

int InputStreet::buildStreet(AbstractMap &map, QGraphicsScene& scene){

    if(ui->startBox->currentText().isEmpty()||ui->destinationBox->currentText().isEmpty()){
        qDebug() << "Error: Input Empty";
        return 1;
    }

    City* start = map.findCity(ui->startBox->currentText());
    City* destination = map.findCity(ui->destinationBox->currentText());

    Street* newStreet = new Street(start, destination);

    map.addStreet(newStreet);
    map.draw(scene);

    return 1;
}

InputStreet::~InputStreet()
{
    delete ui;
}

void InputStreet::on_startBox_currentIndexChanged(int index)
{
    ui->startBox->setCurrentIndex(index);
    ui->destinationBox->clear();
    QList<City*> tempList = cities;
    tempList.removeAt(index);
    ui->destinationBox->insertItems(0, City::getCityNames(tempList));

}
