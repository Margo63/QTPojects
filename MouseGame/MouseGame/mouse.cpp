#include "mouse.h"
#include <QDebug>

Mouse::Mouse(QObject* parent):QObject(parent)
{
}

double Mouse::x() const//геттер x
{
    return m_x;
}

double Mouse::y() const//геттер y
{
    return m_y;
}

void Mouse::changePosition()//метод который вызывается при нажатии на поле
{
    //c++
    /////////////////////////////
    srand(time(0));
    m_x=rand()%640;
    m_y=rand()%480;
    /////////////////////////////

    //QT
   // m_x = generator.bounded(0, 640);    //рандомим позицию на поле
   // m_y = generator.bounded(0, 480);
    emit positionChanged(); //сигнал что все изменилось (можно закоментить и показать что позиция у объекта меняться не будет)
}

void Mouse::move()//метод для вызове в таймере
{
    //c++
    /////////////////////////////
    srand(time(0));
    int x = rand()%10-5;
    int y = rand()%10-5;
    /////////////////////////////
    //QT
    //int x = generator.bounded(-5, 5);//рандомим координаты от -5 до 5 (-1-1 не сильно видны изменения даже при частом вызове)
    //int y = generator.bounded(-5, 5);

    while(x==0 && y==0){//если оба нуля продолжаем рандомить
        //c++
        /////////////////////////////
        x = rand()%10-5;
        y = rand()%10-5;
        /////////////////////////////
        //QT
        //x = generator.bounded(-5, 5);
        //y = generator.bounded(-5, 5);
    }
    qDebug()<<"-------------";//красивый вывод для демонстрации рандомности
    qDebug()<<"x = "<<x;
    qDebug()<<"y = "<<y;
    qDebug()<<"-------------";
    if((m_x+x)>=-100 && (m_x+x)<=640 && (m_y+y)>=-100 && (m_y+y)<=480){//если вышли за пределы области, то не перемещаемся
        m_x+=x;
        m_y+=y;
    }

    emit positionChanged();

}
