#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double res = menu();

    QVector<double> a2(4), ay2(31);                                                                                 QVector<double> x(10), y(10);
    a2 = {6, 2.3, 1.6999999, 0.79999999};
    for (int i = 0; i < 31; i++) {
        ay2[i] = a2[0] + a2[1] * ax[i] + a2[2] * ax[i] * ax[i] + a2[3] * ax[i] * ax[i] * ax[i];
    }

    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(ax, ay1);
    ui->widget->addGraph();
    ui->widget->graph(1)->setData(ax, ay2);
    ui->widget->graph(1)->setPen(QPen("red"));


    QVector<double> x(9), y(9);

    x = {-5, -4, -3, -2, -1, 0, 1, 2, 3};
    y = {-63, -27.2, -7.2, 1.8, 4.6, 6, 10.8, 23.8, 49.8};

    ui->widget->addGraph();
    ui->widget->graph(1)->setData(x, y);
    ui->widget->graph(1)->setPen(QColor(50, 50, 50, 255));
    ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    ui->widget->xAxis->setRange(-6, 4);
    ui->widget->yAxis->setRange(-65, 50);

    ui->widget->replot();
}


void MainWindow::on_pushButton_clicked()
{
    QVector<double> a1(4), ax(31), ay1(31);
    a1 = {6, 2.3, 1.6999999, 0.79999999};
    ax = {-15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0,
         1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    for (int i = 0; i < 31; i++) {
        ay1[i] = a1[0] + a1[1] * ax[i] + a1[2] * ax[i] * ax[i] + a1[3] * ax[i] * ax[i] * ax[i];
    }

    QVector<double> a2(4), ay2(31);
    a2 = {6, 2.3, 1.6999999, 0.79999999};
    for (int i = 0; i < 31; i++) {
        ay2[i] = a2[0] + a2[1] * ax[i] + a2[2] * ax[i] * ax[i] + a2[3] * ax[i] * ax[i] * ax[i];
    }

    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(ax, ay1);
    ui->widget->addGraph();
    ui->widget->graph(1)->setData(ax, ay2);
    ui->widget->graph(1)->setPen(QPen("red"));


    QVector<double> x(9), y(9);

    x = {-5, -4, -3, -2, -1, 0, 1, 2, 3};
    y = {-63, -27.2, -7.2, 1.8, 4.6, 6, 10.8, 23.8, 49.8};

    ui->widget->addGraph();
    ui->widget->graph(2)->setData(x, y);
    ui->widget->graph(2)->setPen(QColor(50, 50, 50, 255));
    ui->widget->graph(2)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    ui->widget->xAxis->setRange(-6, 4);
    ui->widget->yAxis->setRange(-65, 50);

    ui->widget->replot();
}
