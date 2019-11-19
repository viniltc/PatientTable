#ifndef STAGEONE_H
#define STAGEONE_H

#include <QMainWindow>
//#include "mainwindow.h"
#include "stagetwonew.h"
#include "configsettings.h"



class MainWindow;
namespace Ui {
class StageOne;
}

class StageOne : public QMainWindow
{
    Q_OBJECT

public:
    explicit StageOne(QString, QWidget *parent = nullptr);
    ~StageOne();
    configsettings *settingsWindow;
    QString patientLabel;



private slots:
    void on_pushButton_One_clicked();

private:
    Ui::StageOne *ui;
    MainWindow *window;
};

#endif // STAGEONE_H
