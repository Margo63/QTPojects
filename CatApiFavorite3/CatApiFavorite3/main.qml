import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Favorite 1.0
Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Favorite")
    property string sub_id: ""
    property bool cards:false
    function getCatModel(url){
            var request = new XMLHttpRequest()//js
            request.open("GET",url)   //открываем передавая тип запроса и сам url

            //добавляем headers
            request.setRequestHeader('Content-Type', 'application/json') //без этого post не работает
            request.setRequestHeader("x-api-key","live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn")

            request.onreadystatechange = function() {
                          if (request.readyState === XMLHttpRequest.DONE) {
                              if (request.status && request.status === 200) {
                                   var cat_model = JSON.parse(request.responseText)

                                  for(var i=0;i<cat_model.length;i++){
                                       favorite_model.addCatImageList(cat_model[i].id,cat_model[i].url)
                                   }


                              } else{
                                  console.log("ERROR ",request.status)//смотрим на HTTP код если что-то пошло не так
                              }
                          }else{
                              console.log("Status Not Done")
                          }
                     }
            request.send()//отправляем запрос
        }
    function favoriteRequest(req,url,index=null,body=null){
        var request = new XMLHttpRequest()//js

        request.open(req,url)   //открываем передавая тип запроса и сам url

        //добавляем headers
        request.setRequestHeader('Content-Type', 'application/json') //без этого post не работает
        request.setRequestHeader("x-api-key","live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn")

        request.onreadystatechange = function() {
                      if (request.readyState === XMLHttpRequest.DONE) {

                          if (request.status && request.status === 200) {
                              if(req==="GET"){//если делаем get запрос, то сохраняем модель
                                 var model = JSON.parse(request.responseText)//получаем json из строки
                                  for(var i=0;i<model.length;i++){
                                      favorite_model.addFavorite(model[i].image_id,model[i].id,model[i].image.url)
                                  }
                              }

                              if(req==="POST"){//если делаем post запрос, то сохраняем id добавленной картинки
                                  var res = JSON.parse(request.responseText)
                                  favorite_model.postFavorite(index,res['id'])
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







    ScrollView{
        anchors.fill:parent
        Column{
            Component.onCompleted: {
                getCatModel('https://api.thecatapi.com/v1/images/search?limit=10')
            }

            anchors.fill: parent
            spacing:10
            TextInput{
                id:text_input
                width:250
                height:50
                text:"your-user-1234"
                }
            Button{
                onClicked: {
                    if (text_input.text!=""){
                        window.cards= true
                        window.sub_id = text_input.text
                        favoriteRequest("GET",'https://api.thecatapi.com/v1/favourites?sub_id='+sub_id)
                    }


                }
            }

            Repeater{
                id:repeater
                model:favorite_model
                delegate: Rectangle{

                    visible:window.cards
                    width:250
                    height:75
                    color:"lightblue"
                    Row{
                        leftPadding: 10
                        width:parent.width
                        height:parent.height
                        spacing :10
                        Column{
                            spacing: 10
                            width:150
                            height:parent.height
                            Image{
                                width:50
                                height:50
                                source:image_url
                            }

                            Text{
                                text:id
                            }
                        }


                        Rectangle{
                            height:30
                            width:30
                            color: isFavorite
                            MouseArea{
                                anchors.fill:parent
                                onClicked:{
                                    if(isFavorite==="red"){
                                        favoriteRequest('DELETE',"https://api.thecatapi.com/v1/favourites/"+favorite_id)
                                       // favorite_model.changeFavoriteState(index,"lightgray");
                                        favorite_model.deleteFavorite(index);
                                    }else
                                    if(isFavorite==="lightgray"){
                                         var body = {
                                                        "image_id":id,
                                                        "sub_id":window.sub_id
                                                    }
                                        favoriteRequest("POST",'https://api.thecatapi.com/v1/favourites',index,JSON.stringify(body))

                                       // favorite_model.changeFavoriteState(index,"red");


                                    }
                                }
                            }
                        }
                    }
                }
            }


        }
    }

    Row{
        width:parent.wodth
        height:50
        anchors.bottom:parent.bottom
        Button{
            text:"Favorites"
            onClicked:{
                if(text_input.text!=""&& text_input.text==window.sub_id)
                    favorite_model.onlyFavorite()
            }
        }
        Button{
            text:"Change"
            onClicked:{
                if(text_input.text!=""&& text_input.text==window.sub_id){
                    favorite_model.null_size()
                    getCatModel('https://api.thecatapi.com/v1/images/search?limit=10')
                }


            }

        }
    }

    Favorite{
        id:favorite_model

    }
}
