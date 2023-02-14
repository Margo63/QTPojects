#ifndef CHECKTEXT_H
#define CHECKTEXT_H

#include <QObject>
#include <regex>
class CheckText:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text NOTIFY textChanged)
public:
    explicit CheckText(QObject* parent = nullptr);
    QString text() const;
public slots:
    void setText(QString text);
signals:
    void textChanged();
private:
    QString m_text;
};

#endif // CHECKTEXT_H
