#ifndef READINGJSON_H
#define READINGJSON_H
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QTextStream>

class ReadingJson:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url NOTIFY urlChanged)

public:
    explicit ReadingJson(QObject* parent = nullptr);
    QString url()const;
    Q_INVOKABLE QString getJSONOBJ();
public slots:
    void setUrl(QString url);
signals:
    void urlChanged();
private:
    QString m_url;      //путь к json файлу
    QString m_json_file;
};

#endif // READINGJSON_H
