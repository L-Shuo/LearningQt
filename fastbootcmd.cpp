#include "fastbootcmd.h"
#include "option.h"
#include <QDebug>

FastbootCmd::FastbootCmd(QObject *parent) : QObject(parent)
{
    fastbootCmd = new QProcess();
    cmdMap.insert("flash boot","fastboot flash boot boot.img");
    cmdMap.insert("flash system","fastboot flash system system.img");
    cmdMap.insert("flash modem","fastboot flash modem NON-HLOS.bin");
    cmdMap.insert("flash userdata","fastboot flash userdata userdata.img");
    cmdMap.insert("flash bootloader","fastboot flash aboot emmc_appsboot.mbn");
    cmdMap.insert("flash vendor","fastboot flash vendor vendor.img");

    connect(fastbootCmd , SIGNAL(readyReadStandardOutput()) , this , SLOT(getOutput()));
    connect(fastbootCmd , SIGNAL(readyReadStandardError()) , this , SLOT(getOutput()));
}

void FastbootCmd::flash(QString &image,QString &partition)
{
    // workspace:\\172.16.195.51\liushuo2\workspace\cm01_O\out\target\product\cm01
    QString path = Option::getInstance()->getWorkspace();
    path.append(image);
    QString cmd = "fastboot flash " + partition+" "+ path;
    qDebug() << cmd;
    fastbootCmd->start(cmd);
}

void FastbootCmd::getOutput()
{
    qDebug() << "###getOutPut";
    emit showInfo(fastbootCmd->readAllStandardOutput());
    emit showInfo(fastbootCmd->readAllStandardError());
    if(Option::getInstance()->get_autoReboot())
        fastbootCmd->execute("fastboot reboot");
}

void FastbootCmd::execCmd(QString cmd)
{
    //qDebug() << "execCmd" + cmd;
    if(cmdMap.contains(cmd))
    {
        QProcess q;
        QStringList list = cmdMap[cmd].split(' ');
        //qDebug() << list.at(0)+ " " + list.at(1)+ " " + list.at(2) + " " + Option::getInstance()->getWorkspace() + list.last();
        int error = q.execute("adb reboot-bootloader");
        if(error) {
            //return;
        }
        fastbootCmd->start(list.at(0)+ " " + list.at(1)+ " " + list.at(2) + " " + Option::getInstance()->getWorkspace() + list.last());
    }
    else
    {

    }
}
