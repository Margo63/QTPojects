import QtQuick 2.15
import QtQuick.Window 2.15
import Mouse 1.0
import QtMultimedia 5.0
import QtQuick.Controls 2.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Mouse Game")
    property int catched:0

    Row{
        width:640
        height:50
        spacing:10
        Button{
            text:"START"
            onClicked: {
                timer.start()
            }
        }
        Button{
            text:"END"
            onClicked:{
                timer.stop()
            }
        }
        Text{
            text:"Catched: "+catched//выводим сколько раз поймали
        }
    }

    Timer {
        id:timer
        interval: 100
        repeat: true//нужно чтобы была не только одна итерация
        onTriggered: {
            obj_mouse.move()//каждые 100 мс меняем позицию мыши
        }
    }

    Rectangle{
        id:mouse
        width:100
        height:100
        radius:height/2
        color:"lightgray"
        x:obj_mouse.x//передаем позицию "собственной" мыши
        y:obj_mouse.y
        MouseArea{
            anchors.fill:parent
            onClicked:{
                player.seek(0)//рестарт музыки
                catched+=1//плюс один к счетчику
                obj_mouse.changePosition()//изменение позицию на рандом
            }
        }

    }
    Audio{
        id: player
        source:"qrc:/music/mouse.mp3"
        autoLoad: true
        autoPlay: true
    }


    Mouse{
        id:obj_mouse
    }

}


