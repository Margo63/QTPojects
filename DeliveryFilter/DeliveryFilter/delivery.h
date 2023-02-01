#ifndef DELIVERY_H
#define DELIVERY_H

#include <QObject>

//структура для одной пиццы
struct Pizza{
    int price;
    QString name;
    int type;
    int delivery_region;
};

class Delivery:public QObject
{
    Q_OBJECT

public:
    explicit Delivery(QObject* parent=nullptr);
    Q_INVOKABLE void filtration(int filter_value,int filter_type);

//public slots:
    Q_INVOKABLE int pizzaCount();
    Q_INVOKABLE int filterCount();
    Q_INVOKABLE int getPrice(int index,int list);
    Q_INVOKABLE int getType(int index,int list);
    Q_INVOKABLE int getRegion(int index,int list);
    Q_INVOKABLE QString getName(int index,int list);

private:
    enum filter_type{PRICE=1,TYPE,REGION};//перечисление типов для удобного сопоставления
    enum types{HOT=1,VEGAN,NORMAL};
    enum regions{CENTRAL=1,SOUTH,NORTH,EAST,WEST};

    std::vector<Pizza> pizzas={Pizza{199,"Margarita",VEGAN,CENTRAL},//вектор пицц
                              Pizza{199,"Vegetable",VEGAN,SOUTH},
                              Pizza{299,"Marshmallow",NORMAL,EAST},
                              Pizza{399,"Texas",HOT,WEST}};

    std::vector <Pizza>filtered_list;//вектор куда будут добавляться пиццы согласно фильтру

};

#endif // DELIVERY_H
