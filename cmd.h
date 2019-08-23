#ifndef CMD_H
#define CMD_H

#include <QObject>

class Cmd : public QObject
{
    Q_OBJECT
public:
    explicit Cmd(QObject *parent = nullptr);

signals:

public slots:

private:
    QString action;
    QString value;
    QStringList arg;
};

#endif // CMD_H
