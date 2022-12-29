#include "colorchange.h"

ChangeColor::ChangeColor(QObject *parent):
    QObject(parent),
    m_color("white")//констурктор (начальная инициализация)
{

}


QColor ChangeColor::color() const {//геттер
    return m_color;
}
void ChangeColor::changeColor(QColor new_color){
    m_color = new_color; //изменение цвета на переданный
    emit colorChanged();//вызов сигнала
}
