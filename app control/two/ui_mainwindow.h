/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_close;
    QComboBox *comboBox_com;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton_sch;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_sch_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_sch_3;
    QPushButton *pushButton_sch_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_sch_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_sch_6;
    QLabel *label_5;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(707, 267);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(620, 100, 80, 25));
        pushButton_close = new QPushButton(centralWidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setGeometry(QRect(620, 130, 80, 25));
        comboBox_com = new QComboBox(centralWidget);
        comboBox_com->setObjectName(QStringLiteral("comboBox_com"));
        comboBox_com->setGeometry(QRect(530, 100, 75, 24));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(520, 70, 101, 21));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(520, 30, 61, 25));
        spinBox->setMinimum(10);
        spinBox->setMaximum(10000);
        spinBox->setSingleStep(10);
        pushButton_sch = new QPushButton(centralWidget);
        pushButton_sch->setObjectName(QStringLiteral("pushButton_sch"));
        pushButton_sch->setGeometry(QRect(10, 10, 161, 41));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(530, 130, 81, 25));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 60, 161, 41));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(350, 10, 161, 41));
        pushButton_sch_2 = new QPushButton(centralWidget);
        pushButton_sch_2->setObjectName(QStringLiteral("pushButton_sch_2"));
        pushButton_sch_2->setGeometry(QRect(10, 110, 161, 41));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(180, 110, 161, 41));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(180, 60, 161, 41));
        pushButton_sch_3 = new QPushButton(centralWidget);
        pushButton_sch_3->setObjectName(QStringLiteral("pushButton_sch_3"));
        pushButton_sch_3->setGeometry(QRect(350, 60, 161, 41));
        pushButton_sch_4 = new QPushButton(centralWidget);
        pushButton_sch_4->setObjectName(QStringLiteral("pushButton_sch_4"));
        pushButton_sch_4->setGeometry(QRect(180, 160, 161, 41));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 160, 161, 41));
        pushButton_sch_5 = new QPushButton(centralWidget);
        pushButton_sch_5->setObjectName(QStringLiteral("pushButton_sch_5"));
        pushButton_sch_5->setGeometry(QRect(180, 10, 161, 41));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(350, 160, 161, 41));
        pushButton_sch_6 = new QPushButton(centralWidget);
        pushButton_sch_6->setObjectName(QStringLiteral("pushButton_sch_6"));
        pushButton_sch_6->setGeometry(QRect(350, 110, 161, 41));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(520, 10, 61, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 707, 20));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_connect->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        pushButton_close->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\277\320\276\321\200\321\202\320\260", nullptr));
        pushButton_sch->setText(QApplication::translate("MainWindow", "Regular", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Off", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Up down on - all off", nullptr));
        pushButton_sch_2->setText(QApplication::translate("MainWindow", "Blink all", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Up down on - up down off", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Up down on - down up off", nullptr));
        pushButton_sch_3->setText(QApplication::translate("MainWindow", "Down up on - all off", nullptr));
        pushButton_sch_4->setText(QApplication::translate("MainWindow", "Down up on - down up off", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "Chaos", nullptr));
        pushButton_sch_5->setText(QApplication::translate("MainWindow", "Down up on - up down off", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "Round down", nullptr));
        pushButton_sch_6->setText(QApplication::translate("MainWindow", "Round up", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260", nullptr));
        menu->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
