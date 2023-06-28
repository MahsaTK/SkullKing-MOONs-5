#ifndef CHANNELS_H
#define CHANNELS_H

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
private:
    Ui::Channels *ui;
    QTcpSocket * socket;
    std::thread Thread;
};

#endif // CHANNELS_H
