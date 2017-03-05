#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#include <cmath>

#include "Mass.hpp"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_clicked(bool checked);

    void on_lineEdit_z_editingFinished();

    void on_lineEdit_en_editingFinished();

    void on_lineEdit_a_editingFinished();

    void on_lineEdit_d_editingFinished();

    void on_lineEdit_t_editingFinished();

private:
    Ui::MainWindow *ui;

    bool isPhoton_, zSet_, aSet_;
    double idx_;
    double energy_, mass_, distance_,time_, c_;
    int z_, a_;
    double convUtoMeVperCperC_; //!< Conversion factor from amu to MeV/c/c

    Mass masses_;

    void SetMass(void);

    void CalcEnergy(void) {
        energy_ = 0.5*mass_*std::pow(distance_/(time_*c_),2.);
    }
    void CalcTimeOfFlight(void) {
        time_ = (distance_/c_)*std::sqrt(mass_/(2.*energy_));
    }
    void CalcDistance(void) {
        distance_ = (time_*c_)*std::sqrt((2.*energy_)/mass_);
    }

    void CalcGammaTimeOfFlight(void) {
        time_ = distance_/(c_/idx_);
    }
};

#endif // MAINWINDOW_HPP
