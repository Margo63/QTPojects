#include "search.h"

Search::Search(QObject* parent):QObject(parent)
{

}

void Search::addCountry(QString search)
{
    result_list.resize(0);//делаем размер 0

    for(int i=0;i<list_countries.size();i++){
        if(search==""){
            result_list.push_back(list_countries[i]);
            //если строка пустая, то добавляем все страны
        }else{
            if(list_countries[i].contains(search)){//если не пустая, то добавляем в финальный список по вхождению подстроки
                result_list.push_back(list_countries[i]);
            }
        }


    }

}

int Search::countryCount()//геттер для размера финльного списка
{
    return result_list.size();
}

QString Search::getCountry(int index)//геттер для страны
{
    return result_list[index];
}




