#include "lamp.h"

Lamp::Lamp(QObject *parent)
    : QObject{parent}
{

}

bool Lamp::state() const
{
    return m_state;
}

void Lamp::off()
{
    m_state = false;
    emit stateChanged();
}

void Lamp::on()
{
    m_state = true;
    emit stateChanged();
}

void Lamp::click()
{
    m_state = !m_state;
    emit stateChanged();
}
