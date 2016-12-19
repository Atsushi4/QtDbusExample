#include <QCoreApplication>
#include <QDBusConnection>
#include <QTimer>
#include "timeserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TimeServer time(&a);
    auto bus = QDBusConnection::sessionBus();
    bus.registerService("jp.my.service"); // [6]
    bus.registerObject("/time", "jp.my.service.Time", &time, QDBusConnection::ExportAllContents); // [7]

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &time, [&time]{time.setTime(QTime::currentTime());});
    timer.start(1000);

    return a.exec();
}
