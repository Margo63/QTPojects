#ifndef FAVORITE_H
#define FAVORITE_H

#include <QObject>
#include <QAbstractListModel>
#include <QColor>
struct Cat{
    QString id;
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

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void addCatImageList(QString id,QString url);
    void addFavorite(QString image_id,int favorite_id,QString url);
    //void changeFavoriteState(int index,QString color);
    void postFavorite(int index,int id);
    void deleteFavorite(int index);
    void onlyFavorite();
    void null_size();

private:
    QVector<Cat> m_data;
    QVector<Cat> list_favorite;
};

#endif // FAVORITE_H
