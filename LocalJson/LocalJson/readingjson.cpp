#include "readingjson.h"

ReadingJson::ReadingJson(QObject* parent):QObject(parent)
{
}

QString ReadingJson::url() const//геттер для путя
{
    return m_url;
}

QString ReadingJson::getJSONOBJ()
{
    qDebug()<<"READ";


    QFile file(m_url);//для чтения из qrc указываем : (без qrc) и далее сам путь

    if(!file.open(QIODevice::ReadOnly)){    //открываем файл для чтения
        qDebug()<<"Not read";               //если не открылся, то выводим сообщение и вызодим из функии
        return "";
    }
    QTextStream inStream(&file);    //для чтения

    while(!inStream.atEnd()){//пока файл не закончился
        QString line = inStream.readLine(); // читаем построчно
        m_json_file+=line;  //записываем каждую строчку в переменную m_json_file
        //qDebug()<<line;
    }

    file.close();   //закрываем файл
    return m_json_file; //возврашаем содержание файла
}

void ReadingJson::setUrl(QString url) //сеттер для путя к файлу
{
    m_url = url;
    emit urlChanged();
}
