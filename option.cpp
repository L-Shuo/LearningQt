#include "option.h"

Option::Option(QObject *parent) : QObject(parent)
{

}

void Option::setWorkspace(const QString &path)
{
    this->workspace = path;
}
