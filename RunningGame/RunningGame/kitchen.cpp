#include "kitchen.h"
#include <QDebug>
Kitchen::Kitchen(QObject* parent):QAbstractListModel(parent)
{
    m_data.push_back(Food("egg",1,1));
    m_data.push_back(Food("egg",1,1));
    m_data.push_back(Food("flour",60,60));
    m_data.push_back(Food("sugar",100,110));
    m_data.push_back(Food("sugar",200,200));
    m_data.push_back(Food("sugar",200,200));
}

int Kitchen::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
                return 0;
    return m_data.size();
}

QVariant Kitchen::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
            return QVariant();

    const Food &data = m_data.at(index.row());

    switch(role){
        case NameRole:{
            return data.name();
        }
        case XRole:{
            return data.x();
        }
        case YRole:{
            return data.y();
        }
        case WidthRole:{
            return data.width();
        }
        case HeightRole:{
            return data.height();
        }
        default:{
            return QVariant();
        }
    }
}

QHash<int, QByteArray> Kitchen::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[NameRole] = "name";
    roles[XRole] = "x";
    roles[YRole] = "y";
    roles[WidthRole] = "width";
    roles[HeightRole] = "height";

    return roles;
}

void Kitchen::collision(int index,int x,int y)
{
    if(index<0 || index>=m_data.count())
        return;

    Food* data = &m_data[index];
    data->setPosition(x,y);


    for(int i=0; i<m_data.count();i++){
        if(i!=index){
            Food* tmp_data = &m_data[i];
            //столкновение центра передвигаемого объекта с другим (который есть на поле)
            if( (x+data->width()/2) > tmp_data->x() && (x+data->width()/2) < (tmp_data->x()+tmp_data->width())
                    && (y + data->height()/2)>tmp_data->y() && (y + data->height()/2)<(tmp_data->y()+tmp_data->height())){

                if(tmp_data->changeFood(data->formula())){
                    //сигнал об изменение элемента модели
                    QModelIndex change_index= createIndex(i, i, tmp_data);
                    emit dataChanged(change_index, change_index);

                    //удаление "поглошенного/смешанного" объекта
                    beginRemoveRows(QModelIndex(),index, index);
                    m_data.removeAt(index);
                    endRemoveRows();

                }
                return;
            }
        }
    }
}

void Kitchen::decay(int index)
{
     Food* data = &m_data[index];
     int length = data->formula().count();

     //распад объекта на состовляющие
     for(int i=0;i<length;i++){
         QString last=data->removeLast();
         if(last!=""&&last!="fire"){
             beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
             m_data.append(Food{last,data->x()+data->width(),data->y()+data->height()});
             endInsertRows();
         }
     }
     //сигнал об изменение элемента модели
     QModelIndex change_index= createIndex(index, index, data);
     emit dataChanged(change_index, change_index);


}

void Kitchen::oven(int index, int fire, int x, int y, int width, int height)
{
    if(index<0 || index>=m_data.count()|| fire==0)
        return;

    //столкновение с печью
    Food* data = &m_data[index];
    if(data->x()>x && (data->x()+data->width())<(x+width) && data->y()>y && (data->y()+data->height())<(y+height)){
        data->addFire(fire);
    }
    //сигнал об изменение элемента модели
    QModelIndex change_index= createIndex(index, index, data);
    emit dataChanged(change_index, change_index);

}
