#ifndef SEARCH_H
#define SEARCH_H

#include <QObject>

class Search:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList nameList READ nameList NOTIFY nameListChanged)
    Q_PROPERTY(QString search READ search WRITE setSearch NOTIFY searchChanged)
public:
    explicit Search(QObject* parent=nullptr);
    QStringList nameList() const;
    QString search()const;

public slots:
    void addName(QString name);
    void setSearch(QString search);
signals:
    void nameListChanged();
    void searchChanged();
private:
    QStringList m_nameList;
    QString m_search="";

};

#endif // SEARCH_H
