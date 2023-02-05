#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include <QObject>

#include "product.h"

//наследуемся от QAbstractListModel для создания своей модели

class CustomModel:public QAbstractListModel
{
    Q_OBJECT
public:
    //перечисление ролей
    //обязательно с Qt::UserRole + 1 тк до этого внутренние перечисленние ролей (определенное в родительском классе(ItemDateRole))
    enum Roles{NameRole=Qt::UserRole + 1,ProductRole,PriceRole};
    explicit CustomModel(QObject* parent=nullptr);//конструктор

    //переопределяем родительские методы они описаны в документации(https://doc.qt.io/qt-6/qabstractitemmodel.html#roleNames)
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;


    //свои методы для работы с моделью
public slots:
    void add(QString name,QString product,int price);
    void remove(int index);
private:
    QVector<Product> m_data;//вектор значений
};

#endif // CUSTOMMODEL_H
