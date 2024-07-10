#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include "map.h"
#include "mapio.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_test_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_cityButton_clicked();

    void on_streetButton_clicked();

    void on_mapButton_clicked();

    void on_mapStreetButton_clicked();

    void on_debugBox_clicked();

    void on_addCity_clicked();

    void on_fillMapButton_clicked();

    void on_abstractMapButton_clicked();

    void on_testDijkstraButton_clicked();

    void on_dijkstraButton_clicked();

    void on_addStreetButton_clicked();

    void on_loadMapButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapio;

};
#endif // MAINWINDOW_H
