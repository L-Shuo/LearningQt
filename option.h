#ifndef OPTION_H
#define OPTION_H

#include <QObject>
#include <QString>
#include <QDebug>

class Option : public QObject
{
    Q_OBJECT

public:
    explicit Option(QObject *parent = nullptr);
    static Option *getInstance();
    void setWorkspace(const QString &path);
    const QString getWorkspace() {
        qDebug() << this->workspace;
        return this->workspace;
    }
    bool need_autoReboot() {
        return autoReboot;
    }
    void set_autoReboot(bool r) {
        qDebug() << r;
        this->autoReboot = r;
    }

    bool get_autoReboot() {
        return autoReboot;
    }
signals:

public slots:
private:
     QString workspace;
     bool autoReboot;
};


#endif // OPTION_H
