#ifndef MASSWARNINGDIALOG_HPP
#define MASSWARNINGDIALOG_HPP

#include <QDialog>

namespace Ui {
class MassWarningDialog;
}

class MassWarningDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MassWarningDialog(QWidget *parent = 0);
    ~MassWarningDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MassWarningDialog *ui;
};

#endif // MASSWARNINGDIALOG_HPP
