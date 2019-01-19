#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickView>
#include "../tools/locationfinder.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif


    LocationFinder * f = new LocationFinder();


    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<LocationFinder>("io.qt.locationfinder",1,0,"LocationFinder");
    QQuickView view;
    view.engine()->rootContext()->setContextProperty("LocationFinder", f);
   // view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));                 //Xingwen: Lines 24-25 were creating duplicate GUI windows
    //view.show();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
