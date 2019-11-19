#ifndef CONFIGSETTINGS_H
#define CONFIGSETTINGS_H

#include <QMainWindow>

namespace Ui {
class configsettings;
}

class configsettings : public QMainWindow
{
    Q_OBJECT

public:
    explicit configsettings(QString, QWidget *parent = nullptr);
    ~configsettings();

private slots:
    void on_pushButton_save_clicked();

private:
    Ui::configsettings *ui;
};

#endif // CONFIGSETTINGS_H
