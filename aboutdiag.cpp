#include "aboutdiag.h"
#include "ui_aboutdiag.h"

AboutDiag::AboutDiag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDiag)
{
    ui->setupUi(this);
}

AboutDiag::~AboutDiag()
{
    delete ui;
}

void AboutDiag::on_okButton_clicked()
{
    this->accept();
}
