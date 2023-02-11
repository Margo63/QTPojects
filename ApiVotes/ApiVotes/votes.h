#ifndef VOTES_H
#define VOTES_H

#include <QObject>
#include <QAbstractListModel>
#include <QColor>
//структура котика
struct Cat{
    QString id;//image_id
    QString image_url;
    QString color;
    int vote_id;
};

class Votes:public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles{IdRole=Qt::UserRole + 1,ImageRole,VoteRole,VoteIdRole};
    explicit Votes(QObject* parent = nullptr);
//переопределяем родительские методы
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    //добавляем в модель
    void addCatImageList(QString id,QString url);
    //добавляем в список фаворитов и проверяем полученные ранее данные на наличие в них
    void addVote(QString image_id,int vote_id,QString url);
    //void changeFavoriteState(int index,QString color);
    //добавление в фаворитов+изменение модели
    void postVote(int index,int id);
    //удаление из фаворитов+изменение модели
    void deleteVote(int index);
    //модели присваиваем лист фаворитов
    void onlyVote();
    //обнуляем модель
    void null_size();

private:
    QVector<Cat> m_data;//список котиков
    QVector<Cat> list_vote;//список фаворитов
};

#endif // VOTES_H
