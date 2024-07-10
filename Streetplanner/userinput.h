#ifndef USERINPUT_H
#define USERINPUT_H

#include <QDialog>
#include <QAbstractButton>
#include "city.h"

namespace Ui {
class UserInput;
}

class UserInput : public QDialog
{
    Q_OBJECT

public:
    explicit UserInput(QWidget *parent = nullptr);
    City* getCityInput();
    ~UserInput();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::UserInput *ui;
};

#endif // USERINPUT_H
