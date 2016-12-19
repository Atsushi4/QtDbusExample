#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QTime>
#include <QWidget>

class QTime;
class QTimeEdit;
class QPushButton;

class TimeWidget : public QWidget
{
    Q_OBJECT

public:
    TimeWidget(QWidget *parent = 0);
    ~TimeWidget();

signals:
    void adjustRequested();

public slots:
    void setTime(const QTime &time);
    void setAdjusted(int msecs);

private:
    QTimeEdit *timeEdit;
    QPushButton *button;
};

#endif // TIMEWIDGET_H
