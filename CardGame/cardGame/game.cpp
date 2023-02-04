#include "game.h"
#include "QDebug"
Game::Game(QObject* parent):QObject(parent){}

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

void Game::setColor(QColor color,int ind)
{
     kol_operation++;
        if(kol_operation>2){            //если уже было выбрано две карточки, старые данные сбрасываются
            previous_color=nullptr;
            now_color=nullptr;
            m_change_id1=-1;
            m_change_id2=-1;
            m_change = false;
            kol_operation=1;            //тк уже передана 1 карточка, то счетчик равняется 1
        }

        now_color = color;              //фиксация цвета и id
        m_change_id1 = ind;

        if(now_color == previous_color && m_change_id2!=m_change_id1){//если выбраны разные карточки с одинаковым цветом,
            m_change = true;                                            //то m_change меняется на true
            emit stateChanged();
            return;                                                     //выход из функции, тк далее происходит изменение previous_color и m_change_id2
        }else{
            m_change = false;
        }

        previous_color = now_color;     //запоминание цвета и id для дальнейшего сравнения
        m_change_id2=m_change_id1;

}
