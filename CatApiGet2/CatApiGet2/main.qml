import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
//live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn
Window {
    id:window//задаем id чтобы потом все доставать(model и favorite_id)
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property var model//сюда будем сохранять модель
    property string favorite_id //id который будем передовать

    function sendRequest(req,url,body=null){
        var request = new XMLHttpRequest()//js

        request.open(req,url)   //открываем передавая тип запроса и сам url

        //добавляем headers
        request.setRequestHeader('Content-Type', 'application/json') //без этого post не работает
        request.setRequestHeader("x-api-key","live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn")

        request.onreadystatechange = function() {
                      if (request.readyState === XMLHttpRequest.DONE) {

                          if (request.status && request.status === 200) {
                              if(req==="GET"){//если делаем get запрос, то сохраняем модель
                                 window.model = JSON.parse(request.responseText)//получаем json из строки
                              }

                              if(req==="POST"){//если делаем post запрос, то сохраняем id добавленной картинки
                                  var res = JSON.parse(request.responseText)
                                  window.favorite_id = res['id']//сохраняем id
                              }

                              console.log("RESULT ", request.responseText);//выводим текст в консоль

                          } else{
                              console.log("ERROR ",request.status)//смотрим на HTTP код если что-то пошло не так
                          }
                      }else{
                          console.log("Status Not Done")
                      }
                 }
        request.send(body)//отправляем запрос(если нужно, то передаем тело запроса)
    }

    Column{//вывод на экран полученных данных
        TextInput{
            id:input
            text:"9ccXTANkb"
        }
        Button{
            id:but
            text:"POST"
            //формируем тело
            property var body :{
                "image_id":input.text,
                "sub_id":"your-user-1111"
            }
            onClicked:{
                sendRequest('POST',"https://api.thecatapi.com/v1/favourites",JSON.stringify(but.body))//не строкой не отправится
            }
        }
        Button{
            text:"GET Favorite"
            onClicked:{
                sendRequest('GET',"https://api.thecatapi.com/v1/favourites/"+favorite_id)//для path добавляем слеш и id
            }
        }
        Image{
            source:model['image']['url']//вытаскиваем из модели url
            width:100
            height:100
        }
        Button{
            text:"Delete"
            onClicked:{
                sendRequest('DELETE',"https://api.thecatapi.com/v1/favourites/"+favorite_id)//для path добавляем слеш и id
            }
        }
    }
}
