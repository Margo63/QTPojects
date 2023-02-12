#ifndef RICKANDMORTY_H
#define RICKANDMORTY_H

#include <QObject>
#include <QAbstractListModel>

struct Character{
    QString name;
    QString status;
    QString species;
    QString image;
};

class RickAndMorty:public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles{NameRole=Qt::UserRole + 1,StatusRole,SpeciesRole,ImageRole};
    explicit RickAndMorty(QObject* parent=nullptr);
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void add(QString name,QString status,QString species,QString image);
    void clear();
private:
    QVector<Character> m_data;

};

#endif // RICKANDMORTY_H
