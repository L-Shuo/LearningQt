#ifndef ABOUTDIAG_H
#define ABOUTDIAG_H

#include <QDialog>

namespace Ui {
class AboutDiag;
}

class AboutDiag : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDiag(QWidget *parent = nullptr);
    ~AboutDiag();

private slots:
    void on_okButton_clicked();

private:
    Ui::AboutDiag *ui;
};

#endif // ABOUTDIAG_H
