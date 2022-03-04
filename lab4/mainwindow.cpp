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
    /*QVector<double> a2(4), ay2(31);                                                                                 QVector<double> x(10), y(10);

    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(a2, ay2);
    ui->widget->addGraph();
*/

    QVector<double> x(100), y(100);

    double t = 0;
    for (int i = 0; i < 100; i++) {
        x[i] = t;
        t += 0.1;
    }
    for (int i = 0; i < 100; i++) {
        y[i] = 1 - pow(2.71, -x[i]);
    }
    //x = {0, 0.2, 0.4, 0.6, 0.8, 1, 1.2, 1.4, 1.6};
    //y = {0, 0.2, 0.5, 0.6, 0.7, 0.8, 0.85, 0.87, 0.9, 0.9, 0.9, 0.9, 0.9};

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->graph(0)->setPen(QColor(Qt::blue));
    //ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    //ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    ui->widget->xAxis->setRange(0, 10);
    ui->widget->yAxis->setRange(0, 1);

    ui->widget->replot();
}
