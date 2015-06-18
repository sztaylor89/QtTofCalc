#include "PhotonDialog.hpp"
#include "ui_PhotonDialog.h"

PhotonDialog::PhotonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhotonDialog)
{
    ui->setupUi(this);
}

PhotonDialog::PhotonDialog(const double &index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhotonDialog)
{
    ui->setupUi(this);
    idx_ = index;
}

PhotonDialog::~PhotonDialog()
{
    delete ui;
}

void PhotonDialog::on_buttonBox_accepted()
{
    idx_ = ui->lineEdit->text().toDouble();
}
