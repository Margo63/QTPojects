#include "delivery.h"
#include <QDebug>
Delivery::Delivery(QObject*parent):QObject(parent){}

void Delivery::filtration(int filter_value, int filter_type)//передаем тип по которому будем фильтровать(по цене, региону доставки или по типу(острая и тд))
{

    filtered_list.resize(0);//обнуляем отфильтрованный список
    switch(filter_type){
        case PRICE:{
            for(size_t i=0;i<pizzas.size();i++){//просматриваем все елементы вектра всех пицц
                if(pizzas[i].price<=filter_value)//если фильтруем по цене, то в итоговый вектор добавляем если цена пиццы меньше фильтровочной цены
                    filtered_list.push_back(pizzas[i]);//добавляем пиццу
            }
            break;
        }
        case TYPE:{
            for(size_t i=0;i<pizzas.size();i++){//просматриваем все елементы вектра всех пицц
                if(pizzas[i].type==filter_value)//если фильтруем по типу, то в итоговый вектор добавляем если тип рассматриваемой пиццы и переданный тип совпадают
                    filtered_list.push_back(pizzas[i]);//добавляем пиццу
            }
            break;
        }
        case REGION:{
            for(size_t i=0;i<pizzas.size();i++){//просматриваем все елементы вектра всех пицц
                if(pizzas[i].delivery_region==filter_value)//если фильтруем по региону, то в итоговый вектор добавляем если регион рассматриваемой пиццы и переданный регион совпадают
                    filtered_list.push_back(pizzas[i]);//добавляем пиццу
            }

            break;
        }

    }
}

int Delivery::pizzaCount()//геттер для количества всех пицц
{
    return pizzas.size();
}

int Delivery::filterCount()//геттер для количества отфильтрованных пицц
{
    return filtered_list.size();
}


int Delivery::getPrice(int index,int list)//геттер для цены, чтобы не писать дублирующие функции передаем еще и индекс вектора(0-pizzas 1-filtered_list)
{
    if(list==0)
        return pizzas[index].price;
    if(list==1)
        return filtered_list[index].price;
    return -1;
}

int Delivery::getType(int index,int list)//геттер для типа
{
    if(list==0)
        return pizzas[index].type;
    if(list==1)
        return filtered_list[index].type;
    return -1;
}

int Delivery::getRegion(int index,int list)//геттер для региона
{
    if(list==0)
        return pizzas[index].delivery_region;
    if(list==1)
        return filtered_list[index].delivery_region;
    return -1;
}

QString Delivery::getName(int index,int list)//геттер для названия пиццы
{
    if(list==0)
        return pizzas[index].name;
    if(list==1)
        return filtered_list[index].name;
    return "";
}


