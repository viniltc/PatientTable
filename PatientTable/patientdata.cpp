#include "patientdata.h"
#include<QString>

patientData::patientData()
{

}

patientData::parsedItem patientData::dataFetch(const QString dataPath)
{

    QDomDocument domDocument;
    QString  errorMsg;
    int errorLine,errorColumn;


       // Open a file for reading
       QFile file(dataPath);
       if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
       qDebug() << "Failed to open the file for reading.";
       }

       else
       {
           if(!domDocument.setContent(&file,&errorMsg, &errorLine, &errorColumn))
           {
               qDebug () << file<<errorMsg << errorLine << errorColumn;
               qDebug() << "Failed to load the file for reading.";
           }

           file.close();
       }

       qDebug() << "Reading finished";

       domDocument.setContent(&file);
       QDomElement topElement = domDocument.documentElement();
       QDomNode domNode = topElement.elementsByTagName("Name").at(0).firstChild();

       QString name = topElement.elementsByTagName("Name").at(0).firstChild().nodeValue();
       newdata.firstName = name.toStdString();
       QString sname= topElement.elementsByTagName("Surname").at(0).firstChild().nodeValue();
       newdata.surName = sname.toStdString();
       QString Pnote = topElement.elementsByTagName("Clinician_Note").at(0).firstChild().nodeValue();
       newdata.note=Pnote.toStdString();
       QString pID = topElement.elementsByTagName("Patient_ID").at(0).firstChild().nodeValue();
       newdata.patientID = name.toStdString();
       QString dateTime= topElement.elementsByTagName("Date").at(0).firstChild().nodeValue();
       newdata.lastSession = dateTime.toStdString();


       return newdata;
}


