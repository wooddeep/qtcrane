#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>

#include "craneoverlook.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QHBoxLayout * horizontalLayout = new QHBoxLayout(this);
    //this->setLayout(horizontalLayout);

    //this->layout()->addWidget(new CraneOverlook(this));

    CraneOverlook *circle = new CraneOverlook(ui->anti_colli_show);
    circle->setMaximumWidth(100);
    circle->setMaximumHeight(100);

    //ui->anti_colli_show->layout()->addWidget(circle);


    //QGridLayout *layout = (QGridLayout*)ui->anti_colli_show->layout();

    //layout->addWidget(circle, 0, 0);

    circle->move(100, 100);

    CraneOverlook *circle1 = new CraneOverlook(ui->anti_colli_show);
    circle1->setMaximumWidth(100);
    circle1->setMaximumHeight(100);

    circle1->setAttribute(90, 40, 10);
    circle1->move(0, 0);

    circle1->update();

    //horizontalLayout->addWidget(new CraneOverlook(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
