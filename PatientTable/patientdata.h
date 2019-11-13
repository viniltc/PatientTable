#ifndef PATIENTDATA_H
#define PATIENTDATA_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDirIterator>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QDomDocument>

class patientData
{
public:

     struct parsedItem
    {
        std::string firstName;
        std::string surName;
        std::string patientID;
        std::string lastSession;
        std::string note;

    }newdata;

     patientData();
     parsedItem dataFetch(const QString dataPath);
    //parseddata parseDataEntry(const QString dataPath);
};

#endif // PATIENTDATA_H
