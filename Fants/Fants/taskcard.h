#ifndef TASKCARD_H
#define TASKCARD_H

#include <QObject>

class TaskCard
{
    //Q_OBJECT
public:
    TaskCard(QString activity, QString type, int participants, double price, QString link, QString key,double accessibility);
    QString activity()const;
    QString type()const;
    int participants()const;
    double price()const;
    QString link()const;
    QString key()const;
    double accessibility()const;

private:
    QString m_activity;
    QString m_type;
    int m_participants;
    double m_price;
    QString m_link;
    QString m_key;
    double m_accessibility;
};

#endif // TASKCARD_H
