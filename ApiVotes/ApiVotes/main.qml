import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Votes 1.0


Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Votes")
    property string sub_id: ""//будем хранить пользователя
    property bool cards:false //для контроля видимости
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
                                      //добавляем в модель
                                       votes_model.addCatImageList(cat_model[i].id,cat_model[i].url)
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


    function votesRequest(req,url,index=null,body=null){
        var request = new XMLHttpRequest()

        request.open(req,url)

        request.setRequestHeader('Content-Type', 'application/json') //без этого post не работает
        request.setRequestHeader("x-api-key","live_dNLfNAdpjCCFvSnRTmcvN968fPZrzccwTndgfiqoxoc3EHFyaxjJ2V7pnMheNDHn")

        request.onreadystatechange = function() {
                      if (request.readyState === XMLHttpRequest.DONE) {

                          if (request.status /*&& request.status === 200*/) {
                              if(req==="GET"){
                                 var model = JSON.parse(request.responseText)

                                  for(var i=0;i<model.length;i++){
                                      votes_model.addVote(model[i].image_id,model[i].id,model[i].image.url)
                                  }
                              }

                              if(req==="POST"){

                                  var res = JSON.parse(request.responseText)
                                  votes_model.postVote(index,res['id'])//добавляем здесь тк иначе не получим сразу актуальный id
                              }

                              console.log("RESULT ", request.responseText);//выводим текст в консоль

                          } else{
                              console.log("ERROR ",request.status)//смотрим на HTTP код если что-то пошло не так
                          }
                      }else{
                          console.log("Status Not Done")
                      }
                 }
        request.send(body)
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
                text:"your-user-1234"//чтобы каждый раз не вводить
                }
            Button{
                onClicked: {
                    if (text_input.text!=""){//если не пусто
                        window.cards= true//видимость карт
                        window.sub_id = text_input.text//сохраняем id
                        votesRequest("GET",'https://api.thecatapi.com/v1/votes?sub_id='+sub_id)//получаем фаворитов из интернета
                    }


                }
            }

            Repeater{
                id:repeater
                model:votes_model
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
                            color: isVote
                            MouseArea{
                                anchors.fill:parent
                                onClicked:{
                                    if(isVote==="yellow"){
                                        //удаление
                                        votesRequest('DELETE',"https://api.thecatapi.com/v1/votes/"+vote_id)
                                        votes_model.deleteVote(index);
                                    }else
                                    if(isVote==="lightgray"){
                                        //добавление
                                         var body = {
                                                        "image_id":id,
                                                        "sub_id":window.sub_id,
                                                        "value":1
                                                    }
                                        console.log(id,window.sub_id)
                                        votesRequest("POST",'https://api.thecatapi.com/v1/votes',index,JSON.stringify(body))
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
            text:"Votes"
            onClicked:{
                if(text_input.text!=""&& text_input.text==window.sub_id)
                    votes_model.onlyVote()//получаем только фаворитов
            }
        }
        Button{
            text:"Change"
            onClicked:{
                if(text_input.text!=""&& text_input.text==window.sub_id){
                    votes_model.null_size()//обнуяем модель
                    //получаем 10 случайных котиков
                    getCatModel('https://api.thecatapi.com/v1/images/search?limit=10')
                }
            }
        }
    }

    Votes{
        id:votes_model

    }
}
