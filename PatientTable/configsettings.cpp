#include "configsettings.h"
#include "ui_configsettings.h"
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

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
        QString PWVal = QString::number(ui->verticalSlider_pw->value());
        QString FreqVal = QString::number(ui->verticalSlider_frequency->value());


        QString filename = patientName;
        QString path = QCoreApplication::applicationDirPath()+"/data/"+filename+".xml";
        QFile file(path);

        /* QT Append wont work!
         * Open the file read-only, read it all in, close it.
         * Make changes in-memory document.
         * Then open the file for overwrite, write all content, close file. */

        if(!file.open(QIODevice::ReadOnly  | QIODevice::Text))
        {
            qDebug () << "Error saving XML file....";
            QMessageBox::information(this, "Unable to open file for read", file.errorString());
            return;
        }

        QDomDocument document;
        document.setContent(&file);
        QDomElement root = document.documentElement();
//        qDebug()<<root.elementsByTagName("Name").at(0).firstChild().nodeValue();
//        qDebug()<<root.elementsByTagName("Surname").at(0).firstChild().nodeValue();

        file.close();


        QDomElement newTag = document.createElement(QString("Settings"));


        QDomElement newCurrTag = document.createElement(QString("Current"));
        QDomText newCurrVal = document.createTextNode(currVal);
        newCurrTag.appendChild(newCurrVal);
        newTag.appendChild(newCurrTag);

        QDomElement newPWTag = document.createElement(QString("PW"));
        QDomText newPWVal = document.createTextNode(PWVal);
        newPWTag.appendChild(newPWVal);
        newTag.appendChild(newPWTag);

        QDomElement newFreqTag = document.createElement(QString("Freq"));
        QDomText newFreqVal = document.createTextNode(FreqVal);
        newFreqTag.appendChild(newFreqVal);
        newTag.appendChild(newFreqTag);


        //se


        root.appendChild(newTag);


        if(!file.open(QIODevice::WriteOnly  | QIODevice::Text))
        {
            qDebug () << "Error saving XML file....";
            QMessageBox::information(this, "Unable to open file for write", file.errorString());
            return;
        }

        QTextStream output(&file);
        output << document.toString();
        file.close();

        qDebug()<< "Finished";

}
