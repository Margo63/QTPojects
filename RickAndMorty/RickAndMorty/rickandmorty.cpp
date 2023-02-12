#include "rickandmorty.h"

RickAndMorty::RickAndMorty(QObject* parent):QAbstractListModel(parent)
{

}

int RickAndMorty::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
            return 0;
    return m_data.size();//возвращаем размер вектора(количество элементов)
}

//QVariant - обертка над возвращаемыми типами
QVariant RickAndMorty::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    const Character &data = m_data.at(index.row());

    switch(role){
        case NameRole:{
            return data.name;
        }
        case StatusRole:{
            return data.status;
        }
        case SpeciesRole:{

             return data.species;

        }
        case ImageRole:{
                return data.image;
            }
        default:{
            return QVariant();
        }
    }
}

QHash<int, QByteArray> RickAndMorty::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[NameRole] = "name";
    roles[StatusRole] = "status";
    roles[SpeciesRole] = "species";
    roles[ImageRole]="image";

    return roles;
}

void RickAndMorty::add(QString name, QString status, QString species, QString image)
{
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.append(Character{name,status,species,image});
    endInsertRows();

}

void RickAndMorty::clear()
{
    beginRemoveRows(QModelIndex(),0, m_data.size());
    m_data.resize(0);
    endRemoveRows();
}
