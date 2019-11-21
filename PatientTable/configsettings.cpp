#include "configsettings.h"
#include "ui_configsettings.h"
#include <QDomDocument>
#include <QFile>
#include <QDebug>

configsettings::configsettings(QString someLabel,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::configsettings)
{
    ui->setupUi(this);

    ui->label_patient->setText(someLabel);
    ui->label_patient->setAlignment(Qt::AlignCenter);
    patientName = someLabel;


    connect(ui->verticalSlider_current, &QSlider::valueChanged, ui->lcdNumber_current, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));
    connect(ui->verticalSlider_pw, &QSlider::valueChanged, ui->lcdNumber_pw, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));
    connect(ui->verticalSlider_frequency, &QSlider::valueChanged, ui->lcdNumber_frequency, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));


}

configsettings::~configsettings()
{
    delete ui;
}

void configsettings::on_pushButton_save_clicked()
{

        QString currVal = QString::number(ui->verticalSlider_current->value());



        QDomDocument document;
        QString filename = patientName;


        qDebug()<<"file name is:"<<currVal;


        QString path = QCoreApplication::applicationDirPath()+"/data/"+filename+".xml";

        qDebug()<<"\nComplete path is:"<<path;

        QFile file(path);

        if(!file.open(QIODevice::ReadOnly  | QIODevice::Text))
        {
            qDebug () << "Error saving XML file...."; // replace this with Q Messange box later!!!!!!!!!!!
            return;

        }


        document.setContent(&file);
        QDomElement root = document.documentElement();
        qDebug()<<root.elementsByTagName("Name").at(0).firstChild().nodeValue();
        qDebug()<<root.elementsByTagName("Surname").at(0).firstChild().nodeValue();

        file.close();

        QDomElement newTag = document.createElement(QString("Settings"));
        QDomElement newCurrTag = document.createElement(QString("Current"));
        QDomText newCurrVal = document.createTextNode(currVal);
        newCurrTag.appendChild(newCurrVal);
        newTag.appendChild(newCurrTag);
        root.appendChild(newTag);

        file.open(QIODevice::WriteOnly | QIODevice::Text);

        QTextStream output(&file);
        output << document.toString();


        file.close();




        qDebug()<< "Finished";

}
