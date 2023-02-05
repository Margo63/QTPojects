#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "kitchen.h"
#include <QDebug>
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<Kitchen>("Kitchen",1,0,"Kitchen");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


  //  QObject* root = engine.rootObjects().first();//this->parent()->findChild<QObject*>("password");
    //;

//    QObject* obj=engine.rootObjects().first()->findChild<QObject*>("naaame");
//    qDebug()<<obj->objectName();
//    Game game;
//    QObject::connect(obj,SIGNAL(clicked()),&game,SLOT(doSmt()));


    return app.exec();
}
