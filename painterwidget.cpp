#include "painterwidget.h"
#include "ui_painterwidget.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QDebug>

PainterWidget::PainterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PainterWidget)
{
    ui->setupUi(this);
    mousePressed = false;
    menu = new QMenu(this);
    menu->addAction(ui->saveAction);
    menu->addAction(ui->clearAction);
    connect(ui->saveAction,SIGNAL(triggered(bool)),this,SLOT(savePic()));
    connect(ui->clearAction,SIGNAL(triggered(bool)),this,SLOT(clearPic()));
}

PainterWidget::~PainterWidget()
{
    delete ui;
}

void PainterWidget::paintEvent(QPaintEvent *event)
{
    if(mousePressed)
    {
        QPainter painter(this);
        QPen pen;
        pen.setColor(Qt::red);
        pen.setWidth(5);
        painter.setPen(pen);
        QList<QVector<QPoint> *>::const_iterator ci;
        qDebug() << "list:" << qvp.count();
        for(ci=qvp.constBegin(); ci!=qvp.constEnd(); ++ci)
        {
            QVector<QPoint> *p =(QVector<QPoint> *) *ci;
            qDebug() << p->count();
            if(p->count() == 1)
            {
                painter.drawPoint(p->at(0));
            }
            for(int i=0;i<p->count()-1;i++)
            {
                painter.drawLine(p->at(i), p->at(i+1));
            }
        }

        /*if(points.count() == 1)
        {
            painter.drawPoint(points[0]);
        }
        for(int i=0; i < points.count()-1; i++)
        {
            QPoint& p1 = points[i];
            QPoint& p2 = points[i + 1];
            painter.drawLine(p1, p2);
            //qDebug("(%d,%d) - (%d,%d)", p1.x(), p1.y(), p2.x(), p2.y());
            //painter.drawPoint(points[i]);
            //qDebug() << points[i];
        }*/
    }
}

void PainterWidget::mousePressEvent(QMouseEvent *event)
{
     if(event->button() == Qt::RightButton)
     {
        //显示菜单

        mousePressed = false;
        return;
     }
     mousePressed = true;
     QVector<QPoint> *newPset = new QVector<QPoint>();
     newPset->append(event->pos());
     qvp.append(newPset);
     //points.clear();
     //points.append(event->pos());
     update();
}

void PainterWidget::mouseReleaseEvent(QMouseEvent *event)
{
    mousePressed = false;
    //points.clear();
}

void PainterWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::RightButton)  //注意这里的判断方法
    {
       return;
    }
    //points.append(event->pos());
    QVector<QPoint> *last =(QVector<QPoint> *) qvp.last();
    last->append(event->pos());
    update();
}

void PainterWidget::timerEvent(QTimerEvent *event)
{
    qDebug() << "timeevent";
    qvp.clear();
}

void PainterWidget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "contextMenuEvent(QContextMenuEvent *event)";
    //默认的标准右键菜单，如果不需要刻意完全自己实现
    menu->exec(QCursor::pos());
}

void PainterWidget::savePic()
{
    qDebug() << "savePic";
}

void PainterWidget::clearPic()
{
     qDebug() << "clearPic";
     qvp.clear();
     update();
}
