import QtQuick 2.15
import QtQuick.Window 2.15
import Mouse 1.0    //подключаем свой класс
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Mouse game")

    Mouse{//добавляем свой объект
        id:mouse_object
    }

    Rectangle{
        width:100       //размерчики мышки
        height:100
        radius:width/2  //для круга, берем скругление в половину высоты или ширины
        color:"lightgray"   //цвет для мышки
        x:mouse_object.x    //берем свойство x из собственного объекта
        y:mouse_object.y    //берем свойство y из собственного объекта
        Text{
            anchors.centerIn: parent    //текстик для красоты
            text:"мышь"
        }
    }
    MouseArea{
        anchors.fill:parent     //растягиваем по родителю
        onClicked:   {
            console.log("x = ",mouse.x,"y = ",mouse.y)  //просто посмотреть посмотреть
            mouse_object.changePosition(mouse.x,mouse.y)//вызываем метод у мыши
        }
    }
}
