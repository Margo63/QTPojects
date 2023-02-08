#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>


class JikanModel : public QObject
{
    Q_OBJECT
    //свйство что что-то добавили
    Q_PROPERTY(bool  isParametersAdded  READ  isParametersAdded NOTIFY  isParametersAddedChanged)
    //свойства для получаемых из запроса данных
    Q_PROPERTY(int malId READ malId  NOTIFY malIdChanged)
    Q_PROPERTY(QString username READ username  NOTIFY usernameChanged)
    Q_PROPERTY(QString url READ url  NOTIFY urlChanged)
    Q_PROPERTY(QString imageJpg READ imageJpg  NOTIFY imageJpgChanged)
    Q_PROPERTY(QString imageWebp READ imageWebp  NOTIFY imageWebpChanged)
    Q_PROPERTY(QString lastOnline READ lastOnline  NOTIFY lastOnlineChanged)
    Q_PROPERTY(QString gender READ gender  NOTIFY genderChanged)
    Q_PROPERTY(QString birthday READ birthday  NOTIFY birthdayChanged)
    Q_PROPERTY(QString location READ location  NOTIFY locationChanged)
    Q_PROPERTY(QString joined READ joined  NOTIFY joinedChanged)

public:
    explicit JikanModel(QObject* parent = nullptr);
    bool isParametersAdded()const;
    //геттеры
    int malId() const;
    QString username() const;
    QString url()const;
    QString imageJpg()const;
    QString imageWebp()const;
    QString lastOnline()const;
    QString gender()const;
    QString birthday()const;
    QString location()const;
    QString joined()const;

public slots:
    //сеттер для всего
    void setParameters(int mal_id,QString username,QString url,QString image_jpg,QString image_webp,
                       QString last_online,QString gender,QString birthday,QString location,QString joined);


signals:
    void isParametersAddedChanged();
    void malIdChanged();
    void usernameChanged();
    void urlChanged();
    void imageJpgChanged();
    void imageWebpChanged();
    void lastOnlineChanged();
    void genderChanged();
    void birthdayChanged();
    void locationChanged();
    void joinedChanged();

private:
    //значения по дефолту (можно и в конструкторе, мне просто они здесь виднее и удобнее)
    int m_mal_id=-1;
    QString m_username = "data has not yet arrived";
    QString m_url= "data has not yet arrived";
    QString m_image_jpg= "data has not yet arrived";
    QString m_image_webp= "data has not yet arrived";
    QString m_last_online= "data has not yet arrived";
    QString m_gender= "data has not yet arrived";
    QString m_birthday= "data has not yet arrived";
    QString m_location= "data has not yet arrived";
    QString m_joined= "data has not yet arrived";

    bool m_isParametersAdded = false;


};

#endif // PROCESSING_H
