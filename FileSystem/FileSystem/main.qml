import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Dialogs 1.0
Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property string tmp_url: ""

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.pictures
        nameFilters: [ "*.jpg *.png" ]
        onAccepted: {         
            window.tmp_url = fileDialog.fileUrl
        }    

    }

    Column{
       anchors.fill:parent
       Text{
           text: window.tmp_url
       }
       Image{
           width:200
           height:200
           source: window.tmp_url
       }
       Rectangle{
           color:"lightblue"
           width:150
           height:50
           Text{
               text:"click"
           }

           MouseArea{
               anchors.fill:parent

               onClicked:{
                   fileDialog.visible = true
               }
           }
       }
    }
}




//    ListModel{
//        id:model
//        Component.onCompleted: {
//            append({
//                       name:"Home",
//                       path:StandardPaths.home
//                   });
//            append({
//                       name:"Music",
//                       path:StandardPaths.music
//                   });
//            append({
//                       name:"Pictures",
//                       path:StandardPaths.pictures
//                   });
//        }
//    }

//    Grid{
//        rows: 3
//        columns: 1
//        spacing: 10
//        Repeater{
//            delegate: Text{
//                text: model.name
//            }
//                model:model
//        }

//    }
