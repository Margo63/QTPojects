import QtQuick 2.15
import QtQuick.Window 2.15
//live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn
Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property var model//сюда будем сохранять модель
    property string img_id:"ckk"//id который будем передовать

    function getINFO(){
        var request = new XMLHttpRequest()

        request.open('GET',"https://api.thecatapi.com/v1/images"+"/"+img_id)//для path параметра добавляем слеш

        request.setRequestHeader('Content-Type', 'application/json')
        request.setRequestHeader("x-api-key","live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn")

        request.onreadystatechange = function() {
                      if (request.readyState === XMLHttpRequest.DONE) {

                          if (request.status && request.status === 200) {

                              window.model = JSON.parse(request.responseText)//получаем json из строки
                              console.log("RESULT ", request.responseText);//выводим текст в консоль

                          } else{
                              console.log("ERROR ",request.status)//смотрим на HTTP код если что-то пошло не так
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
    Column{//вывод на экран полученных данных
        Text {
            text: "id: "+ window.model['id']
        }
        Text {
            text: "url: "+ window.model['url']
        }
        Text {
            text: "width: "+ window.model['width']
        }
        Text {
            text: "height: "+ window.model['height']
        }
    }
}
