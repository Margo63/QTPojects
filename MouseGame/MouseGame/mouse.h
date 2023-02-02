#ifndef MOUSE_H
#define MOUSE_H

#include <QObject>
#include <QRandomGenerator>
#include <time.h>
class Mouse:public QObject
{
    Q_OBJECT
    Q_PROPERTY(double x READ x NOTIFY positionChanged); // свойство x
    Q_PROPERTY(double y READ y NOTIFY positionChanged); // свойство y
public:
    explicit Mouse(QObject * parent=nullptr);
    double x()const;//геттер для x
    double y()const;//геттер для y

public slots:
    void changePosition();//метод для рандомного изменения позиции
    void move();//метод для изменения позиции в таймере
signals:
    void positionChanged();//сигнал что позиция изменилась

private:
    double m_x=0;
    double m_y=0;
    //мне не понравилась работа с Qt функцией тк он генерит случайное число каждый вызов(движения дерганные), а с++ реализация раз в секунду
    //тк функция time возвращает время начиная с 1 января 1970
    //а функция вызывается 10 раз в секунду
   // QRandomGenerator generator;// класс для работы с рандомом
};

#endif // MOUSE_H
