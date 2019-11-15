#ifndef STAGEONE_H
#define STAGEONE_H

#include <QMainWindow>
//#include "mainwindow.h"
#include "stagetwonew.h"

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
};

#endif // STAGEONE_H
