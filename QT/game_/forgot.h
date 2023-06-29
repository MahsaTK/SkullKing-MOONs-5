#ifndef FORGOT_H
#define FORGOT_H
#pragma once

#include <QMainWindow>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <functions.h>
#include <QDialog>

namespace Ui {
class Forgot;
}

class Forgot : public QDialog
{
    Q_OBJECT

public:
    explicit Forgot(QWidget *parent = nullptr);
    ~Forgot();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Forgot *ui;
//    QFormLayout *forgotMainForm;
//    QLabel *forgotUserLabel;
//    QLabel *forgotPassLabel;
//    QLineEdit * forgotPassEdit;
//    QLineEdit * forgotUserEdit;
};

#endif // FORGOT_H
