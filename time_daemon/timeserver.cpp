#include "timeserver.h"

#include <QThread>
#include <QtConcurrentRun>

TimeServer::TimeServer(QObject *parent)
    : QObject(parent)
{

}

QTime TimeServer::time() const
{
    return m_time;
}

void TimeServer::setTime(QTime time)
{
    if (m_time == time)
        return;

    m_time = time;
    emit timeChanged(time);
}

void TimeServer::adjust()
{
    // [8]
    QtConcurrent::run([this]{
        QThread::sleep(10);
        QMetaObject::invokeMethod(this, "adjusted", Q_ARG(int, -12)); // [9]
    });
    // [8]
}
