import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls  2.2
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    objectName: "MAINWINDOW"

    StackView{
        anchors.fill:parent
        id:stack
        initialItem: instruction_page
    }

    Component{
        id:instruction_page
        InstructionPage{}
    }
    Component{
        id:kitchen_page
        KitchenPage{}
    }

}
