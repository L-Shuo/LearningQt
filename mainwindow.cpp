#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdiag.h"
#include <QDebug>
#include <QFileDialog>
#include <QTextEdit>
#include <QTextBlock>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    qDebug() << "Open file";
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open file"), "C:\\Users\\liushuo\\Desktop", tr("Files (*.txt)"));
    qDebug() << fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QDialog diag(this);
        diag.setWindowTitle("Open file failed!!!");
        diag.resize(QSize(300,30));
        diag.exec();
        return;
    }

    if(file.exists()) {
        QByteArray line;
        while (!file.atEnd()) {
            line = file.readLine();
            line.remove(line.indexOf('\n'),1); //remove /n
            ui->plainTextEdit->appendPlainText(line);
        }
    }
    ui->plainTextEdit->show();
    connect(ui->plainTextEdit,SIGNAL(textChanged()),this,SLOT(textChanged()));
}

void MainWindow::on_actionClose_triggered()
{
    on_actionSave_triggered();
    disconnect(ui->plainTextEdit,SIGNAL(textChanged()),this,SLOT(textChanged()));
    ui->plainTextEdit->close();
    qDebug() << "Close file";
}

void MainWindow::on_actionSave_triggered()
{
    if(m_textChanged)
    {
        qDebug() << "Save file";
        QString fileName = QFileDialog::getSaveFileName(this,
            tr("Open file"), "C:\\Users\\liushuo\\Desktop\\save.txt", tr("Files (*.txt)"));
        qDebug() << fileName;
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            QTextDocument *td = ui->plainTextEdit->document();
            QTextBlock textBlock;
            for(textBlock=td->begin();textBlock!=td->end();textBlock=textBlock.next()){
                    out << textBlock.text() << endl;
            }
            return;
        }
        m_textChanged = false;
    }
}

void MainWindow::on_actionAbout_triggered()
{
    qDebug() << "About...";
    AboutDiag ad(this);
    ad.exec();
}

void MainWindow::textChanged()
{
    qDebug() << "Text Changed!!!";
    m_textChanged = true;
}
