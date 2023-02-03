#ifndef MOUSE_H
#define MOUSE_H

#include <QObject>

class Mouse:public QObject
{
    Q_OBJECT
    Q_PROPERTY(double x READ x NOTIFY positionChanged); // свойство x
    Q_PROPERTY(double y READ y NOTIFY positionChanged); // свойство y
public:
    explicit Mouse(QObject* parent = nullptr);//конструктор
    double x()const;//геттер для x
    double y()const;//геттер для y

public slots:
    void changePosition(double x, double y);//метод для изменения позиции
signals:
    void positionChanged();//сигнал что позиция изменилась

private:
    double m_x;
    double m_y;
    int mouse_size = 50; //размер мышки 100 на 100, поэтому для центрирования вычитаем половину
};

#endif // MOUSE_H
