/********************************************************************************
** Form generated from reading UI file 'startthegame.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTTHEGAME_H
#define UI_STARTTHEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartTheGame
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartTheGame)
    {
        if (StartTheGame->objectName().isEmpty())
            StartTheGame->setObjectName(QString::fromUtf8("StartTheGame"));
        StartTheGame->resize(800, 600);
        menubar = new QMenuBar(StartTheGame);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        StartTheGame->setMenuBar(menubar);
        centralwidget = new QWidget(StartTheGame);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        StartTheGame->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(StartTheGame);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StartTheGame->setStatusBar(statusbar);

        retranslateUi(StartTheGame);

        QMetaObject::connectSlotsByName(StartTheGame);
    } // setupUi

    void retranslateUi(QMainWindow *StartTheGame)
    {
        StartTheGame->setWindowTitle(QCoreApplication::translate("StartTheGame", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartTheGame: public Ui_StartTheGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTTHEGAME_H
