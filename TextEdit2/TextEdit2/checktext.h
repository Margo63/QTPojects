#ifndef CHECKTEXT_H
#define CHECKTEXT_H

#include <QObject>

class CheckText:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text NOTIFY textChanged)
    Q_PROPERTY(QString regular READ regular WRITE setRegular NOTIFY regularChanged)
public:
    explicit CheckText(QObject* parent = nullptr);
    QString text() const;
    QString regular() const;
public slots:
    void setText(QString text);
    void setRegular(QString regular);

signals:
    void textChanged();
    void regularChanged();
private:
    QString m_text;
    QString m_regular;
};

#endif // CHECKTEXT_H
