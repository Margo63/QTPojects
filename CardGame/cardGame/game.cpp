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
    if(kol_operation>2){
        previous_color=nullptr;
        now_color=nullptr;
        m_change_id1=-1;
        m_change_id2=-1;
        m_change = false;
        kol_operation=1;
    }

    now_color = color;
    m_change_id1 = ind;

    if(now_color == previous_color){
        m_change = true;
        emit stateChanged();
        return;
    }else{
        m_change = false;
    }

    previous_color = now_color;
    m_change_id2=m_change_id1;



}
