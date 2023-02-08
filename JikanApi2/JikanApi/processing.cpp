#include "processing.h"
#include<QDebug>
JikanModel::JikanModel(QObject* parent):QObject(parent)
{

}

bool JikanModel::isParametersAdded() const
{
    return m_isParametersAdded;
}

void JikanModel::setParameters(int mal_id, QString username, QString url, QString image_jpg, QString image_webp, QString last_online, QString gender, QString birthday, QString location, QString joined)
{
    m_mal_id = mal_id;
    m_username = username;
    m_url = url;
    m_image_jpg = image_jpg;
    m_image_webp =  image_webp;
    m_last_online = last_online;
    m_gender = gender;
    m_birthday = birthday;
    m_location = location;
    m_joined = joined;

    m_isParametersAdded = true;
    emit isParametersAddedChanged();
}

//int JikanModel::getMalId()
//{
//    if(!m_isParametersAdded)
//        return m_mal_id;
//    if(!m_mal_id)
//        return 0;
//    return m_mal_id;
//}

//QString JikanModel::getUsername()
//{
//    if(!m_isParametersAdded)
//        return m_username;
//    if(m_username==NULL || m_username=="")
//        return "not in data";
//    return m_username;
//}

//QString JikanModel::getUrl()
//{
//    if(!m_isParametersAdded)
//        return m_url;
//    if(m_url==NULL || m_url=="")
//        return "not in data";
//    return m_url;
//}

//QString JikanModel::getImageJpg()
//{
//    if(!m_isParametersAdded)
//        return "qrc:/image/nothing";
//    if(m_image_jpg==NULL || m_image_jpg=="")
//        return "qrc:/image/not_in_data.png";
//    return m_image_jpg;
//}

//QString JikanModel::getImageWebp()
//{
//    if(!m_isParametersAdded)
//        return "qrc:/image/nothing";
//    if(m_image_webp==NULL || m_image_webp=="")
//        return "qrc:/image/not_in_data.png";
//    return m_image_webp;
//}

//QString JikanModel::getLastOnline()
//{
//    if(!m_isParametersAdded)
//        return m_last_online;
//    if(m_last_online==NULL || m_last_online=="")
//        return "not in data";
//    return m_last_online;
//}

//QString JikanModel::getGender()
//{
//    if(!m_isParametersAdded)
//        return m_gender;
//    if(m_gender==NULL || m_gender=="")
//        return "not in data";
//    return m_gender;
//}

//QString JikanModel::getBirthday()
//{
//    if(!m_isParametersAdded)
//        return m_birthday;
//    if(m_birthday==NULL || m_birthday=="")
//        return "not in data";
//    return m_birthday;
//}

//QString JikanModel::getLocation()
//{
//    if(!m_isParametersAdded)
//        return m_location;
//    if(m_location==NULL || m_location=="")
//        return "not in data";
//    return m_location;
//}

//QString JikanModel::getJoined()
//{
//    if(!m_isParametersAdded)
//        return m_joined;
//    if(m_joined==NULL || m_joined=="")
//        return "not in data";
//    return m_joined;
//}

