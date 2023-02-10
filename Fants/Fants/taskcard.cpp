#include "taskcard.h"

TaskCard::TaskCard(QString activity, QString type, int participants, double price, QString link, QString key,double accessibility):
    m_activity(activity),m_type(type), m_participants(participants), m_price(price), m_link(link), m_key(key), m_accessibility(accessibility)
{

}

QString TaskCard::activity() const
{
    return m_activity;
}

QString TaskCard::type() const
{
    return m_type;
}

int TaskCard::participants() const
{
    return m_participants;
}

double TaskCard::price() const
{
    return m_price;
}

QString TaskCard::link() const
{
    return m_link;
}

QString TaskCard::key() const
{
    return m_key;
}

double TaskCard::accessibility() const
{
    return m_accessibility;
}
