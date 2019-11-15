#include "stageone.h"
#include "ui_stageone.h"
#include "mainwindow.h"

StageOne::StageOne(QString someLabel, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StageOne)
{
    ui->setupUi(this);

//    MainWindow *mainWindow= new MainWindow(this);
//    connect(mainWindow, &MainWindow::patientIdChanged, ui->label, &QLabel::setText);  //


    ui->label->setText(someLabel);
    ui->label->setAlignment(Qt::AlignCenter);

}

StageOne::~StageOne()
{
    delete ui;
}
