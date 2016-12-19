#include "timeclient.h"
#include <QDBusInterface>
#include <QDBusConnection>

TimeClient::TimeClient(QObject *parent)
    : QObject(parent)
    // [2]
    , d(new QDBusInterface(QStringLiteral("jp.my.service"),
                           QStringLiteral("/time"),
                           QStringLiteral("jp.my.service.Time"),
                           QDBusConnection::sessionBus()))
    // [2]
{
    connect(d, SIGNAL(timeChanged(QTime)), this, SLOT(updateTime(QTime))); // [3]
    connect(d, SIGNAL(adjusted(int)), this, SIGNAL(adjusted(int)));
    updateTime(d->property("time").toTime()); // [4]
}

QTime TimeClient::time() const
{
    return m_time;
}

void TimeClient::adjust()
{
    d->call(QStringLiteral("adjust"));
}

void TimeClient::setTime(QTime time)
{
    if (m_time == time)
        return;

    d->call(QStringLiteral("setTime"), time);
}

// [5]
void TimeClient::updateTime(QTime time)
{
    if (m_time == time)
        return;

    m_time = time;
    emit timeChanged(time);
}
// [5]
