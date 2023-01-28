import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
//live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn
Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property var model//сюда будем сохранять модель
    property string favorite_id //id который будем передовать

    function getFavorite(){
        var request = new XMLHttpRequest()//js

        request.open('GET',"https://api.thecatapi.com/v1/favourites"+"/"+favorite_id)//для path параметра добавляем слеш


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

    function postFavorite(image_id,sub_id){

        var request = new XMLHttpRequest()

        request.open('POST',"https://api.thecatapi.com/v1/favourites",true)

        request.setRequestHeader('Content-Type', 'application/json')
        request.setRequestHeader("x-api-key","live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn")

        //создаем тело для передачи в запросе
        var body = {
            "image_id":image_id,
            "sub_id":sub_id
        }

        request.onreadystatechange = function() {
                      if (request.readyState === XMLHttpRequest.DONE) {

                          if (request.status && request.status === 200) {


                              console.log("RESULT ", request.responseText);//выводим текст в консоль
                              var res = JSON.parse(request.responseText)
                              window.favorite_id = res['id']//сохраняем id чтобы потом вывести

                          } else{
                              console.log("ERROR ",request.status)//смотрим на HTTP код если что-то пошло не так
                          }
                      }else{
                          console.log("Status Not Done")
                      }
                 }

        request.send(JSON.stringify(body))//нужно обязательно передавать строчку, а не объект
    }

    function delFavorite(){
        var request = new XMLHttpRequest()

        request.open('DELETE',"https://api.thecatapi.com/v1/favourites"+"/"+favorite_id)//для path параметра добавляем слеш


        request.setRequestHeader("x-api-key","live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn")

        request.onreadystatechange = function() {
                      if (request.readyState === XMLHttpRequest.DONE) {

                          if (request.status && request.status === 200) {

                              //window.model = JSON.parse(request.responseText)//получаем json из строки
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

    Column{//вывод на экран полученных данных
        TextInput{
            id:input
            text:"9ccXTANkb"
        }
        Button{
            text:"POST"
            onClicked:{
                postFavorite(input.text,"your-user-1111")
            }
        }

        Button{
            text:"GET Favorite"
            onClicked:{
                getFavorite()
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
                delFavorite()
            }
        }
    }
}
