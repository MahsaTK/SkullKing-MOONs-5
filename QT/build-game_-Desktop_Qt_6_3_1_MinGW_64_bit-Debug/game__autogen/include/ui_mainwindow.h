/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QPushButton *loginOk;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *signUpOk;
    QPushButton *forgotPassword;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(903, 669);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(903, 669));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
""));
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setCursor(QCursor(Qt::ArrowCursor));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        centralwidget->setAutoFillBackground(false);
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        loginOk = new QPushButton(centralwidget);
        loginOk->setObjectName(QString::fromUtf8("loginOk"));

        gridLayout->addWidget(loginOk, 3, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setAutoFillBackground(false);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        signUpOk = new QPushButton(centralwidget);
        signUpOk->setObjectName(QString::fromUtf8("signUpOk"));

        gridLayout->addWidget(signUpOk, 2, 0, 1, 1);

        forgotPassword = new QPushButton(centralwidget);
        forgotPassword->setObjectName(QString::fromUtf8("forgotPassword"));

        gridLayout->addWidget(forgotPassword, 4, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::FieldRole, gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 903, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Skull king", nullptr));
        loginOk->setText(QCoreApplication::translate("MainWindow", "OK ", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Register Account", nullptr));
        signUpOk->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        forgotPassword->setText(QCoreApplication::translate("MainWindow", "Forgot Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
