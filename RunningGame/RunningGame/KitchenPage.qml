import QtQuick 2.0
import QtQuick.Window 2.15
import QtQuick.Controls  2.2
import Kitchen 1.0

Item {

    Rectangle{
        id:oven
        width:200
        height:200
        anchors.right: parent.right
        anchors.top:parent.top
        color:"red"
        TextEdit{
            id:fire
            text:"100"
            height:50
            width:200

        }
    }

    Kitchen{
        id:kitchen
    }


    Repeater{
        model:kitchen
        delegate:Rectangle{
            id:rec
            width:model.width
            height:model.width
            x:model.x
            y:model.y
            color:"lightblue"
            Text{
                text:name
            }
            MouseArea{
                drag.target: rec
                anchors.fill:parent
                onReleased:    {
                    kitchen.collision(index,rec.x,rec.y)//столкновение с другими продуктами
                    kitchen.oven(index,Number(fire.text),oven.x,oven.y,oven.width,oven.height)//столкновение с печью
                }
                onDoubleClicked: {
                    kitchen.decay(index);//распад продуктов

                }
            }
        }

    }






}
