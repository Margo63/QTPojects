#include "checktext.h"
#include <QDebug>
CheckText::CheckText(QObject* parent):QObject(parent)
{

}
QString CheckText::text() const{
    return m_text;
}

void CheckText::setText(QString text){



    //std::regex reg("a[a-z]");//простой пример

    std::regex reg("[0-9]+");//только цифры
   // if(regex_match(text.toStdString(),reg) && text.length()<=7){//regex_match - полное совпадение
   //     m_text=text;
   // }else{
   //     m_text="wrong";
   // }

    if(regex_search(text.toStdString(),reg) && text.length()<=7){//regex_search - частичное совпадение (будет работать если есть хотя бы одна цифра)
        m_text=text;
    }else{
        m_text="wrong";
    }

    emit textChanged();

}
