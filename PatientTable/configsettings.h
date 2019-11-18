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
    explicit configsettings(QWidget *parent = nullptr);
    ~configsettings();

private:
    Ui::configsettings *ui;
};

#endif // CONFIGSETTINGS_H
