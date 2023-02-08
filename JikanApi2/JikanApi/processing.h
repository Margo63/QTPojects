#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>


class JikanModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool  isParametersAdded  READ  isParametersAdded NOTIFY  isParametersAddedChanged)
public:
    explicit JikanModel(QObject* parent = nullptr);
    bool isParametersAdded()const;

public slots:
    void setParameters(int mal_id,QString username,QString url,QString image_jpg,QString image_webp,
                       QString last_online,QString gender,QString birthday,QString location,QString joined);
//    int getMalId();
//    QString getUsername();
//    QString getUrl();
//    QString getImageJpg();
//    QString getImageWebp();
//    QString getLastOnline();
//    QString getGender();
//    QString getBirthday();
//    QString getLocation();
//    QString getJoined();

signals:
    void isParametersAddedChanged();

private:
    int m_mal_id=0;
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
