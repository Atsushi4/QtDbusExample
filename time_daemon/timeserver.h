#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QObject>
#include <QTime>
#include <qdbusmacros.h>

// [1]
class TimeServer : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "jp.my.service.Time") // [2]
    Q_PROPERTY(QTime time READ time WRITE setTime NOTIFY timeChanged) // [3]
public:
    explicit TimeServer(QObject *parent = nullptr);
    Q_INVOKABLE QTime time() const; // [4]
signals:
    void timeChanged(QTime time);
    void adjusted(int msecs);
public slots:
    // [5]
    Q_NOREPLY void setTime(QTime time);
    Q_NOREPLY void adjust();
    // [5]
private:
    QTime m_time;
};
// [1]

#endif // TIMESERVER_H
