#include "option.h"

Q_GLOBAL_STATIC(Option,OptionInstance);

Option::Option(QObject *parent) : QObject(parent)
{

}

void Option::setWorkspace(const QString &path)
{
    this->workspace = path;
}

Option *Option::getInstance() {
    return OptionInstance;
}
