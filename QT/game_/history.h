#ifndef HISTORY_H
#define HISTORY_H
#include <GameInfo.h>
#include <QMainWindow>

namespace Ui {
class History;
}

class History : public QMainWindow
{
    Q_OBJECT

public:
    explicit History(GameInfo g2,QWidget *parent = nullptr);
    ~History();

private:
    Ui::History *ui;
};

#endif // HISTORY_H
