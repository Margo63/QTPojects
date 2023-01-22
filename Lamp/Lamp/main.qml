import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import ImportNameLamp 1.0
//для добавления нового cpp файла: исходники правой кнопкой мыши -> add New -> C/C++ -> класс с++

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Lamp")

    ObjectNameLamp{//добавление своего объекта типа ObjectNameLamp
        id:lamp     //задаем id, чтобы потом вызывать
    }
    Column{
        spacing:10      //отступы в столбце
        anchors.fill:parent // размеры столбца = размеры окна

        Rectangle{

            height:150
            width:height
            radius: height/2    //чтобы был кружок, радиус должен быть равен половине высоты объекта
            color: lamp.state ? "yellow": "lightblue" //если свойство лампочки state true - цвет желтый, если false - цвет голубой
        }
        Row{

            spacing:10      //отступы в строке
            Button{
                text:"ON"
                onClicked: {
                    lamp.on(); //вызов метода on при нажатии на кнопку
                }
            }
            Button{
                text:"OFF"
                onClicked:{
                    lamp.off(); //вызов метода off при нажатии на кнопку
                }
            }
        }
    }



}
