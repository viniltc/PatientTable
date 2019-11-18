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

StageOne::~StageOne()
{
    delete ui;
}

void StageOne::on_pushButton_One_clicked()
{
    this->close();
    settingsWindow = new  configsettings (this);
    settingsWindow ->setWindowTitle("Settings window");
    settingsWindow -> show();
}
