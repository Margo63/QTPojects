 import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function get(){

        var request = new XMLHttpRequest()

        request.open('GET',"https://api.thecatapi.com/v1/images/search")


        request.onreadystatechange = function() {

                      if (request.readyState === XMLHttpRequest.DONE) {

                          if (request.status && request.status === 200) {
                              console.log("response", request.responseText);

                          } else {

                              console.log("HTTP:", request.status, request.statusText)
                          }
                      }else{
                          console.log("Status Not Done")
                      }
                 }
        request.send()
    }
    Button{
        width:100
        height:100
        text:"CLICK"
        onClicked: {

            get()
        }
    }
}
