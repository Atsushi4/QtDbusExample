#include "timeclient.h"
#include "timewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TimeClient c;
    TimeWidget w;
    QObject::connect(&c, &TimeClient::timeChanged, &w, &TimeWidget::setTime);
    QObject::connect(&w, &TimeWidget::adjustRequested, &c, &TimeClient::adjust);
    QObject::connect(&c, &TimeClient::adjusted, &w, &TimeWidget::setAdjusted);
    w.setTime(c.time());
    w.show();

    return a.exec();
}
