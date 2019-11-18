#include "configsettings.h"
#include "ui_configsettings.h"

configsettings::configsettings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::configsettings)
{
    ui->setupUi(this);

    connect(ui->verticalSlider_current, &QSlider::valueChanged, ui->lcdNumber_current, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));
    connect(ui->verticalSlider_pw, &QSlider::valueChanged, ui->lcdNumber_pw, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));
    connect(ui->verticalSlider_frequency, &QSlider::valueChanged, ui->lcdNumber_frequency, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));
}

configsettings::~configsettings()
{
    delete ui;
}
