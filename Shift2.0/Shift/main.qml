import QtQuick 2.15
import QtQuick.Window 2.15
import ru.auroraos.Shift 1.0
Window {
    id:wid
    width: 640
    height: 480
    visible: true
    title: qsTr("LabApp")
    color:"white"

    Collision{
        id:col
    }

    Rectangle{
        id:rec
        width: parent.width-50
        height: parent.height-50
        anchors.centerIn: parent
        radius: 10
        border.color: "blue"
        color: "white"
        border.width: 2


        MouseArea{
            anchors.fill:parent

        }
        Rectangle{
            id: water
            width:200
            height:300

            color: col.color
            anchors.bottom: rec.bottom
            anchors.horizontalCenter: rec.horizontalCenter
            Text{
                anchors.centerIn: parent
                text:col.text
            }
            MouseArea{
                anchors.fill:parent
                drag.target: naoh
                drag.axis: Drag.XAndYAxis
                acceptedButtons: Qt.AllButtons
            }



        }

        Rectangle{
            id: naoh
            width:50
            height:50
            radius: 25
            color: "lightgray"

            Text{
                anchors.centerIn: parent
                text: "NaOH"
            }


            MouseArea{
                anchors.fill:parent
                drag.target: naoh
                //drag.axis: Drag.XAndYAxis
                drag.maximumX: rec.width-50     //ограничение области передвижения объекта
                drag.minimumX: rec.x -25
                drag.maximumY: rec.height-50
                drag.minimumY: rec.y -25
                onPositionChanged:{
                    naoh.visible = col.collisionFunc(naoh.x,naoh.y,water.x,water.y,parent.width,"NaOH")
                }

            }
        }
        Rectangle{
            id: fenol
            width:35
            height:35
            radius: 15
            color: "lightblue"
            Text{
                anchors.centerIn: parent
                text: "fenol"
            }


            MouseArea{
                anchors.fill:parent
                drag.target: fenol
                drag.maximumX: rec.width-35    //ограничение области передвижения объекта
                drag.minimumX: rec.x -25
                drag.maximumY: rec.height-35
                drag.minimumY: rec.y -25
                onPositionChanged:{
                    fenol.visible = col.collisionFunc(parent.x,parent.y,water.x,water.y,parent.width,"fenol")
                }
            }
        }
        Rectangle{
            id: hno3
            width:50
            height:50
            radius: 25
            color: "lightyellow"
            Text{
                anchors.centerIn: parent
                text: "HNO3"
            }


            MouseArea{
                anchors.fill:parent
                drag.target: hno3
                drag.maximumX: rec.width-50     //ограничение области передвижения объекта
                drag.minimumX: rec.x -25
                drag.maximumY: rec.height-50
                drag.minimumY: rec.y -25
                onPositionChanged:{
                    hno3.visible = col.collisionFunc(parent.x,parent.y,water.x,water.y,parent.width,"HNO3")
                }
            }
            DragHandler{
                xAxis.maximum: rec.width-50
                xAxis.minimum: rec.x -25
                yAxis.maximum: rec.height-50
                yAxis.minimum: rec.y-25
            }
        }

    }
}
