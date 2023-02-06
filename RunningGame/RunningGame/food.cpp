#include "food.h"

Food::Food(QString name,int x,int y):m_name(name),m_x(x),m_y(y)
{
    //при вызове конструктора добавляем имя в формулу, определяем размеры
    m_formula.resize(0);
    m_formula.push_back(name);
    getData();
}

QString Food::name() const
{
    return m_name;
}

QVector<QString> Food::formula() const
{
    return m_formula;
}

int Food::x() const
{
    return m_x;
}

int Food::y() const
{
    return m_y;
}

int Food::width() const
{
    return m_width;
}

int Food::height() const
{
    return m_height;
}

bool Food::changeFood(QVector<QString> formula)
{
    if(m_formula.count()==formula.count()){
        if(hash(m_formula)==hash(formula)){//объекты с одиноковой формулой не "смешиваем"
            return false;
        }
    }

    //объединение формул
    for(int i=0;i<formula.count();i++){
        m_formula.push_back(formula[i]);
    }

    getData();
    return true;
}


void Food::setPosition(int x, int y)
{
    m_x=x;
    m_y=y;
}

//"прожарка" в зависимости от температуры
void Food::addFire(int fire)
{

    if(fire>=300){
        m_formula.push_back("fire");
    }
    if(fire>=200){
        m_formula.push_back("fire");
    }
    if(fire>=100){
        m_formula.push_back("fire");
    }
    getData();
}

//функция хеширования
int Food::hash(QVector<QString> formula)
{
    int x=13,q=131;
    int hash=0;

    for(int i=0;i<formula.size();i++){
        int tmp_hash=0;
        for(int j=0;j<formula[i].size();j++){
            tmp_hash = (tmp_hash*x + formula[i][j].unicode())%q;
        }
        hash+=tmp_hash;
    }
    return hash;
}

//функция удаления последнего элемента
QString Food::removeLast()
{
    if(m_formula.size()==1)
        return "";

    QString last = m_formula[m_formula.count()-1];
    m_formula.pop_back();
    if(m_formula.size()==1)
        isSmt=false;
    getData();
    return last;
}

void Food::getData()
{
    int egg=0, flour=0,fire=0,sugar=0;

    for(int i=0;i<m_formula.count();i++){//подсчет элементов

        if (m_formula[i]=="egg")
            egg++;

        if (m_formula[i]=="sugar")
            sugar++;

        if (m_formula[i]=="flour")
            flour++;

        if (m_formula[i]=="fire")
            fire++;

    }
    //в зависимости от рецепта определяем свойства
    if(egg==1 && sugar==0 && flour==0 && fire==0 && !isSmt){
        m_name = "egg";
        m_width = 50;
        m_height = 50;
        return ;
    }
    if(egg==0 && sugar==1 && flour==0 && fire==0 && !isSmt){
        m_name = "sugar";
        m_width = 70;
        m_height = 70;
        return ;
    }
    if(egg==0 && sugar==0 && flour==1 && fire==0 && !isSmt){
        m_name = "flour";
        m_width = 90;
        m_height = 90;
        return ;
    }


    if(egg==1 && sugar==1 && flour==0 && fire==0 && !isSmt){
        m_name = "sweet egg";
        m_width = 80;
        m_height = 80;
        return ;
    }
    if(egg==1 && sugar==1 && flour==1 && fire==0 && !isSmt){
        m_name = "dough";
        m_width = 90;
        m_height = 90;
        return ;
    }
    if(egg==1 && sugar==1 && flour==1 && fire==1 && !isSmt){
        m_name = "cake base";
        m_width = 100;
        m_height = 100;
        return ;
    }
    if(egg==1 && sugar==1 && flour==1 && fire==2 && !isSmt){
        m_name = "burnt cake base";
        m_width = 100;
        m_height = 100;
        return ;
    }
    if(egg==1 && sugar==1 && flour==1 && fire==3 && !isSmt){
        m_name = "burned down\ncake base";
        m_width = 100;
        m_height = 100;
        return ;
    }
    if(egg==1 && sugar==2 && flour==0 && fire==0 && !isSmt){
        m_name = "cream";
        m_width = 80;
        m_height = 80;
        return ;
    }
    if(egg==2 && sugar==3 && flour==1 && fire==1 && !isSmt){
        m_name = "cake";
        m_width = 80;
        m_height = 80;
        return ;
    }

    m_name="something";
    m_height=90;
    m_width=80;
    isSmt=true;
}
