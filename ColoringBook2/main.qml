import QtQuick 2.15
import QtQuick.Window 2.15
import ru.auroraos.ColoringBook 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    color: "white"    //фон


       Column{
           anchors.fill:parent
           Text {
               id: name
               text: qsTr("COLORS:\t"+colorState.color) // текст для фиксации изменений
           }
           Row{
               width: parent.width
               Rectangle{
                   color:"red"
                   border.color: "black"
                   border.width: 2
                   width: 120
                   height: 120
                   MouseArea{
                       anchors.fill: parent
                       onClicked: {
                           colorState.changeColor("red")//изменение цвета на красный (вызов функции changeColor)
                       }
                   }
               }
               Rectangle{
                   color:"blue"
                   border.color: "black"
                   border.width: 2
                   width: 120
                   height: 120
                   MouseArea{
                       anchors.fill: parent
                       onClicked: {

                           const new_c ="blue";
                           colorState.changeColor("blue")//изменение цвета на синий (вызов функции changeColor)

                       }
                   }
               }
               Rectangle{
                   color:"green"
                   border.color: "black"
                   border.width: 2
                   width: 120
                   height: 120
                   MouseArea{
                       anchors.fill: parent
                       onClicked: {
                           colorState.changeColor("green")//изменение цвета на зеленый (вызов функции changeColor)

                       }
                   }
               }

           }

           Column{
               width: parent.width
               Row{
                   width: parent.width
                   Rectangle{
                       id:rec1
                       color: "white"          //начальный цвет квадратика
                       border.color: "black"   //цвет границы
                       border.width: 2         //ширина границы
                       width: 120              //размеры квадратика
                       height: 120
                       MouseArea{                 // зона для взаимодействия
                           anchors.fill: parent // растягиваем по родителю
                           onClicked: {

                               rec1.color=colorState.color //при нажатии на квадратик изменяется цвет на тот, который хранится в colorState
                           }
                       }
                   }
                   Rectangle{
                       id:rec2
                       color: "white"
                       border.color: "black"
                       border.width: 2
                       width: 120
                       height: 120
                       MouseArea{
                           anchors.fill: parent
                           onClicked: {

                               rec2.color=colorState.color

                           }
                       }
                   }
                   Rectangle{
                       id:rec3
                       color: "white"
                       border.color: "black"
                       border.width: 2
                       width: 120
                       height: 120
                       MouseArea{
                           anchors.fill: parent
                           onClicked: {

                               rec3.color=colorState.color
                           }
                       }
                   }
               }
               Row{
                   Rectangle{
                       id:rec4
                       color: "white"
                       border.color: "black"
                       border.width: 2
                       width: 120
                       height: 120
                       MouseArea{
                           anchors.fill: parent
                           onClicked: {

                               rec4.color=colorState.color
                           }
                       }
                   }
                   Rectangle{
                       id:rec5
                       color: "white"
                       border.color: "black"
                       border.width: 2
                       width: 120
                       height: 120
                       MouseArea{
                           anchors.fill: parent
                           onClicked: {

                               rec5.color=colorState.color
                           }
                       }
                   }
                   Rectangle{
                       id:rec6
                       color: "white"
                       border.color: "black"
                       border.width: 2
                       width: 120
                       height: 120
                       MouseArea{
                           anchors.fill: parent
                           onClicked: {

                               rec6.color=colorState.color
                           }
                       }
                   }

               }
               Row{
                   Rectangle{
                       id:rec7
                       color: "white"
                       border.color: "black"
                       border.width: 2
                       width: 120
                       height: 120
                       MouseArea{
                           anchors.fill: parent
                           onClicked: {

                               rec7.color=colorState.color
                           }
                       }
                   }
                   Rectangle{
                       id:rec8
                       color: "white"
                       border.color: "black"
                       border.width: 2
                       width: 120
                       height: 120
                       MouseArea{
                           anchors.fill: parent
                           onClicked: {

                               rec8.color=colorState.color
                           }
                       }
                   }
                   Rectangle{
                       id:rec9
                       color: "white"
                       border.color: "black"
                       border.width: 2
                       width: 120
                       height: 120
                       MouseArea{
                           anchors.fill: parent
                           onClicked: {
                               rec9.color=colorState.color

                           }
                       }
                   }

               }

           }
       }

       ChangeColor { id: colorState } // пользовательский QObject
}
