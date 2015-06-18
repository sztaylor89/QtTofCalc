#include "MainWindow.hpp"
#include "PhotonDialog.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    idx_ = 1.0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qApp->quit();
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    if(checked) {
        ui->lineEdit_z->setEnabled(false);
        ui->lineEdit_a->setEnabled(false);
        PhotonDialog diag(1.0);
        diag.exec();
        idx_ = diag.GetMediumIndexRefraction();
    } else {
        ui->lineEdit_z->setEnabled(true);
        ui->lineEdit_a->setEnabled(true);
    }
}
