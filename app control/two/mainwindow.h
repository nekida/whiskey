#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_connect_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_sch_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_sch_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_sch_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_sch_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_sch_3_clicked();

    void on_pushButton_sch_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;

    QSerialPort *serial = nullptr;
};

#endif // MAINWINDOW_H
