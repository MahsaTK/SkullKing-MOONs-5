#ifndef CHANNELS_H
#define CHANNELS_H
#include "Player.h"
#include <QWidget>
#include <QTcpSocket>
#include <thread>
namespace Ui {
class Channels;
}

class Channels : public QWidget
{
    Q_OBJECT

public:
    explicit Channels(QTcpSocket * Socket,QWidget *parent = nullptr);
    ~Channels();
    void communicate();
    QString playerName;
    QTcpSocket * socket;
private:
    Ui::Channels *ui;
    std::thread Thread;
};

#endif // CHANNELS_H
