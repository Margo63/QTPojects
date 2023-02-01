#include "search.h"

Search::Search(QObject* parent):QObject(parent)
{

}

void Search::addCountry(QString search)
{
    result_list.resize(0);//делаем размер 0

    for(size_t i=0;i<list_countries.size();i++){
        if(search==""){
            result_list.push_back(QString::fromStdString(list_countries[i]));//если строка пустая, то добавляем все страны
        }else{
            //toStdString() преобразуем к std::string
            //QString::fromStdString() преобразуем к QString
            //для windows есть другие функции
            //find возвращает позицию подстроки в строке (первого символа), если вхождения нет, возвращается string::npos
            if(list_countries[i].find(search.toStdString())!=std::string::npos){//если не пустая, то добавляем в финальный список по вхождению подстроки
                result_list.push_back(QString::fromStdString(list_countries[i]));
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




