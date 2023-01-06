#ifndef CANCULATOR_H
#define CANCULATOR_H

#include <QObject>

class Calculator:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ result NOTIFY resultChanged)

public:
    explicit Calculator(QObject* parent=nullptr);
    QString result()const;

    void plus();
    void minus();
    void multiplication();
    void division();
    void del();
    void cleaner();
    void setResult( );

public slots:
    void getNumber(QString add,int operation);



signals:
    void resultChanged();
private:
    QString input="0";
    QString input2="0";
    QString m_result="";
    float r;
    int choosen_operation=-1;
    enum operations{CLEAN=0, DIV, MULTI, MINUS, PLUS, RESULT};

};

#endif // CANCULATOR_H
