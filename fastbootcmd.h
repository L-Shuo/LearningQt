#ifndef FASTBOOTCMD_H
#define FASTBOOTCMD_H

#include <QObject>
#include <QProcess>

class FastbootCmd : public QObject
{
    Q_OBJECT
public:
    explicit FastbootCmd(QObject *parent = nullptr);
    void flash(QString &image, QString &partition);
signals:
    void showInfo(QString info);

public slots:
    void getOutput();
private:
    QProcess *fastbootCmd;
};

#endif // FASTBOOTCMD_H
