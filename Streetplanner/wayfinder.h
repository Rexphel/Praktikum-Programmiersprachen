#ifndef WAYFINDER_H
#define WAYFINDER_H

#include <QDialog>
#include "street.h"
#include "abstractmap.h"

namespace Ui {
class WayFinder;
}

class WayFinder : public QDialog
{
    Q_OBJECT

public:
    explicit WayFinder(QWidget *parent = nullptr, QList<City*> cityList = QList<City*>());
    QVector<Street*> search(const AbstractMap &map, QGraphicsScene& scene);
    ~WayFinder();

private slots:
    void on_startBox_currentIndexChanged(int index);

private:
    QList<City*> cities;
    Ui::WayFinder *ui;
};

#endif // WAYFINDER_H
