#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#include <cmath>

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

private:
    Ui::MainWindow *ui;
    double idx_;
    double energy_, mass_, distance_,time_, c_;


    void CalcEnergy(void) {
        energy_ = 0.5*mass_*std::pow(distance_/(time_*c_),2.);
    }
    void CalcTimeOfFlight(void) {
        time_ = (distance_/c_)*std::sqrt(mass_/(2.*energy_));
    }
    void CalcDistance(void) {
        distance_ = (time_*c_)*std::sqrt((2.*energy_)/mass_);
    }
};

#endif // MAINWINDOW_HPP
