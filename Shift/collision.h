#ifndef COLLISION_H
#define COLLISION_H

#include <QObject>
#include <QColor>
#include <QDebug>
#include <vector>
class Collision:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)          //сигнал для цвета
    Q_PROPERTY(QString text READ formula WRITE setFormula NOTIFY formulaChanged)    //сигнал для формулы



public:
    explicit Collision(QObject *parent=nullptr);
    QColor color() const;
    QString formula()const;
    Q_INVOKABLE bool collisionFunc(int x, int y, int w_x, int w_y,int wid,QString type);

public slots:
    void setColor(QColor c);
    void setFormula(QString added);

signals:
    void colorChanged();
    void formulaChanged();

private:
    QString m_formula;
    QColor m_color;
    int water_width = 200;

    std::vector <QString> components;




};

#endif // COLLISION_H
