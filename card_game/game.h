#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QColor>


class Game : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool change READ change NOTIFY stateChanged);
    Q_PROPERTY(int id1 READ change1 NOTIFY stateChanged);
    Q_PROPERTY(int id2 READ change2 NOTIFY stateChanged);
public:
    explicit Game(QObject *parent = nullptr);
    bool change() const;
    int change1() const;
    int change2() const;

signals:
    void stateChanged();

public slots:
    void setColor(QColor color, int index);

private:
    int count_operation = 0;
    QColor color1 = nullptr;
    QColor color2 = nullptr;
    int m_change_id1;
    int m_change_id2;
    bool m_change = false;
};


#endif // GAME_H
