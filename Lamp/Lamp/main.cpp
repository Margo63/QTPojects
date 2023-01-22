#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "lamp.h" // подключение класса lamp

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<Lamp>("ImportNameLamp",1,0,"ObjectNameLamp");//регистрация нового типа, в треугольных скобках указывается класс
                          //первый аргумент - имя для импорта; второй,третий - версия; четвертый - имя объекта

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
