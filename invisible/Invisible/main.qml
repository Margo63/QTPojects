import QtQuick 2.15
import QtQuick.Window 2.15
import ru.auroraos.Invisible 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Grid{
        rows:3                      //количество рядов
        spacing: 10                 //отступ между елементами
        flow: Grid.TopToBottom      //направление заполнения
        anchors.centerIn: parent
        Repeater{
            delegate:               //автозаполнение
                Rectangle{
                    id:rec
                    width:50
                    height:50
                    color: visibility.isVisible ? "red" : "white"   //выбор цвета в зависимоти от наведения мыши
                    Text{
                        text:index  //текст для визуализации автазаполнения
                    }

                    MouseArea{
                        id:mouse
                        anchors.fill:parent
                        hoverEnabled: true


                        onEntered:{
                            visibility.changeVisibility()           //при наведении и выходе из зоны изменение bool переменной

                        }
                        onExited: {
                            visibility.changeVisibility()
                        }


                    }

                    Changes{id:visibility}          //QObject типа Changes
                }

            model:10

        }



    }




}
