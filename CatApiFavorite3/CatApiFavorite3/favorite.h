#ifndef FAVORITE_H
#define FAVORITE_H

#include <QObject>
#include <QAbstractListModel>
#include <QColor>
//структура котика
struct Cat{
    QString id;//image_id
    QString image_url;
    QString color;
    int favorite_id;
};

class Favorite:public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles{IdRole=Qt::UserRole + 1,ImageRole,FavoriteRole,FavoriteIdRole};
    explicit Favorite(QObject* parent = nullptr);
//переопределяем родительские методы
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    //добавляем в модель
    void addCatImageList(QString id,QString url);
    //добавляем в список фаворитов и проверяем полученные ранее данные на наличие в них
    void addFavorite(QString image_id,int favorite_id,QString url);
    //void changeFavoriteState(int index,QString color);
    //добавление в фаворитов+изменение модели
    void postFavorite(int index,int id);
    //удаление из фаворитов+изменение модели
    void deleteFavorite(int index);
    //модели присваиваем лист фаворитов
    void onlyFavorite();
    //обнуляем модель
    void null_size();

private:
    QVector<Cat> m_data;//список котиков
    QVector<Cat> list_favorite;//список фаворитов
};

#endif // FAVORITE_H
