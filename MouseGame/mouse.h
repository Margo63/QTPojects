#ifndef MOUSE_H
#define MOUSE_H

#include <QObject>

class Mouse : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double x READ x NOTIFY positionChanged);
    Q_PROPERTY(double y READ y NOTIFY positionChanged);
    Q_PROPERTY(int score READ score NOTIFY scoreChanged);
    Q_PROPERTY(bool state READ state WRITE setState NOTIFY gameState);
    Q_PROPERTY(int width READ width NOTIFY withState);
    Q_PROPERTY(int height READ height NOTIFY heightState);
public:
    explicit Mouse(QObject *parent = nullptr);
    double x() const;
    double y() const;
    int score() const;
    bool state() const;
    int width() const;
    int height() const;

signals:
    void positionChanged();
    void scoreChanged();
    void gameState();
    void heightState();

public slots:
    void changePosition();
    void move();
    void setState( bool );
    void windowSize(int width, int height);

private:
    double m_x = 0;
    double m_y = 100;
    int m_score = 0;
    bool m_state = false;
    int m_height = 0;
    int m_width = 0;
};

#endif // MOUSE_H

