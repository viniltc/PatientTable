#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    // Setup table
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList{"Patient ID","Name", "Surname", "LastSession"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //connect(&stagetwonew, SIGNAL(tableUpdate()), this, tabletEvent());


     QString path = QCoreApplication::applicationDirPath()+"/data/";


    //QStringList qdiFilter("entry_*.xml");
    QStringList qdiFilter("*.xml");


    QDirIterator qdi( path, qdiFilter, QDir::Files);
    while (qdi.hasNext())
    {
        parseDataEntry(qdi.next());
    }
       //qDebug()<<qdi.next();
}

void MainWindow::parseDataEntry(const QString dataPath)
{

    QString patientID, firstName, surName, lastSession = "";

    // Load our XML file.
    QFile *xmlFile;
    xmlFile = new QFile(dataPath);
    if(!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this,
                              "Error Loading Patient Data File",
                              QString("Could not load the patient XML data file at:\r\n  %0").arg(dataPath),
                              QMessageBox::Ok);
        return;
    }

    // Create an XML reader.
    QXmlStreamReader *xmlReader;
    xmlReader = new QXmlStreamReader(xmlFile);


    // Parse each element of the XML until we reach the end.
    while(!xmlReader->atEnd() && !xmlReader->hasError()) {
        // Read next element
        QXmlStreamReader::TokenType token = xmlReader->readNext();

        // If token is just StartDocument - go to next
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }

        // If token is StartElement - read it
        if(token == QXmlStreamReader::StartElement) {

            if(xmlReader->name() == "Name") {
                firstName = xmlReader->readElementText();

            } else if(xmlReader->name() == "Surname") {
                surName = xmlReader->readElementText();
            }
            else if(xmlReader->name() == "Patient_ID") {
                patientID = xmlReader->readElementText();
            }
            else if(xmlReader->name() == "Date") {
                lastSession = xmlReader->readElementText();
            }
        }
    }

    if(xmlReader->hasError()) {
        QMessageBox::critical(this,
                              "Error Parsing Patient Data File",
                              QString("Error reading the patient file at:\r\n  %0,\r\nError:  %1").arg(dataPath,
                                                                                                       xmlReader->errorString()),
                              QMessageBox::Ok);
        return;
    }


    // close reader and flush file
    xmlReader->clear();
    xmlFile->close();


    // Delete
    delete xmlFile;
    delete xmlReader;


    // Add a new row to the table, with the data we parsed.
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,
                             0,
                             new QTableWidgetItem(patientID));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,
                             1,
                             new QTableWidgetItem(firstName));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,
                             2,
                             new QTableWidgetItem(surName));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,
                             3,
                             new QTableWidgetItem(lastSession));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    MainWindow().close();
    stagetwonew = new StageTwoNew(this);
    stagetwonew->setWindowTitle("New details");
    stagetwonew-> show();

}
