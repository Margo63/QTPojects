#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
//собственная структура (простыми словами структура = класс где все public)
//вместо структуры можно сделать свой класс
struct Product{
    QString name;
    QString product;
    int price;
};

#endif // PRODUCT_H
