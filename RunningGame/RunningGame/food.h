#ifndef FOOD_H
#define FOOD_H

#include <QObject>

class Food
{
public:
     Food(QString name,int x,int y);

     //геттеры для свойств
    QString name() const;
    QVector<QString> formula() const;
    int x() const;
    int y() const;
    int width() const;
    int height() const;


    bool changeFood(QVector<QString> formula);//изменение типа продукта
    void setPosition(int x, int y);//сеттер позиции
    void addFire(int time);//добавление "прожарки"
    int hash(QVector<QString>formula); //функция хеширования данных
    QString removeLast(); //удаление последнего элемента
    void getData(); //функция, которая в зависимости от формулы, определяет имя и размеры



private:
     //один из вариантов добавить счетчики для каждого продукта
    QString m_name;
    QVector<QString> m_formula;
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    bool isSmt=false;

};

#endif // FOOD_H
