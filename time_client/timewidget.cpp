#include "timewidget.h"
#include <QVBoxLayout>
#include <QTimeEdit>
#include <QPushButton>
#include <QMessageBox>

TimeWidget::TimeWidget(QWidget *parent)
    : QWidget(parent)
{
    setLayout(new QVBoxLayout());
    layout()->addWidget(timeEdit = new QTimeEdit(this));
    timeEdit->setReadOnly(true);
    timeEdit->setDisplayFormat(QStringLiteral("HH:mm:ss"));
    layout()->addWidget(button = new QPushButton(QStringLiteral("&Adjust"), this));
    connect(button, &QPushButton::clicked, this, [this]{
        button->setEnabled(false);
        emit adjustRequested();
    });
}

TimeWidget::~TimeWidget()
{

}

void TimeWidget::setTime(const QTime &time)
{
    timeEdit->setTime(time);
}

void TimeWidget::setAdjusted(int msecs)
{
    button->setEnabled(true);
    QMessageBox::information(this,
                             QStringLiteral("Adjusted"),
                             QStringLiteral("Adjusted %1 msec(s)").arg(msecs),
                             QMessageBox::Ok,
                             QMessageBox::Ok);
}
