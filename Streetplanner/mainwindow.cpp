#include <QFile>
#include <QFileDialog>
#include "mainwindow.h"
#include "city.h"
#include "street.h"
#include "userinput.h"
#include "inputstreet.h"
#include "wayfinder.h"
#include "./ui_mainwindow.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include "mapiofileinput.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    ui->debugInputs->hide();
    MapIoNrw* mapioNrw = new MapIoNrw();
    mapio = mapioNrw;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_test_clicked()
{
    QString lineText = ui->lineEdit_test->text();
    QString text = QString("Lel: %1").arg(lineText);

    bool err;
    int i = lineText.toInt(&err);

    qDebug() << text;

    if(err) qDebug() << i+4;

    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::yellow);

    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);

    scene.addRect(rand()%10, rand()%10, rand()%100, rand()%100, pen, brush);

}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    map.clear();
    scene.clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.about(this, "Test Titel", "Lorem ipsum est");
}


void MainWindow::on_cityButton_clicked()
{
    City* c1 = new City("Aachen", 50, 100);
    City* c2 = new City("Köln", 200, 80);

    scene.addLine(53,103,203,83);
    c1->draw(scene);
    c2->draw(scene);

}


void MainWindow::on_mapButton_clicked()
{
    City* c1 = new City("city c1", rand()%200, rand()%500);
    map.addCity(c1);
    map.draw(scene);
}



void MainWindow::on_streetButton_clicked()
{
    City* c1 = new City("city c1", rand()%200, rand()%500);
    City* c2 = new City("city c1", rand()%200, rand()%500);

    Street* s1 = new Street(c1, c2);

    map.addCity(c1);
    map.addCity(c2);

    s1->draw(scene);
    map.draw(scene);



}


void MainWindow::on_mapStreetButton_clicked()
{
    City* c1 = new City("Frankfuhrt am Main", 300, 200);
    City* c2 = new City("Mainz", 250, 200);
    City* c3 = new City("Aachen", 50, 100);

    Street* s1 = new Street(c1, c2);
    Street* s2 = new Street(c1, c3);

    map.addCity(c1);
    map.addCity(c2);
    map.addStreet(s1);
    map.addStreet(s2);

    map.draw(scene);
}


void MainWindow::on_debugBox_clicked()
{
    if(!ui->debugBox->isChecked()){
        ui->debugInputs->hide();
    }
    else{
        ui->debugInputs->show();
    }

}


void MainWindow::on_addCity_clicked()
{
    Start:
    UserInput userInput;
    int retcode = userInput.exec();
    City* tempCity = userInput.getCityInput();
    if(retcode==0){
        return;
    }
    if(retcode!=1){
        qDebug() << "Error: Could not build City from Dialogbox in MainWindow";
        goto Start;
    }

    map.addCity(std::move(tempCity));
    map.draw(scene);

}

void MainWindow::on_fillMapButton_clicked()
{
    mapio->fillMap(map);
    map.draw(scene);
}


void MainWindow::on_testDijkstraButton_clicked()
{
    QVector<Street*> streets = Dijkstra::search(map, "Aachen", "Düsseldorf");

    if(streets.length()==0){
        qDebug() << "No connection found";
        return;
    }

    for(qsizetype i = 0; i < streets.size(); i++){
        streets.at(i)->drawred(scene);
    }

    qDebug() << "Connection found with " << streets.length() << " Streets between";
}


void MainWindow::on_dijkstraButton_clicked()
{
    WayFinder wayFinder;
    int retcode = wayFinder.exec();
    QVector<Street*> streets = wayFinder.search(map, scene);
}


void MainWindow::on_addStreetButton_clicked()
{
    if(map.getCityList().isEmpty()) return;
    InputStreet inputStreet(nullptr, map.getCityList().toList());
    int retcode = inputStreet.exec();
    if(!retcode){
        qDebug() << "Error: Could not Build City from Dialogbox in MainWindow";
        return;
    }
    inputStreet.buildStreet(map, scene);
}

void MainWindow::on_loadMapButton_clicked()
{

    QFile cityFile(QFileDialog::getOpenFileName(this, tr("Choose City File"), "", tr("City File (*.txt)")));
    QString cityString = QString::fromStdU32String(cityFile.filesystemFileName().u32string());
    if (cityString.isEmpty()){
        QMessageBox error;
        qDebug() << "Error: File not found.";
        error.critical(0,"Error", "File not found");
        return;
    }
    QFile streetFile(QFileDialog::getOpenFileName(this, tr("Choose Street File"), "", tr("Street File (*.txt)")));
    QString streetString = QString::fromStdU32String(streetFile.filesystemFileName().u32string());
    if (cityString.isEmpty()){
        QMessageBox error;
        qDebug() << "Error: File not found.";
        error.critical(0,"Error", "File not found");
        return;
    }
    mapio = new MapIoFileinput(cityString, streetString);
    mapio->fillMap(map);
    map.draw(scene);
}


void MainWindow::on_abstractMapButton_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}
