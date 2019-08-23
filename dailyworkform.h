#ifndef DAILYWORKFORM_H
#define DAILYWORKFORM_H

#include <QWidget>

namespace Ui {
class DailyWorkForm;
}

class DailyWorkForm : public QWidget
{
    Q_OBJECT

public:
    explicit DailyWorkForm(QWidget *parent = nullptr);
    ~DailyWorkForm();

private:
    Ui::DailyWorkForm *ui;
};

#endif // DAILYWORKFORM_H
