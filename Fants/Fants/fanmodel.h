#ifndef FANMODEL_H
#define FANMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "taskcard.h"
class FanModel:public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles{ActivityRole=Qt::UserRole + 1,TypeRole,ParticipantsRole,PriceRole,LinkRole,KeyRole,AccessibilityRole};
    explicit FanModel(QObject* parent = nullptr);
//переопределяем родительские методы
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void addTask(QString activity,QString type, int participants,double price,QString link,QString key, double accessibility);

private:
    QVector<TaskCard> m_data;//список котиков
};

#endif // FANMODEL_H
