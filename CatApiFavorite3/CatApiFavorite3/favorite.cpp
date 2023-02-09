#include "favorite.h"
#include <QDebug>
Favorite::Favorite(QObject* parent):QAbstractListModel(parent)
{


}

int Favorite::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
            return 0;
    return m_data.size();//возвращаем размер вектора(количество элементов)
}

//QVariant - обертка над возвращаемыми типами
QVariant Favorite::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    const Cat &data = m_data.at(index.row());

    switch(role){
        case IdRole:{
            return data.id;
        }
        case ImageRole:{
            return data.image_url;
        }
        case FavoriteRole:{

             return data.color;

        }
    case FavoriteIdRole:{
            return data.favorite_id;
        }
        default:{
            return QVariant();
        }
    }
}

QHash<int, QByteArray> Favorite::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[IdRole] = "id";
    roles[ImageRole] = "image_url";
    roles[FavoriteRole] = "isFavorite";
    roles[FavoriteIdRole]="favorite_id";

    return roles;
}

void Favorite::addCatImageList(QString id, QString url)
{

    if(id!="" && url!=""){
        //qDebug()<<id<<" "<<url;
        beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
        m_data.append(Cat{id,url,"lightgray",0});
        endInsertRows();

    }
}

void Favorite::addFavorite(QString image_id,int favorite_id)
{
    qDebug()<<image_id;
    for(int i=0;i<m_data.size();i++){
        if(m_data[i].id == image_id){
            qDebug()<<i;
            Cat* data = &m_data[i];
            data->color = "red";
            data->favorite_id = favorite_id;
            QModelIndex change_index= createIndex(i, i, data);
            emit dataChanged(change_index, change_index);
            return;
        }
    }
}

void Favorite::changeFavoriteState(int index, QString color)
{
    if(index<0 || index>=m_data.count())
            return;
        Cat* data = &m_data[index];
        data->color = color;
        QModelIndex change_index= createIndex(index, index, data);
        emit dataChanged(change_index, change_index);
}

void Favorite::postFavorite(int index,int id)
{
    if(index<0 || index>=m_data.count())
            return;
    Cat* data = &m_data[index];
    data->favorite_id = id;
    QModelIndex change_index= createIndex(index, index, data);
    emit dataChanged(change_index, change_index);

}

void Favorite::deleteFavorite(int index)
{
    if(index<0 || index>=m_data.count())
            return;
    Cat* data = &m_data[index];
    data->favorite_id = 0;
    data->color = "lightgray";
    QModelIndex change_index= createIndex(index, index, data);
    emit dataChanged(change_index, change_index);
}

//void Favorite::changeColor(int index,QString color)
//{
//    if(index<0 || index>=m_data.count())
//        return;
//    Cat* data = &m_data[index];
//    data->color = color;
//    QModelIndex change_index= createIndex(index, index, data);
//    emit dataChanged(change_index, change_index);
//}
