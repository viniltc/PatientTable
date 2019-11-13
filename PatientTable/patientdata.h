#ifndef PATIENTDATA_H
#define PATIENTDATA_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDirIterator>
#include <QXmlStreamReader>
#include <QMessageBox>

class patientData
{
public:

     struct parseddata
    {
        std::string firstName;
        std::string surName;
        std::string patientID;
        std::string lastSession;
        std::string note;

    }newdata;

    patientData();
    parseddata parseDataEntry(const QString dataPath);
};

#endif // PATIENTDATA_H
