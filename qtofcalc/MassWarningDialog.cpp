#include "MassWarningDialog.hpp"
#include "ui_MassWarningDialog.h"

MassWarningDialog::MassWarningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MassWarningDialog)
{
    ui->setupUi(this);
}

MassWarningDialog::~MassWarningDialog()
{
    delete ui;
}

void MassWarningDialog::on_pushButton_clicked()
{
    this->close();
}
