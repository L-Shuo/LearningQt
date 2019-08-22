#include "fastbootcmd.h"
#include "option.h"
#include <QDebug>

FastbootCmd::FastbootCmd(QObject *parent) : QObject(parent)
{
    fastbootCmd = new QProcess();
    connect(fastbootCmd , SIGNAL(readyReadStandardOutput()) , this , SLOT(getOutput()));
    connect(fastbootCmd , SIGNAL(readyReadStandardError()) , this , SLOT(getOutput()));
}

void FastbootCmd::flash(QString &image,QString &partition)
{
    // workspace:\\172.16.195.51\liushuo2\workspace\cm01_O\out\target\product\cm01
    QString path = Option::getWorkspace();
    path.append(image);
    QString cmd = "fastboot flash " + partition+" "+ path;
    qDebug() << cmd;
    //qDebug() << this->fastbootCmd.execute(cmd);
    fastbootCmd->start(cmd);
}

void FastbootCmd::getOutput()
{
    //qDebug() << "xxxx" << fastbootCmd->readAllStandardOutput() << fastbootCmd->readAllStandardError();
    emit showInfo(fastbootCmd->readAllStandardOutput());
    emit showInfo(fastbootCmd->readAllStandardError());
}
