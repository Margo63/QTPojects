import QtQuick 2.15
import QtQuick.Window 2.15
import Reading 1.0
import QtQuick.Controls 2.0
Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Control work")
    property string tmp_url:":/json/example2.json"
    property var control_work
    property string question:"q1"
    property string subject:"maths"
    property var answer: control_work["test"][subject][question]["answer"]

    Reading{
        id:read
    }

    function getCW(){//из стринга получаем json
        control_work = JSON.parse(read.getJSONOBJ())
    }
    Component.onCompleted: {
        read.setUrl(tmp_url)
        getCW()

        console.log(control_work["test"])
    }
    Column{

        anchors.fill: parent

        Row{
            width:parent.width
            height:70
            spacing:10
            Button{
                text:"maths"
                onClicked:{
                    subject = "maths"
                }
            }
            Button{
                text:"biology"
                onClicked: {
                    subject = "biology"
                }
            }
        }
        Row{
            width:parent.width
            height:70
            spacing:10
            Button{
                text:"question1"
                onClicked:{
                    question = "q1"
                }
            }
            Button{
                text:"question2"
                onClicked: {
                    question = "q2"
                }
            }
        }
        Text{
            text: control_work["test"][subject][question]["question"]
            font.pixelSize: 30
        }
        Row {
            spacing:5
            Repeater {
                model:control_work["test"][subject][question]["response_options"]
                Rectangle {
                    id:rec
                    width: 130; height: 40
                    border.width: 1
                    color: "lightblue"

                    Text{
                        text:modelData
                        font.pixelSize: 20
                    }
                    MouseArea{
                        anchors.fill:parent
                        onClicked:{
                            if(modelData===answer){
                                rec.color = "green"
                            }else{
                                rec.color="red"
                            }
                        }
                    }
                }
            }
        }
    }
}
