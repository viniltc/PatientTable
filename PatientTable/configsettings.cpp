#include "configsettings.h"
#include "ui_configsettings.h"

configsettings::configsettings(QString someLabel,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::configsettings)
{
    ui->setupUi(this);

    ui->label_patient->setText(someLabel);
    ui->label_patient->setAlignment(Qt::AlignCenter);


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
    //    if (someLabel.length()!=0)
    //    {
    //    QDomDocument xml("tetragrip");
    //    QString filename = someLabel;
    //    QString path = QCoreApplication::applicationDirPath()+"/data/"+filename+".xml";
    //    QFile file(path);

    //    if(!file.open(QFile::WriteOnly | QFile::Text))
    //    {
    //        qDebug () << "Error saving XML file...."; // replace this with Q Messange box later!!!!!!!!!!!
    //        file.close();
    //        return;
    //    }

    //    QDomElement root = xml.createElement("settings");
    //    xml.appendChild(root);

    //    QDomElement tagName = xml.createElement("Current");
    //    root.appendChild(tagName);
    //    QDomText textName = xml.createTextNode("sample text here to check");
    //    tagName.appendChild(textName);

    //    QTextStream output(&file);
    //    output << xml.toString();


    //    file.close();

    //    }
}
