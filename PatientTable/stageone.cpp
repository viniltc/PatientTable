#include "stageone.h"
#include "ui_stageone.h"
#include <QDomDocument>
#include "mainwindow.h"
#include "configsettings.h"

StageOne::StageOne(QString someLabel, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StageOne)
{
    ui->setupUi(this);

//    MainWindow *mainWindow= new MainWindow(this);
    //connect(window,&MainWindow::patientIdChanged, ui->label, &QLabel::setText);  //


    ui->label->setText(someLabel);
    ui->label->setAlignment(Qt::AlignCenter);

    patientLabel = someLabel;

}

StageOne::~StageOne()
{
    delete ui;
}

void StageOne::on_pushButton_One_clicked()
{
    qDebug()<<"This is patient details"<<patientLabel;

    this->close();
    settingsWindow = new  configsettings (patientLabel, this);
    settingsWindow ->setWindowTitle("Settings window");
    settingsWindow -> show();
}
