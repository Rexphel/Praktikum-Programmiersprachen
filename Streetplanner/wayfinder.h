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
    explicit WayFinder(QWidget *parent = nullptr);
    QVector<Street*> search(const AbstractMap &map, QGraphicsScene& scene);
    ~WayFinder();

private:
    Ui::WayFinder *ui;
};

#endif // WAYFINDER_H
