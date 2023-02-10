import QtQuick 2.0
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import FanModel 1.0
Item {

    Column{
        anchors.fill: parent
        spacing:10
        Button{
            text:"Back"
            onClicked: {
                stack.pop()
            }
        }

        Repeater{
            model:fan_model
            delegate: Rectangle{
                width:parent.width
                height:75
                color:"lightblue"
                Column{
                    anchors.fill:parent
                    Text{
                        text:activity
                    }
                    Text{
                        text:type
                    }
                    Text{
                        text:participants
                    }
                }


            }
        }



    }

}
