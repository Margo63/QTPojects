import QtQuick 2.0
import QtQuick.Controls 2.0
import QtSensors 5.2

Item {
    property var gyroscape_x: gyroscope.reading.x
    property var gyroscape_y: gyroscope.reading.y
    property var gyroscape_z: gyroscope.reading.z
    property int count:0
    signal onGyroscape_xChanged
    onGyroscape_xChanged:{
       count+=1
    }

    signal onGyroscape_yChanged
    onGyroscape_yChanged:{
       count+=1
    }

    signal onGyroscape_zChanged
    onGyroscape_zChanged:{
       count+=1
    }


    Column{
        anchors.fill:parent
        spacing:10

        Button{
            text:"to list"
            onClicked:{
                stack.push(list_done_cards_page)
            }
        }

        Button{
            text:"SHAKE"
            onClicked:{
                if(count>=5){
                    getTask()
                }
            }
        }

        Gyroscope{
                id:gyroscope
            }
        Text{
            text:window.activity
        }

    }

}
