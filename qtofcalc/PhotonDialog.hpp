#ifndef PHOTONDIALOG_HPP
#define PHOTONDIALOG_HPP

#include <QDialog>

namespace Ui {
class PhotonDialog;
}

class PhotonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PhotonDialog(QWidget *parent = 0);
    explicit PhotonDialog(const double &index, QWidget *parent = 0);
    ~PhotonDialog();

    double GetMediumIndexRefraction(void){return(idx_);};

private slots:

    void on_buttonBox_accepted();

private:
    Ui::PhotonDialog *ui;
    bool inMedium_;
    double idx_;
};

#endif // PHOTONDIALOG_HPP
