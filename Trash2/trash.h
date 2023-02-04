#ifndef TRASH_H
#define TRASH_H

#include <QObject>
#include <QRandomGenerator>

struct Rubbish{
    QString name;
    QString type;
};

class Trash:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text NOTIFY textChanged)
    Q_PROPERTY(int mistakes READ mistakes NOTIFY mistakesChanged)
    Q_PROPERTY(bool gameState READ gameState NOTIFY gameStateChanged)
public:
    explicit Trash(QObject* parent = nullptr);
    QString text();
    int mistakes();
    bool gameState();
    Q_INVOKABLE QString getMistakeMessage();
    Q_INVOKABLE void restart();

public slots:
    void setText(QString type);
signals:
    void textChanged();
    void mistakesChanged();
    void gameStateChanged();
    void mistakeMessageChanged();

private:
    QVector<Rubbish> rubbish={Rubbish{"сломаный компьютер","special"},Rubbish{"обои","special"},
                              Rubbish{"испортившейся творог","organic"},Rubbish{"стухшее мясо","organic"},
                              Rubbish{"книги(не очень хорошие)","paper"},Rubbish{"печатные средства массовой информации","paper"},
                              Rubbish{"консервная банка","metal"},Rubbish{"металлом","metal"},
                              Rubbish{"упаковка от шампуня","plastic"},Rubbish{"пластиковые крышки","plastic"}};
    QString m_text;
    Rubbish tmp_rubbish;
    int tmp_index;
    QRandomGenerator generator;
    int m_mistakes=0;
    bool m_gameState=false;
    QString mistakeMessage;
};

#endif // TRASH_H
