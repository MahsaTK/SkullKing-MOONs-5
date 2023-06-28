#ifndef FORGOT_H
#define FORGOT_H

#include <QMainWindow>

namespace Ui {
class Forgot;
}

class Forgot : public QMainWindow
{
    Q_OBJECT

public:
    explicit Forgot(QWidget *parent = nullptr);
    ~Forgot();

private:
    Ui::Forgot *ui;
};

#endif // FORGOT_H
