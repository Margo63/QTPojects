import QtQuick 2.0
import QtQuick.Window 2.15
import QtQuick.Controls  2.2
Item {
    Column{
        anchors.fill:parent
        Button{
            text:"начать игру"
            onClicked:{
                stack.push(kitchen_page)
            }
        }
        Text{
            text:"INSTRUCTION\nCAKE RECEPIE\n CREAM:\n  egg+2sugar\n CAKE BASE:\n  egg+sugar+flour+100 degree in oven\n FINAL CAKE:\n  cream+cake base"
        }
    }


}
