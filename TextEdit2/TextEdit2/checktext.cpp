#include "checktext.h"
#include <QRegExp>
CheckText::CheckText(QObject* parent):QObject(parent)
{

}
QString CheckText::text() const{
    return m_text;
}

QString CheckText::regular() const
{
    return m_regular;
}

void CheckText::setText(QString text){

//^([a-z0-9_\.-]+)@([a-z0-9_\.-]+)\.([a-z\.]{2,6})$ //почта
//([0-9]+)([a-z])?*([A-Z])?*    //моя попытка в пароль (работает не очень)
    QRegExp rx(m_regular);

    if(!rx.isValid() || rx.isEmpty()){//плохая регулярка, выходим
       return;
    }
    if(rx.exactMatch(text)){
        m_text = text;
    }else{
        m_text = "wrong";
    }
    emit textChanged();

}

void CheckText::setRegular(QString regular)
{
    m_regular = regular;
    emit regularChanged();
}
