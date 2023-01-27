import QtQuick 2.15
import QtQuick.Window 2.15
import Reading 1.0
Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Means of expression")
    property string tmp_url:":/json/example1.json"
    property var means_of_expression    //средства выразительности

    Reading{
        id:read
    }
    function getMOE(){//из стринга получаем json
        means_of_expression = JSON.parse(read.getJSONOBJ())
    }
    Component.onCompleted: {
        read.setUrl(tmp_url)
        getMOE()
        console.log(means_of_expression["phraseologism"])
    }
    Column{
        anchors.fill:parent
        Text{
            text:means_of_expression["oxymoron"]
        }
        Text{
            text:means_of_expression["phraseologism"]
        }
        Text{
            text:means_of_expression["metaphor"]
        }
        Text{
            text:means_of_expression["parcelling"]
        }

    }
}
