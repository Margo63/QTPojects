#include "fanmodel.h"
#include "taskcard.h"
FanModel::FanModel(QObject* parent):QAbstractListModel(parent)
{

}

int FanModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
                    return 0;
        return m_data.size();
}

QVariant FanModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    const TaskCard &data = m_data.at(index.row());

    switch(role){
        case ActivityRole:{
            return data.activity();
        }
        case TypeRole:{
            return data.type();
        }
        case ParticipantsRole:{
            return data.participants();
        }
        case PriceRole:{
            return data.price();
        }
        case LinkRole:{
            return data.link();
        }
        case KeyRole:{
            return data.key();
        }
        case AccessibilityRole:{
            return data.accessibility();
        }
        default:{
            return QVariant();
        }
    }
}

QHash<int, QByteArray> FanModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[ActivityRole] = "activity";
    roles[TypeRole] = "type";
    roles[ParticipantsRole] = "participants";
    roles[PriceRole] = "price";
    roles[LinkRole] = "link";
    roles[KeyRole] = "key";
    roles[AccessibilityRole] = "accessibility";
    return roles;

}

void FanModel::addTask(QString activity, QString type, int participants, double price, QString link, QString key, double accessibility)
{
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.append(TaskCard(activity, type,participants, price, link, key, accessibility));
    endInsertRows();

}
