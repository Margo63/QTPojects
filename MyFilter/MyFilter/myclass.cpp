#include "myclass.h"
#include <QDebug>


#include <vector>
//using namespace std;

MyClass::MyClass(QObject *parent):QObject(parent){//конструктор


}

void MyClass::add(QString price, QString product)//добовляем элемент
{

    qDebug()<<list_products.size();
    list_products.insert(list_products.begin(),Products{price.toInt(),product});
    show();
}

void MyClass::remove(QString price, QString product)//удаляем элемент
{
    //в теории можно передавать индекс и удалять уже по нему
    for(int i=0;i<list_products.size();i++){
        if(list_products[i].price==price.toInt() && list_products[i].product==product){
            list_products.erase(list_products.begin()+i);
            show();
            return;//тк если будут повторяющиеся элементы то удаляем первый встретившийся
        }
    }
}
void MyClass::show()    //для фиксации изменений в с++
{
    for(int i=0;i<list_products.size();i++){
        qDebug()<<list_products[i].product;
    }
}

int MyClass::getPrice(int index)//геттер для продукта
{
    return list_products[index].price;
}

QString MyClass::getProduct(int index)//геттер для цены
{
    return list_products[index].product;
}

void MyClass::priceSort()
{   //сортировка выбором (не самая оптимальная, но наиболее понятная, для студентов можно дать задание на добавление своей сортировки(слияние и тд))
    //встроенные сортировки у меня не заработали
    for(int i=0;i<list_products.size()-1;i++){
        int min=i;
        for(int j=i+1;j<list_products.size();j++){
            if (list_products[j].price < list_products[min].price)
                min = j;
        }
        if (min != i)
        {
            Products tmp = list_products[i];
            list_products[i]=list_products[min];
            list_products[min]=tmp;
        }


    }

}



