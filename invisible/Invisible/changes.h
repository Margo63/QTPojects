#ifndef CHANGES_H
#define CHANGES_H

#include <QObject>

class Changes:public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isVisible READ getVisibility NOTIFY visibilityChanged)

public:
    explicit Changes(QObject *parent = nullptr);
    bool getVisibility() const;

public slots:
    void changeVisibility();

signals:
    void visibilityChanged();

private:
    bool isVisible=true;
};

#endif // CHANGES_H
