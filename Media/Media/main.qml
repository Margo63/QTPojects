import QtQuick 2.15
import QtQuick.Window 2.15

import QtMultimedia 5.0 //для плеера
import QtQuick.Controls 2.0 //для кнопки

///!!!!!!!!!нужно media подключать в pro файле!!!!!!!!!!!!!!!
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Audio{
        id: player//https://drive.google.com/file/d/1ySRCJ26YZPz6_zSfYa5UD3c13tOa05eU/view?usp=share_link
        //file:///Users/margarita/Music/greenday21guns.mp3
        source:"file:///Users/margarita/Music/greenday21guns.mp3"
        autoLoad: true
        autoPlay: true
    }
    Row{
        anchors.fill:parent
        spacing:10
        Button{
            text:"play"
            onClicked: {
                player.play();
            }
        }
        Button{
            text:"stop"
            onClicked: {
                player.pause();
            }
        }
    }
}
