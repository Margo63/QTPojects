import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import FanModel 1.0

Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Fants")
    property string activity:"not "


    function getTask(){
        var request = new XMLHttpRequest()  //создаем объект

        request.open('GET',"https://www.boredapi.com/api/activity")//формируем запрос

        request.setRequestHeader('Content-Type', 'application/json')//устанавливаем Headers
        request.onreadystatechange = function() {//определяем функцию, которая будет выполняться при изменении readyState
                      if (request.readyState === XMLHttpRequest.DONE) {
                          //200 - код успешного завершения
                          if (request.status && request.status === 200) {
                              var model = JSON.parse(request.responseText)//преобразование в объект
                              window.activity = model.activity
                              fan_model.addTask(model.activity,model.type,model.participants,model.price,
                                                  model.link,model.key,model.accessibility)


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
    StackView{
            anchors.fill:parent
            id:stack
            initialItem: fant_card_page
        }

    Component{
        id:fant_card_page
        FantCardPage{}
    }
    Component{
        id:list_done_cards_page
        ListDoneCardsPage{}
    }
    FanModel{
        id:fan_model
    }






}
