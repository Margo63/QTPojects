#include "game.h"

Game::Game(QObject *parent)
    : QObject{parent}
{

}

bool Game::change() const
{
    return m_change;
}

int Game::change1() const
{
    return m_change_id1;
}

int Game::change2() const
{
    return m_change_id2;
}

void Game::setColor(QColor color, int index)
{
     count_operation++;

     if (count_operation > 2) //если рассматривается третья карточка
     {
         //если уже было выбрано две карточки, старые данные сбрасываются
         color1 = nullptr;
         color2 = nullptr;
         m_change_id1 = -1;
         m_change_id2 = -1;
         m_change = false;
         count_operation = 1; //тк уже передана 1 карточка, то счетчик равняется 1
      }

     color2 = color; //присваивается цвет второй карточке
     m_change_id2 = index; //присвается индекс второй карточке

     if(color2 == color1 && m_change_id2 != m_change_id1) //цвета одни, но карточки разные
     {//если выбраны разные карточки с одинаковым цветом,
        m_change = true;                                            //то m_change меняется на true
        emit stateChanged();
        return;                                                     //выход из функции, тк далее происходит изменение previous_color и m_change_id2
     }
     else
     {
        m_change = false;
     }

     color1 = color2;     //запоминание цвета и id для дальнейшего сравнения
     m_change_id1 = m_change_id2;
}
