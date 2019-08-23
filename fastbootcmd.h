#ifndef FASTBOOTCMD_H
#define FASTBOOTCMD_H

#include <QObject>
#include <QProcess>
#include <QMap>

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
    void execCmd(QString cmd);

private:
    QProcess *fastbootCmd;
    QMap<QString,QString> cmdMap;
};

#endif // FASTBOOTCMD_H
