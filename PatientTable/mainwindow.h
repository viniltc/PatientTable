#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QDirIterator>
#include <QXmlStreamReader>
#include <QMessageBox>
#include "stagetwonew.h"
#include "stageone.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    StageTwoNew *stagetwonew;
    StageOne *stageone;

signals:

    void patientIdChanged(QString);


private slots:

    void on_pushButton_New_clicked();

    void on_pushButton_Open_clicked();

    void parseDataEntry(const QString dataPath);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
