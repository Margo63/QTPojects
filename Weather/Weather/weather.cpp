#include "weather.h"

Weather::Weather(QObject* parent):QObject(parent)
{

}

double Weather::temperature() const
{
    if(m_temp=="c")
        return m_temp_c;
    return m_temp_f;
}


double Weather::wind() const
{
    if(m_speed=="mph")
        return m_wind_mph;
    return m_wind_kph;
}

double Weather::pressure() const
{
    if(m_press =="mb")
        return m_pressure_mb;
    return m_pressure_in;
}

int Weather::humidity() const
{
    return m_humidity;
}

double Weather::feelslike() const
{
    if(m_temp=="c")
        return m_feelslike_c;
    return m_feelslike_f;
}

double Weather::gust() const
{
    if(m_speed=="mph")
        return m_gust_mph;
    return m_gust_kph;
}

QString Weather::name() const
{
    return m_name;
}

QString Weather::country() const
{
    return m_country;
}

QString Weather::speed() const
{
    return m_speed;
}

QString Weather::temp() const
{
    return m_temp;
}

QString Weather::press() const
{
    return m_press;
}

void Weather::setData(QString name, QString country, double temp_c, double temp_f, double wind_mph, double wind_kph, double pressure_mb, double pressure_in, int humidity, double feelslike_c, double feelslike_f, double gust_mph, double gust_kph)
{
    m_name = name;
    m_country = country;
    m_temp_c = temp_c;
    m_temp_f = temp_f;
    m_wind_mph = wind_mph;
    m_wind_kph = wind_kph;
    m_pressure_mb = pressure_mb;
    m_pressure_in = pressure_in;
    m_humidity = humidity;
    m_feelslike_c = feelslike_c;
    m_feelslike_f = feelslike_f;
    m_gust_mph = gust_mph;
    m_gust_kph = gust_kph;

    emit temperatureChanged();
    emit windChanged();
    emit pressureChanged();
    emit humidityChanged();
    emit feelslikeChanged();
    emit gustChanged();
    emit nameChanged();
    emit countryChanged();

}

void Weather::setSpeed(QString speed)
{
    if(speed =="mph"||speed == "kph"){

        m_speed=speed;
        emit speedChanged();
        emit windChanged();
        emit gustChanged();
    }



}

void Weather::setTemp(QString temp)
{
    if(temp =="c"||temp == "f"){

        m_temp=temp;
        emit tempChanged();
        emit feelslikeChanged();
        emit temperatureChanged();
    }

}

void Weather::setPress(QString press)
{
    if(press =="mb"||press == "in"){

        m_press=press;
        emit pressChanged();
        emit pressureChanged();
    }

}
