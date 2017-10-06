#ifndef DIALOGLEFDEF_H
#define DIALOGLEFDEF_H

#include <QDialog>
#include <QString>
#include <iostream>

#include "ui_dialoglefdef.h"
#include "control/application.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class DialogLefDef;
}

class DialogLefDef : public QDialog
{
    Q_OBJECT

    apps::Application *mApp{nullptr};

public:
    explicit DialogLefDef(QWidget *parent = 0);
    DialogLefDef(QWidget *parent, apps::Application *app);
    ~DialogLefDef();

private slots:
    void on_chooseLef_clicked();

    void on_chooseDef_clicked();

    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_chooseVerilog_clicked();

private:
    Ui::DialogLefDef *ui;

};

#endif // DIALOGLEFDEF_H