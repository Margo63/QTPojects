import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import Delivery 1.0
Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Filter")
    property var types: {"hot": 1, "vegan":2,"normal":3}//объект для типа
    property var filter_type: {"price": 1, "type":2,"region":3}//объект для типа фильтрации доставки
    property var regions: {"central": 1, "south":2,"north":3,"east":4,"west":5}//объект для региона доставки


    Delivery{
        id:delivery
    }

    ListModel{
        id:list
    }
    Row{
        id:input_row
        width:parent.width
        height:50
        TextEdit{
            width:250
            height:20
            id:input_text
            text:"input"
            onTextChanged: {//если вводимый текст изменяется обнуляем модель и цвет текста
                input_text.color="black"
                list.clear()
            }
        }
        Button{

            text:"CLEAR"
            onClicked: {//при нажатии на кнопку очищаем текст и делаем его черным
                input_text.color="black"
                input_text.text=""
            }
        }

    }



    Row{
        id:buttons_row
        anchors.top:input_row.bottom
        width:parent.width
        Button{
            text:"Район"
            onClicked:{
                list.clear()//обнуляем модель
                if(window.regions[input_text.text]){//если в объекте можно сопоставить введенный текст, то фильтруем
                    delivery.filtration(Number(window.regions[input_text.text]),window.filter_type["region"])//передаем регион для фильтрации и тип фильтрации
                    for(var i=0;i<delivery.filterCount();i++){//цикл по количеству отфильтрованных элементов
                        //добавляем элемент из отфильтрованного вектора
                        list.append({type:delivery.getType(i,1),name:delivery.getName(i,1),price:delivery.getPrice(i,1),region:delivery.getRegion(i,1)})
                    }
                }else{
                    //вывод сообщения об ошибке
                    console.log("INVALID REGION")
                    input_text.color = "red"
                }

            }
        }
        Button{
            text:"Цена"
            onClicked:{
                list.clear()//обнуляем модель
                if(Number(input_text.text)&& Number(input_text.text)>0 ){//если не ноль (если введен текст без цифр, то Number вернет ноль) и значение больше нуля
                    delivery.filtration(Number(input_text.text),window.filter_type["price"])//передаем цену для фильтрации и тип фильтрации
                    for(var i=0;i<delivery.filterCount();i++){//цикл по количеству отфильтрованных элементов
                        //добавляем элемент из отфильтрованного вектора
                        list.append({type:delivery.getType(i,1),name:delivery.getName(i,1),price:delivery.getPrice(i,1),region:delivery.getRegion(i,1)})
                    }
                }else{
                    //вывод сообщения об ошибке
                    console.log("INVALID PRICE")
                    input_text.color = "red"//для красоты делаем текст красным
                }
            }
        }
        Button{
            text:"Тип еды"
            onClicked:{

                list.clear()//обнуляем модель
                if(window.types[input_text.text]){//если в объекте можно сопоставить введенный текст, то фильтруем
                    delivery.filtration(Number(window.types[input_text.text]),window.filter_type["type"])//передаем тип для фильтрации и тип фильтрации
                    for(var i=0;i<delivery.filterCount();i++){//цикл по количеству отфильтрованных элементов
                        //добавляем элемент из отфильтрованного вектора
                        list.append({type:delivery.getType(i,1),name:delivery.getName(i,1),price:delivery.getPrice(i,1),region:delivery.getRegion(i,1)})
                    }
                }else{
                    //вывод сообщения об ошибке
                    console.log("INVALID TYPE")
                    input_text.color = "red"
                }


            }
        }
        Button{
            text:"без филльтров"
            onClicked:{
                list.clear()
                for(var i=0;i<delivery.pizzaCount();i++){//цикл по количеству всех элементов
                    //добавляем элемент из вектора всех пицц
                    list.append({type:delivery.getType(i,0),name:delivery.getName(i,0),price:delivery.getPrice(i,0),region:delivery.getRegion(i,0)})
                }

            }
        }
    }
    ListView{
        spacing: 10
        anchors.top:buttons_row.bottom
        model:list
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        delegate:Rectangle{
            width:350
            height:50
            color:"lightblue"

            Row{
                spacing :5
                width:350
                height:50
                Text{
                    text:name
                }
                Text{
                    text:price
                }
                Text{
                    text:switch(type){//вывод типа
                         case 1:
                             return "hot"
                         case 2:
                             return "vegan"
                         case 3:
                             return "normal"
                         default:
                             return "none"
                         }

                }
                Text{
                    text:switch(region){//вывод региона
                         case 1:
                             return "central"
                         case 2:
                             return "south"
                         case 3:
                             return "north"
                         case 4:
                             return "east"
                         case 5:
                             return "west"
                         default:
                             return "none"
                         }
                }
            }
        }
    }
}
