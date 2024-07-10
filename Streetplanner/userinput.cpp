#include "userinput.h"
#include "ui_userinput.h"
#include "QMessageBox"

UserInput::UserInput(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserInput)
{
    ui->setupUi(this);
}

UserInput::~UserInput()
{
    delete ui;
}

City* UserInput::getCityInput(){

    QString initName = ui->cityNameBox->currentText().trimmed();
    int initSize = ui->citySizeLineEdit->text().trimmed().toInt();
    int initX = ui->cityLatitudeLineEdit->text().toInt();
    int initY = ui->cityLongitudeLineEdit->text().trimmed().toInt();
    City* tempCity = new City(initName, initX, initY, initSize);

    return std::move(tempCity);
}


void UserInput::on_buttonBox_accepted()
{
    bool bToInt = false;

    QString initName = ui->cityNameBox->currentText().trimmed();
    if(initName.isEmpty()){
        QMessageBox error;
        error.critical(0,"Error", "Name Empty or not Valid");
        qDebug() << "Error: Name Empty or not Valid";
        setResult(2);
        return;
    }
    int initSize = ui->citySizeLineEdit->text().trimmed().toInt(&bToInt);
    if(!bToInt) {
        QMessageBox error;
        error.critical(0,"Error", "Size no Valid Number");
        qDebug() << "Error: Size no Valid Number";
        setResult(2);
        return;
    }
    int initX = ui->cityLatitudeLineEdit->text().toInt(&bToInt);
    if(!bToInt) {
        QMessageBox error;
        error.critical(0,"Error", "Latitude no Valid Number");
        qDebug() << "Error: Latitude no Valid Number";
        setResult(2);
        return;
    }
    int initY = ui->cityLongitudeLineEdit->text().trimmed().toInt(&bToInt);
    if(!bToInt) {
        QMessageBox error;
        error.critical(0,"Error", "Longitude no Valid Number");
        qDebug() << "Error: Longitude no Valid Number";
        setResult(2);
        return;
    }
    if(initSize == 0){
        qDebug() << "Warning: Size cannot be 0. Dafault to 6";
        initSize = 6;
    }

}

