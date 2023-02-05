#include "custommodel.h"

CustomModel::CustomModel(QObject* parent):QAbstractListModel(parent)//наследуем конструктор родителя
{
}

int CustomModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
            return 0;
    return m_data.size();//возвращаем размер вектора(количество элементов)
}

//QVariant - обертка над возвращаемыми типами
QVariant CustomModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    const Product &data = m_data.at(index.row());

    switch(role){
        case NameRole:{
            return data.name;
        }
        case ProductRole:{
            return data.product;
        }
        case PriceRole:{
            return data.price;
        }
        default:{
            return QVariant();
        }
    }
}

QHash<int, QByteArray> CustomModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[NameRole] = "name";
    roles[ProductRole] = "product";
    roles[PriceRole] = "price";

    return roles;
}

void CustomModel::add(QString name,QString product,int price)
{
    //добавляем элемент (используются методы родителя)

    /*  Документация QT:
        Реализация insertRows() должна вызывать beginInsertRows() перед вставкой новых строк в структуру данных,
        и endInsertRows() сразу после этого.
    */

    //логика (в данном случае проверка)
    if(name!="" && product!="" && price>0){
        beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
        m_data.append(Product{name,product,price});
        endInsertRows();
    }


}

void CustomModel::remove(int index)
{ //удяляем элемент по номеру строки (используются методы родителя)

    /*  Документация QT:
        Реализация removeRows() должна вызывать beginRemoveRows() до того,
        как строки будут удалены из структуры данных, и endRemoveRows() сразу после этого.
    */

    if(index<0 || index>m_data.count())
        return;

    beginRemoveRows(QModelIndex(),index, index);
    m_data.removeAt(index);
    endRemoveRows();
}


