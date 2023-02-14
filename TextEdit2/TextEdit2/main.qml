import QtQuick 2.15
import QtQuick.Window 2.15
import CheckText 1.0
import QtQuick.Controls 2.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Column{
        anchors.fill:parent
        Rectangle{
            width:parent.width
            height:50
            border.color:"black"
            border.width: 1

            TextEdit{
                id:input_text
                text: check.text
                width:parent.width
                height:50

            }

        }
        Rectangle{
            width:parent.width
            height:50
            border.color:"black"
            border.width: 1
            TextEdit{
                id:input_reg
                width:parent.width
                height:50
                onTextChanged: {
                    check.regular = input_reg.text
                }

            }
        }
        Button{
            text:"check"
            onClicked:{
                check.setText(input_text.text)
            }
        }
    }



    CheckText{
        id:check
    }


}
