#include "votes.h"
#include <QDebug>
Votes::Votes(QObject* parent):QAbstractListModel(parent)
{

}

int Votes::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
            return 0;
    return m_data.size();//возвращаем размер вектора(количество элементов)
}

//QVariant - обертка над возвращаемыми типами
QVariant Votes::data(const QModelIndex &index, int role) const
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
        case VoteRole:{

             return data.color;

        }
    case VoteIdRole:{
            return data.vote_id;
        }
        default:{
            return QVariant();
        }
    }
}

QHash<int, QByteArray> Votes::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[IdRole] = "id";
    roles[ImageRole] = "image_url";
    roles[VoteRole] = "isVote";
    roles[VoteIdRole]="vote_id";

    return roles;
}

void Votes::addCatImageList(QString id, QString url)
{
//проверка на валидность
    if(id!="" && url!=""){
        //qDebug()<<id<<" "<<url;
        beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
        m_data.append(Cat{id,url,"lightgray",0});
        endInsertRows();

    }
}

void Votes::addVote(QString image_id,int vote_id,QString url)
{

    //добавляем в список фаворитов
    list_vote.append(Cat{image_id,url,"yellow",vote_id});
    for(int i=0;i<m_data.size();i++){
        if(m_data[i].id == image_id){//меняем данные если случайный котик в фаворитах
            //qDebug()<<i;
            Cat* data = &m_data[i];
            data->color = "yellow";
            data->vote_id = vote_id;
            QModelIndex change_index= createIndex(i, i, data);
            emit dataChanged(change_index, change_index);
            return;
        }
    }
}

void Votes::postVote(int index,int id)
{

    if(index<0 || index>=m_data.count())
            return;
    //меняем данные и список фаворитов
    Cat* data = &m_data[index];
    data->vote_id = id;
    data->color="yellow";

    list_vote.append(Cat{data->id,data->image_url,"yellow",id});
    QModelIndex change_index= createIndex(index, index, data);
    emit dataChanged(change_index, change_index);

}

void Votes::deleteVote(int index)
{
    //удаляем
    //qDebug()<<"delete";
    if(index<0 || index>=m_data.count())
            return;
    Cat* data = &m_data[index];
    //int erase_ind=-1;
    for(int i=0;i<list_vote.count();i++){
        if(data->vote_id == list_vote[i].vote_id){
            //qDebug()<<data->vote_id;
            list_vote.remove(i);
        }
    }


    //изменяем модель
    data->vote_id = 0;
    data->color = "lightgray";

    QModelIndex change_index= createIndex(index, index, data);
    emit dataChanged(change_index, change_index);
}

void Votes::onlyVote()
{
    //обнуляем и заново заполняем
    null_size();

    for(int i=0;i<list_vote.count();i++){
        beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
        m_data.append(list_vote[i]);
        endInsertRows();

    }

}

void Votes::null_size()
{
    //удаляем все строчки
    beginRemoveRows(QModelIndex(),0, m_data.size());
    m_data.resize(0);
    endRemoveRows();
}
