#include "collision.h"

Collision::Collision(QObject * parent):
    QObject(parent),m_formula("H2O"),m_color("lightblue")
{
}

QColor Collision::color() const //геттер цвета
{
    return m_color;
}

QString Collision::formula() const  //геттер формулы
{
    return m_formula;
}

bool Collision::collisionFunc(int x, int y, int w_x, int w_y,int wid,QString type){
    if (x>=w_x && y>=w_y && x+wid<=w_x+water_width){ // если объект внутри стакана с водой, то происходит столкновение
        setFormula(type);                               //изменение формулы
        return false;
    }else{
        return true;
    }
}

void Collision::setColor(QColor c)
{
    m_color = c;
    emit colorChanged();
}

void Collision::setFormula(QString added)
{
    m_formula+=" + ";
    m_formula+=added;           //добавление к формуле компонента
    components.push_back(added);//добавление компонента к вектору
    emit formulaChanged();      //сигнал изменения формулы

    if(std::count(components.begin(), components.end(), "NaOH") &&
            std::count(components.begin(), components.end(), "fenol") &&
            !std::count(components.begin(), components.end(), "HNO3"))  //если добавлена щелочь и индикатора
    {
          setColor("magenta");

    }else{
        setColor("lightblue");      //в противном случае цвет синий
    }
}
