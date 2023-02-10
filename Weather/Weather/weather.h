#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>

class Weather:public QObject
{
    Q_OBJECT

    Q_PROPERTY(double temperature READ temperature NOTIFY temperatureChanged)
    Q_PROPERTY(double wind READ wind NOTIFY windChanged)
    Q_PROPERTY(double pressure READ pressure NOTIFY pressureChanged)
    Q_PROPERTY(int humidity READ humidity NOTIFY humidityChanged)
    Q_PROPERTY(double feelslike READ feelslike NOTIFY feelslikeChanged)
    Q_PROPERTY(double gust READ gust NOTIFY gustChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString country READ country NOTIFY countryChanged)

    Q_PROPERTY(QString speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(QString temp READ temp WRITE setTemp NOTIFY tempChanged)
    Q_PROPERTY(QString press READ press WRITE setPress NOTIFY pressChanged)

public:
    explicit Weather(QObject* parent=nullptr);
    double temperature()const;
    double wind()const;
    double pressure()const;
    int humidity()const;
    double feelslike()const;
    double gust()const;
    QString name()const;
    QString country()const;

    QString speed()const;
    QString temp()const;
    QString press()const;
public slots:
    void setData(QString name,QString country,double temp_c,double temp_f,double wind_mph,double wind_kph,
                    double pressure_mb, double pressure_in, int humidity, double feelslike_c, double feelslike_f,
                    double gust_mph, double gust_kph);

    void setSpeed(QString speed);
    void setTemp(QString temp);
    void setPress(QString press);

signals:
    void temperatureChanged();
    void windChanged();
    void pressureChanged();
    void humidityChanged();
    void feelslikeChanged();
    void gustChanged();
    void nameChanged();
    void countryChanged();

    void speedChanged();
    void tempChanged();
    void pressChanged();
private:
    QString m_name;
    QString m_country;
    double m_temp_c;
    double m_temp_f;
    double m_wind_mph;
    double m_wind_kph;
    double m_pressure_mb;
    double m_pressure_in;
    int m_humidity;
    double m_feelslike_c;
    double m_feelslike_f;
    double m_gust_mph;
    double m_gust_kph;
    QString m_speed="mph";
    QString m_temp="c";
    QString m_press="mb";
};

#endif // WEATHER_H
