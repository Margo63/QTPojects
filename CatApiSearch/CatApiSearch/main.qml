import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("SearchBreeds")
    property var model

    function getINFO(breed_id){
        var request = new XMLHttpRequest()  //создаем объект
        request.open('GET',"https://api.thecatapi.com/v1/images/search?breed_ids="+breed_id+"&limit=10")

        request.setRequestHeader('Content-Type', 'application/json')//устанавливаем Headers
        request.setRequestHeader('x-api-key', 'live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn')

        request.onreadystatechange = function() {//определяем функцию, которая будет выполняться при изменении readyState
                      if (request.readyState === XMLHttpRequest.DONE) {
                          //200 - код успешного завершения
                          if (request.status && request.status === 200) {
                              window.model = JSON.parse(request.responseText)//преобразование в объект
                              console.log("RESULT ", request.responseText);//посмотреть что пришло


                          } else{
                              console.log("ERROR ",request.status)

                          }
                      }else{
                          console.log("Status Not Done")

                      }
                 }
        request.send()//отправляем запрос

    }
    ScrollView{

    anchors.fill:parent

    Column{
        anchors.fill:parent
        TextEdit{
            id:input_text
            width:parent.width
            height:50
        }
        Button{
            id:get_data_button
            width:100
            height:50
            text:"GET DATA"

            onClicked: {
                getINFO(input_text.text)
            }
        }

            Repeater{
                model:window.model
                delegate:Image{
                    width:100
                    height:100
                    source:window.model[index].url
                }
            }


    }
    }








}
