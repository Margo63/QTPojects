#ifndef LAMP_H
#define LAMP_H

#include <QObject>

class Lamp : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool state READ state NOTIFY stateChanged);
public:
    explicit Lamp(QObject *parent = nullptr);
    bool state() const;

public slots:
    void off();
    void on();
    void click();

signals:
    void stateChanged();

private:
    bool m_state = false;
};

#endif // LAMP_H
