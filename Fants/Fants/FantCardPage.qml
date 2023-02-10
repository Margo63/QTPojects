import QtQuick 2.0
import QtQuick.Controls 2.0
Item {

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
            text:"get task"
            onClicked: {
                getTask()
            }
        }

        Text{
            text:window.activity
        }

    }

}
