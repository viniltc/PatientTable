#include "patientdata.h"
#include<QString>

patientData::patientData()
{

}

patientData::parseddata patientData::parseDataEntry(const QString dataPath)
{

   // QString patientID, firstName, surName, lastSession = "";

//    struct parsedData
//    {
//        std::string firstName;
//        std::string surName;
//        std::string patientID;
//        std::string lastSession;
//        std::string note;

//    } newdata;

    //parsedData newdata;

    // Load our XML file.
    QFile *xmlFile;
    xmlFile = new QFile(dataPath);
    if(!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(0,
                              "Error Loading Patient Data File",
                              QString("Could not load the patient XML data file at:\r\n  %0").arg(dataPath),
                              QMessageBox::Ok);
       // return;
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
                newdata.firstName = xmlReader->readElementText().toStdString();

            } else if(xmlReader->name() == "Surname") {
                newdata.surName = xmlReader->readElementText().toStdString();
            }
            else if(xmlReader->name() == "Patient_ID") {
                newdata.patientID = xmlReader->readElementText().toStdString();
            }
            else if(xmlReader->name() == "Date") {
                newdata.lastSession = xmlReader->readElementText().toStdString();
            }
        }
    }

    if(xmlReader->hasError()) {
        QMessageBox::critical(0,
                              "Error Parsing Patient Data File",
                              QString("Error reading the patient file at:\r\n  %0,\r\nError:  %1").arg(dataPath,
                                                                                                       xmlReader->errorString()),
                              QMessageBox::Ok);
       // return;
    }




    // close reader and flush file
    xmlReader->clear();
    xmlFile->close();


    // Delete
    delete xmlFile;
    delete xmlReader;

    return newdata;



    // Add a new row to the table, with the data we parsed.
//    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

//    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,
//                             0,
//                             new QTableWidgetItem(patientID));
//    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,
//                             1,
//                             new QTableWidgetItem(firstName));
//    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,
//                             2,
//                             new QTableWidgetItem(surName));
//    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,
//                             3,
//                             new QTableWidgetItem(lastSession));
}
