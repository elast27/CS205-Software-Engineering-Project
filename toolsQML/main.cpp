#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickView>
#include "message.h"


    int main(int argc, char *argv[]) {
        QGuiApplication app(argc, argv);

        QQuickView view;
        Message msg;
        view.engine()->rootContext()->setContextProperty("msg", &msg);
        view.setSource(QUrl::fromLocalFile("/qrc:/MyMessage.qml"));
        view.show();

        return app.exec();
    }
