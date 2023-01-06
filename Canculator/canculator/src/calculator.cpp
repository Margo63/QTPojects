#include "calculator.h"
#include <QDebug>

Calculator::Calculator(QObject *parent):QObject(parent)
{

}

QString Calculator::result() const
{
    return m_result;//геттер
}

void Calculator::getNumber(QString add,int operation)
{


    qDebug()<<"OPERATION: "<<operation;
    switch(operation){
        case -1://получение числа

            if(choosen_operation==-1){//если операция не выбрана, то данные записываются в первую переменную
                input+=add;
            }else{                      //если операция выбрана, то данные записываются во вторую переменную

                input2+=add;
            }
            m_result+=add;//для вывода на экран
            break;

        case CLEAN:
            qDebug()<<"clean";//сброс данных
            cleaner();
            break;

        case RESULT:
            setResult();//выполнение выбраной операции
            break;

        default:
            m_result="";
            choosen_operation=operation;//определение операции
    }

    emit resultChanged();



}

void Calculator::plus()
{
    r=input.toFloat()+input2.toFloat();
}

void Calculator::minus()
{
    r=input.toFloat()-input2.toFloat();
    qDebug()<<r;
}

void Calculator::multiplication()
{
    r=input.toFloat()*input2.toFloat();
}

void Calculator::division()
{
    r=input.toFloat()/input2.toFloat();
}

void Calculator::cleaner()
{
    qDebug()<<"cleaner";
    m_result="";
    input="0";
    input2="0";
    r=0;
    choosen_operation=-1;
}

void Calculator::setResult()
{

    switch(choosen_operation){

        case DIV:
            division();
            break;

        case MULTI:
            multiplication();
            break;

        case MINUS:
            minus();
            break;

        case PLUS:
            plus();
            break;

    }
    m_result = QString::number(r);//результат операции преобразуется в строку
    input=m_result;               //в первое число записывается результат
    choosen_operation=-1;         //сброс старой операции и второй переменной
    input2="0";


}
