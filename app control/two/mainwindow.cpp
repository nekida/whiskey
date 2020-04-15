#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QTextCodec>
#include <QTimer>
#include <QThread>
#include <QByteArray>

typedef enum{
    REGULAR = 1,
    OFF,
    BLINK_ALL,
    UP_DOWN_ON__ALL_OFF,
    DOWN_UP_ON__ALL_OFF,
    UP_DOWN_ON__UP_DOWN_OFF,
    DOWN_UP_ON__DOWN_UP_OFF,
    UP_DOWN_ON__DOWN_UP_OFF,
    DOWN_UP_ON__UP_DOWN_OFF,
    CHAOS,
    ROUND_UP,
    ROUND_DOWN
} mode;

uint8_t tx_array[3] = {0};
uint16_t msg_delay = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serial(new QSerialPort(this))
{
    ui->setupUi(this);

    //read avaible comports
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->comboBox_com->addItem(info.portName());   
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_connect_clicked()
{
    //select name for our serial port from combobox
    if (serial->portName() != ui->comboBox_com->currentText())
    {
          serial->close();
          serial->setPortName(ui->comboBox_com->currentText());
          //ui->label->setText("Порт закрыт");
    }
  //setup COM port
        serial->setBaudRate(115200);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        serial->open(QSerialPort::ReadWrite);

        ui->label->setText("Порт открыт");
}

void MainWindow::on_pushButton_close_clicked()
{
    //close
    serial->close();
    ui->label->setText("Порт закрыт");
}

void MainWindow::on_pushButton_sch_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = REGULAR;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}

void MainWindow::on_pushButton_clicked()
{
    ui->comboBox_com->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->comboBox_com->addItem(info.portName());
}

void MainWindow::on_pushButton_2_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = OFF;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}

void MainWindow::on_pushButton_sch_2_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = BLINK_ALL;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}

void MainWindow::on_pushButton_3_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = UP_DOWN_ON__ALL_OFF;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}

void MainWindow::on_pushButton_6_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = CHAOS;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}

void MainWindow::on_pushButton_sch_6_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = ROUND_UP;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}

void MainWindow::on_pushButton_7_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = ROUND_DOWN;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}

void MainWindow::on_pushButton_sch_5_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = DOWN_UP_ON__UP_DOWN_OFF;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}

void MainWindow::on_pushButton_4_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = UP_DOWN_ON__UP_DOWN_OFF;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}

void MainWindow::on_pushButton_sch_3_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = DOWN_UP_ON__ALL_OFF;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}

void MainWindow::on_pushButton_sch_4_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = DOWN_UP_ON__DOWN_UP_OFF;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}

void MainWindow::on_pushButton_5_clicked()
{
    msg_delay = ui->spinBox->value();

    tx_array[0] = UP_DOWN_ON__DOWN_UP_OFF;
    tx_array[1] = msg_delay;
    tx_array[2] = (msg_delay >> 8);

    for(int i=0; i<3; i++)
        serial->putChar(tx_array[i]);

    for(int i=0; i<3; i++)
        tx_array[i] = 0;
}
