#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QList>
#include <QMenu>

namespace Ui {
class PainterWidget;
}

class PainterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PainterWidget(QWidget *parent = nullptr);
    ~PainterWidget();

protected:
    virtual void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void savePic();
    void clearPic();

private:
    Ui::PainterWidget *ui;
    bool mousePressed = false;
    //QPainter pen;
    //QPoint curPoint;
    //QVector<QPoint> points;
    QList<QVector<QPoint> *> qvp;
    QMenu *menu;
};

#endif // PAINTERWIDGET_H
