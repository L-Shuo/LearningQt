#ifndef OPTION_H
#define OPTION_H

#include <QObject>
#include <QString>

class Option : public QObject
{
    Q_OBJECT
public:
    explicit Option(QObject *parent = nullptr);
    void setWorkspace(const QString &path);
    static const QString &getWorkspace() {
        return workspace;
    }
signals:

public slots:
private:
     static QString workspace;
};

#endif // OPTION_H
