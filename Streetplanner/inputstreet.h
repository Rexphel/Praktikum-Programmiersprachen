#ifndef INPUTSTREET_H
#define INPUTSTREET_H

#include <QDialog>
#include "abstractmap.h"
#include "city.h"

namespace Ui {
class inputStreet;
}

class InputStreet : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief QDialog for creating a Street between two diffrent cities
     * @param List of Pointers to all cities on map
     */
    explicit InputStreet(QWidget *parent = nullptr, QList<City*> cityList = QList<City*>());

    /**
     * @brief Creates a Street between two cities
     * @param Map Object to be modified
     * @param QGraphicsScene reference
     * @return
     */
    int buildStreet(AbstractMap &map, QGraphicsScene& scene);
    ~InputStreet();

private slots:
    void on_startBox_currentIndexChanged(int index);

private:
    QList<City*> cities;
    Ui::inputStreet *ui;
};

#endif // INPUTSTREET_H
