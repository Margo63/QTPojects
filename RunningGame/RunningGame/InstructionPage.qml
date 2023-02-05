import QtQuick 2.0
import QtQuick.Window 2.15
import QtQuick.Controls  2.2
Item {
    Column{
        anchors.fill:parent
        Button{
            onClicked:{
                stack.push(kitchen_page)
            }
        }

        Text{
            text:"HOHOHOO"
        }
    }


}
