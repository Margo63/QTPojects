#ifndef COLORCHANGE_H
#define COLORCHANGE_H

#include <QObject>
#include <QColor>


class ChangeColor:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor color MEMBER m_color NOTIFY colorChanged) //подключение сигнала
public:
    explicit ChangeColor(QObject *parent = nullptr);
    QColor color() const; //геттер для цвета


public slots:
    void changeColor(QColor new_color); // метод для изменения цвета

signals:

    void colorChanged(); //сигнал изменения цвета

private:
    QColor  m_color; //цвет
};


#endif // COLORCHANGE_H
