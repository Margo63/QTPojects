import QtQuick 2.15
import QtQuick.Window 2.15
import ru.auroraos.Game 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Card Game")

    Game{
        id:game
    }

    ListModel{
        id:dataModel
        ListElement{color:"green";enabled:true}
        ListElement{color:"yellow";enabled:true}
        ListElement{color:"blue";enabled:true}
        ListElement{color:"green";enabled:true}
        ListElement{color:"red";enabled:true}

        ListElement{color:"yellow";enabled:true}
        ListElement{color:"green";enabled:true}
        ListElement{color:"red";enabled:true}
        ListElement{color:"blue";enabled:true}
        ListElement{color:"yellow";enabled:true}

        ListElement{color:"blue";enabled:true}
        ListElement{color:"yellow";enabled:true}
        ListElement{color:"blue";enabled:true}
        ListElement{color:"red";enabled:true}
        ListElement{color:"yellow";enabled:true}

        ListElement{color:"green";enabled:true}
        ListElement{color:"red";enabled:true}
        ListElement{color:"blue";enabled:true}
        ListElement{color:"yellow";enabled:true}
        ListElement{color:"blue";enabled:true}

        ListElement{color:"blue";enabled:true}
        ListElement{color:"yellow";enabled:true}
        ListElement{color:"red";enabled:true}
        ListElement{color:"green";enabled:true}
        ListElement{color:"blue";enabled:true}

        ListElement{color:"red";enabled:true}
        ListElement{color:"green";enabled:true}
        ListElement{color:"blue";enabled:true}
        ListElement{color:"yellow";enabled:true}
        ListElement{color:"green";enabled:true}

        ListElement{color:"blue";enabled:true}
        ListElement{color:"red";enabled:true}
        ListElement{color:"blue";enabled:true}
        ListElement{color:"green";enabled:true}
        ListElement{color:"blue";enabled:true}
    }

    Grid{
        rows:5
        columns:6
        flow: Grid.TopToBottom
        anchors.centerIn:  parent
        Repeater{
            delegate:               //автозаполнение
                Rectangle{
                    id:rec
                    width: 50
                    height:50
                    color:model.color
                    border.color: "lightgray"

                    MouseArea{
                        id:mouse
                        anchors.fill:parent
                        enabled: model.enabled
                        onClicked: {
                            game.setColor(model.color,index);
                            if(game.change){
                                dataModel.setProperty(game.id1,"color","white")
                                dataModel.setProperty(game.id2,"color","white")
                                dataModel.setProperty(game.id1,"enabled","false")
                                dataModel.setProperty(game.id2,"enabled","false")
                            }
                        }
                    }
                }
            model:dataModel

        }
    }
}
