#include "trash.h"
#include <QDebug>
Trash::Trash(QObject* parent):QObject(parent)
{
    //инициализация случайного элемента
    tmp_index = generator.bounded(0,rubbish.size());
    tmp_rubbish = rubbish[tmp_index];
    m_text = tmp_rubbish.name;
}

QString Trash::text()//геттер текста
{
    return m_text;
}

int Trash::mistakes()//геттер ошибок
{
    return m_mistakes;
}

bool Trash::gameState()//геттер состояния игры
{
    return m_gameState;
}

QString Trash::getMistakeMessage()//геттер поясняющего сообщения
{
    return mistakeMessage;
}



void Trash::restart()//обновляем данные на исходные
{
    rubbish={Rubbish{"сломаный компьютер","special"},Rubbish{"обои","special"},
                                  Rubbish{"испортившейся творог","organic"},Rubbish{"стухшее мясо","organic"},
                                  Rubbish{"книги(не очень хорошие)","paper"},Rubbish{"печатные средства массовой информации","paper"},
                                  Rubbish{"консервная банка","metal"},Rubbish{"металлом","metal"},
                                  Rubbish{"упаковка от шампуня","plastic"},Rubbish{"пластиковые крышки","plastic"}};
    tmp_index = generator.bounded(0,rubbish.size());
    tmp_rubbish = rubbish[tmp_index];
    m_text = tmp_rubbish.name;
    m_mistakes=0;
    m_gameState=false;
    mistakeMessage="";
    emit textChanged();
    emit mistakesChanged();
    emit gameStateChanged();

}

void Trash::setText(QString type)
{
    //qDebug()<<type;
    if(rubbish.size()!=0){//если вектор не пуст
        if(type != tmp_rubbish.type){//если выбранная категария и правильная категория не совпадают фиксиируем ошибки
            mistakeMessage+=tmp_rubbish.name+" ваш ответ: "+type+" правильный ответ: "+tmp_rubbish.type+"\n";//фиксируем текст для вывода ошибок на экране
            m_mistakes+=1;//увеличиваем количество ошибок
            emit mistakesChanged();//сигнал для ошибок
        }else{
            rubbish.remove(tmp_index);//если все правильно, удаляем из массива
            //qDebug()<<"remove"<<rubbish.size();
            if(!rubbish.size()){//если все элементы рассмотрены(те элементов больше нет)
                if(m_mistakes==0){//если ошибок нет
                    m_text="Хорошая работа!";
                }else{//вывод количества ошибок
                    m_text="Твои ошибки = "+QString::number(m_mistakes);
                }
                m_gameState=true;//фиксируем конец игры
                emit textChanged();//сигналы о изменении статуса игры
                emit gameStateChanged();//и текста
                return;//выходим тк больше не можем генерировать случайные числа(тк размер 0)
            }

        }
        tmp_index = generator.bounded(0,rubbish.size());//случайный индекс
        tmp_rubbish = rubbish[tmp_index];//случайный элемент по полученному индексу
        m_text = tmp_rubbish.name;//передаем текс из случайного элемента
        emit textChanged();//сигнал об изменении текста
     //   qDebug()<<m_text;
    }
    }


