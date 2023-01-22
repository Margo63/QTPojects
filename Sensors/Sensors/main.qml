import QtQuick 2.15
import QtQuick.Window 2.15
import QtSensors 5.2
import QtQuick.Controls 2.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //Датчик приближения
//    ProximitySensor{
//        id: proximity
//        active: true
//    }

//    Switch{
//        anchors.centerIn:parent
//        enabled: proximity.active
//        checked: proximity.active && proximity.reading.near
//        scale:10
//    }


    //датчик освещенности
//    LightSensor{
//        id: lightSensors
//        active:true
//    }
//    Label{
//        anchors.centerIn: parent
//        text: lightSensors.reading ?
//                  qsTr("%1 lux").arg(lightSensors.reading.illuminance):
//                  qsTr("Unknown")
//        font.pixelSize: 30
//        color: "darkblue"
//    }

    //датчик Accelerometer

//    Accelerometer{
//        id:accelerometer
//    }

//    Button{
//        text:"Click"
//        onClicked: {
//            console.log("x = ",accelerometer.reading.x)
//            console.log("y = ",accelerometer.reading.y)
//            console.log("z = ",accelerometer.reading.z)
//        }
//    }

    Gyroscope{
        id:gyroscope
    }

    Button{
        text:"Click"
        onClicked: {
            console.log("x = ",gyroscope.reading.x)
            console.log("y = ",gyroscope.reading.y)
            console.log("z = ",gyroscope.reading.z)
        }
    }
}
