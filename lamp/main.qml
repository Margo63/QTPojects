import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0

import ImportNameLamp 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ObjectNameLamp {
        id:lamp
    }

    Column {
        spacing: 10
        Rectangle {
            height: 150
            width: height
            radius: height/2
            color: lamp.state ? "yellow": "lightblue"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    lamp.click()
                }
            }
        }

        Row {
        spacing: 10
            Button {
                text: "On"
                onClicked: {
                    lamp.on()
                }
            }
            Button {
                text: "Off"
                onClicked: {
                    lamp.off()
                }
            }
        }
    }
}
