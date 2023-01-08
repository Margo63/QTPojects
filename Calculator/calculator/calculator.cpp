#include "calculator.h"
#include <QDebug>

Calculator::Calculator(QObject *parent):QObject(parent)
{

}

QString Calculator::result() const
{
    return m_result;
}

void Calculator::getNumber(QString add,int operation)
{


    qDebug()<<"OPERATION: "<<operation;
    switch(operation){
        case -1:

            if(choosen_operation==-1){
                input+=add;
            }else{

                input2+=add;
            }
            m_result+=add;
            break;

        case CLEAN:
            qDebug()<<"clean";
            cleaner();
            break;

        case RESULT:
            setResult();
            break;

        default:
            m_result="";
            choosen_operation=operation;
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
    m_result = QString::number(r);
    input=m_result;
    choosen_operation=-1;
    //m_result = "";
    input2="0";


}
