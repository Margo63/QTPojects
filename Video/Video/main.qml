import QtQuick 2.15
import QtQuick.Window 2.15
import QtMultimedia 5.0//видео
import QtQuick.Controls 2.0//кнопки

//для добавления видео нужно зайти в qrc файл и там прописать

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column{
        anchors.fill:parent
        Video{
            width:parent.width
            height:400
            id: video
            source:"qrc:/video/second.mp4"    //абсолютный путь file:///Users/margarita/Movies/smth.mp4
            autoPlay: true//будет воспроизводиться при включении приложения
            focus: true

        }
        Row{
            width:parent.width
            spacing:10
            Button{
                text:"PLAY"
                onClicked: {
                    video.play() //воспроизведение(не заново, а продолжая с места остановки)
                }
            }
            Button{
                text:"PAUSE"
                onClicked: {
                    video.pause() //пауза
                }
            }
            Button{
                text:"SEEK"
                onClicked: {
                    //console.log(video.position)//показывает время в милисекундах
                    video.seek(10670)//можно "переместить" показ видео (метод принимает милисекунды)
                }
            }
            Button{
                text:"RESTART"
                onClicked: {

                    video.seek()//по умолчанию перемещает в начало
                }
            }
        }
    }
}
