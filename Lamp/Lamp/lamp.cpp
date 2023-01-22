#include "lamp.h"

Lamp::Lamp(QObject *parent):QObject(parent){}//конструктор

bool Lamp::state() const//геттер для состояния
{
    return m_state;
}

void Lamp::off()//если вызывается метод off состояние меняется на false
{
    m_state = false;
    emit stateChanged();//вызов сигнала
}

void Lamp::on()//если вызывается метод on состояние меняется на true
{
    m_state = true;
    emit stateChanged();//вызов сигнала
}


