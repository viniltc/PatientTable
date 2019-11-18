#ifndef STAGEONE_H
#define STAGEONE_H

#include <QMainWindow>
//#include "mainwindow.h"
#include "stagetwonew.h"



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


private:
    Ui::StageOne *ui;
    MainWindow *window;
};

#endif // STAGEONE_H
