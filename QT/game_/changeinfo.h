#ifndef CHANGEINFO_H
#define CHANGEINFO_H
#include <QPushButton>
#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QFormLayout>
#include <QDialog>
#include <functions.h>

namespace Ui {
class changeInfo;
}

class changeInfo : public QDialog
{
    Q_OBJECT

public:
    explicit changeInfo(Player& person,QWidget *parent = nullptr);
    ~changeInfo();
    Player get_player(){
        return player;
    }

private slots:
    void on_buttonBox_accepted();

private:
    Ui::changeInfo *ui;
    QFormLayout *MainForm;
    QLineEdit * UserEdit;
    QLineEdit *PassEdit;
    QLabel*explain;
    QLabel*PassLabel;
    QLabel*UserLabel;
    QLineEdit*NameEdit;
    QLineEdit*Last_nameEdit;
    QLineEdit*Phone_numberEdit;
    QLineEdit*EmailEdit;
    QLineEdit*AddressEdit;
    QLabel*NameLabel;
    QLabel*Last_nameLabel;
    QLabel*Phone_numberLabel;
    QLabel*EmailLabel;
    QLabel*AddressLabel;
    Player player;
};

#endif // CHANGEINFO_H
