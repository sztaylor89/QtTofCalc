#include <iostream>

#include "MassWarningDialog.hpp"
#include "MainWindow.hpp"
#include "PhotonDialog.hpp"
#include "ui_MainWindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    idx_ = 1.0;
    convUtoMeVperCperC_ = 931.4941;
    c_ = 29.9792458; //! Speed of light in m/s
    distance_ = time_ = energy_ = 0.0;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    qApp->quit();
}

void MainWindow::on_checkBox_clicked(bool checked) {
    if(checked) {
        ui->lineEdit_z->setEnabled(false);
        ui->lineEdit_a->setEnabled(false);
        ui->lineEdit_m->setEnabled(false);
        ui->lineEdit_en->setEnabled(false);
        PhotonDialog diag(1.0);
        diag.exec();
        idx_ = diag.GetMediumIndexRefraction();
        isPhoton_ = true;
        mass_ = 0.0;
    } else {
        ui->lineEdit_en->setEnabled(true);
        ui->lineEdit_z->setEnabled(true);
        ui->lineEdit_a->setEnabled(true);
        ui->lineEdit_m->setEnabled(true);
        isPhoton_ = false;
    }
}

void MainWindow::on_lineEdit_z_editingFinished() {
    zSet_ = true;
    SetMass();
}

void MainWindow::on_lineEdit_a_editingFinished() {
    aSet_ = true;
    SetMass();
}

void MainWindow::SetMass() {
    a_ = ui->lineEdit_a->text().toInt();
    z_ = ui->lineEdit_z->text().toInt();
    mass_ = masses_.GetMass(z_, a_) * convUtoMeVperCperC_;
    ui->lineEdit_m->setText(QString::number(mass_));
}

void MainWindow::on_lineEdit_en_editingFinished() {
    QString txt;
    energy_ = ui->lineEdit_en->text().toDouble();
    if(mass_ != 0.0) {
        if(distance_ != 0) {
            CalcTimeOfFlight();
            txt = QString::number(time_);
            ui->lineEdit_t->selectAll();
            ui->lineEdit_t->insert(txt);
        } else if(time_ != 0) {
            CalcDistance();
            txt = QString::number(distance_);
            ui->lineEdit_d->selectAll();
            ui->lineEdit_d->insert(txt);
        }
    }
}

void MainWindow::on_lineEdit_d_editingFinished()
{
    QString txt;
    distance_ = ui->lineEdit_d->text().toDouble();
    if(mass_ != 0.0) {
        if(energy_ != 0) {
            CalcTimeOfFlight();
            txt = QString::number(time_);
            ui->lineEdit_t->selectAll();
            ui->lineEdit_t->insert(txt);
        } else if(time_ != 0) {
            CalcEnergy();
            txt = QString::number(energy_);
            ui->lineEdit_en->selectAll();
            ui->lineEdit_en->insert(txt);
        }
    } else {
        CalcGammaTimeOfFlight();
        txt = QString::number(time_);
        ui->lineEdit_t->selectAll();
        ui->lineEdit_t->insert(txt);
    }
}

void MainWindow::on_lineEdit_t_editingFinished()
{
    QString txt;
    time_ = ui->lineEdit_t->text().toDouble();
    if(mass_ != 0.0) {
        if(distance_ != 0) {
            CalcEnergy();
            txt = QString::number(energy_);
            ui->lineEdit_en->selectAll();
            ui->lineEdit_en->setText(txt);
        } else if(energy_ != 0) {
            CalcDistance();
            txt = QString::number(distance_);
            ui->lineEdit_d->selectAll();
            ui->lineEdit_d->setText(txt);
        }
    }
}
