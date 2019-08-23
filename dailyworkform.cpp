#include "dailyworkform.h"
#include "ui_dailyworkform.h"

DailyWorkForm::DailyWorkForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DailyWorkForm)
{
    ui->setupUi(this);
}

DailyWorkForm::~DailyWorkForm()
{
    delete ui;
}
