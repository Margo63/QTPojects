#include "search.h"
#include <QString>
#include <QDebug>
Search::Search(QObject* parent):QObject(parent)
{

}

QStringList Search::nameList() const
{
    //if(m_search=="")
        return m_nameList;

//    QStringList result;
//    //for(int i=0;i<m_nameList.size();i++){
//       // if(m_nameList[i].contains(m_search)){
//            //qDebug()<<m_nameList[i];
//           // result.push_back(m_nameList[i]);
//        //}
//  //  }

//    return result;
}

QString Search::search() const
{
    return m_search;
}

void Search::addName(QString name)
{
    m_nameList.push_back(name);
    emit nameListChanged();
}

void Search::setSearch(QString search)
{
    qDebug()<<"qqq";
    m_search = search;
    qDebug()<<"aaa";
   // emit searchChanged();
     qDebug()<<"zzz";
}

