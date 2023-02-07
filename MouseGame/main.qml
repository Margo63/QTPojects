import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import MouseGame 1.0

ApplicationWindow {
    visible: true

    property int width_w: parent.width
    property int height_w: parent.height

    Mouse {
        id: obj_mouse
    }

    Timer {
        id: timer
        interval: 100
        repeat: true
        onTriggered: {
            obj_mouse.move()
        }
    }

    Row {
        width: 640
        height: 50
        spacing: 50

        Button {
            text: "start"
            onClicked: {
                obj_mouse.windowSize(width_w, height_w)

                timer.start()
                obj_mouse.setState(true)
            }
        }

        Text {
            id: score
            text: qsTr("Score: " + obj_mouse.score)
        }

        Button {
            text: "stop"
            onClicked: {
                timer.stop()
                obj_mouse.setState(false)
            }
        }
    }

    Rectangle {
        id: mouse
        width: 100
        height: 100
        radius: width / 2
        color: "lightgray"
        x: obj_mouse.x
        y: obj_mouse.y

        MouseArea {
            anchors.fill: parent
            onClicked: {
                obj_mouse.changePosition()
            }
        }
    }
}

