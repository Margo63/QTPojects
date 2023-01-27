import QtQuick 2.15
import QtQuick.Window 2.15
//live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn
Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property var model
    function getINFO(){
        var request = new XMLHttpRequest()

        var params = "limit=5";

        request.open('GET',"https://api.thecatapi.com/v1/images/search"+"?"+params)
        request.setRequestHeader('Content-Type', 'application/json')
        request.setRequestHeader("x-api-key","live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn")
        request.onreadystatechange = function() {
                      if (request.readyState === XMLHttpRequest.DONE) {

                          if (request.status && request.status === 200) {

                              window.model = JSON.parse(request.responseText)
                              console.log("RESULT ", request.responseText);

                          } else{
                              console.log("ERROR ",request.status)
                          }
                      }else{
                          console.log("Status Not Done")
                      }
                 }
        request.send()
    }
    Component.onCompleted: {
        getINFO()
        console.log()
    }
    Column{
        anchors.fill:parent
        spacing:5
        Repeater{
            model:window.model
            delegate: Rectangle{
                width:150
                height:150

                Image{
                    height:150
                    width:150
                    source:modelData['url']
                }
            }
        }
    }
}
