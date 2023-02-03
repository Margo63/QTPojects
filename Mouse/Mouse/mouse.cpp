#include "mouse.h"

Mouse::Mouse(QObject* parent):QObject(parent)
{}

double Mouse::x() const//геттер x
{
    return m_x;
}

double Mouse::y() const//геттер y
{
    return m_y;
}

void Mouse::changePosition(double x, double y)//метод который вызывается при нажатии на поле
{
    m_x=x-mouse_size;           //вычитаем размер кружочка, чтобы мышка перемешалась в центр
    m_y = y-mouse_size;
    emit positionChanged(); //сигнал что все изменилось (можно закоментить и показать что позиция у объекта меняться не будет)
}

