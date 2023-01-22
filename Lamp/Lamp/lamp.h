#ifndef LAMP_H
#define LAMP_H

#include <QObject>

class Lamp:public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool state READ state NOTIFY stateChanged);//добавляем свойство для объекта ObjectNameLamp
public:
    explicit Lamp(QObject* parent=nullptr);//!!!обязательно по умолчанию nullptr
    bool state() const;//!!! геттер для m_state обязательно const

public slots:
    void off();
    void on();

signals:
    void stateChanged();

private:
    bool m_state=false;

};

#endif // LAMP_H
