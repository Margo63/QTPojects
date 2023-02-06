#ifndef KITCHEN_H
#define KITCHEN_H

#include <QAbstractListModel>
#include <QStringList>
#include <QObject>
#include "food.h"
class Kitchen:public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Kitchen(QObject* parent=nullptr);
    enum Roles{NameRole=Qt::UserRole + 1,XRole,YRole,WidthRole,HeightRole};


       //переопределяем родительские методы
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    //столкновение
    void collision(int index,int x,int y);
    //распад на составляющие
    void decay(int index);
    //печка
    void oven(int index,int fire,int x,int y,int width,int height);

private:
    QVector<Food> m_data;//вектор значений

};

#endif // KITCHEN_H
