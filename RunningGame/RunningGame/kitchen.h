#ifndef KITCHEN_H
#define KITCHEN_H

#include <QObject>

class Kitchen:public QObject
{
    Q_OBJECT
public:
    explicit Kitchen(QObject* parent=nullptr);
};

#endif // KITCHEN_H
