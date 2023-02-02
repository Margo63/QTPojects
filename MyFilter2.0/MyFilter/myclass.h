#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>


struct Products{
    int price;
    QString product;

};

class MyClass:public QObject
{
    Q_OBJECT


public:
    explicit MyClass(QObject* parent = nullptr);

    Q_INVOKABLE void add(QString price,QString product);
    Q_INVOKABLE void remove(QString price,QString product);
    Q_INVOKABLE void show();

    Q_INVOKABLE int getPrice(int index);
    Q_INVOKABLE QString getProduct(int index);

    Q_INVOKABLE void priceSort();

private:

    QVector<Products> list_products;

};



#endif // MYCLASS_H
