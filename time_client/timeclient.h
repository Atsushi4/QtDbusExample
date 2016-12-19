#ifndef TIMECLIENT_H
#define TIMECLIENT_H

#include <QObject>
#include <QTime>

class QDBusInterface;
// [1]
class TimeClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QTime time READ time WRITE setTime NOTIFY timeChanged)
public:
    explicit TimeClient(QObject *parent = nullptr);

    QTime time() const;

signals:
    void adjusted(int msecs);
    void timeChanged(QTime time);

public slots:
    void adjust();
    void setTime(QTime time);

private slots:
    void updateTime(QTime time);

private:
    QDBusInterface *d;
    QTime m_time;
};
// [1]

#endif // TIMECLIENT_H
