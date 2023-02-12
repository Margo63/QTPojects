import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import RickAndMorty 1.0


Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Rick and Morty")


    function getINFO(persname,status){
        var request = new XMLHttpRequest()

        request.open('GET',"https://rickandmortyapi.com/api/character/?name="+persname+"&status="+status)
        request.setRequestHeader('Content-Type', 'application/json')//устанавливаем Headers
        request.onreadystatechange = function() {//определяем функцию, которая будет выполняться при изменении readyState
                      if (request.readyState === XMLHttpRequest.DONE) {
                          //200 - код успешного завершения
                          if (request.status && request.status === 200) {
                              var model = JSON.parse(request.responseText)//преобразование в объект

                              for(var i=0;i<model.results.length;i++){
                                    rickAndMortyModel.add(model.results[i].name,model.results[i].status,model.results[i].species,model.results[i].image)
                              }

                              console.log("RESULT ", request.responseText);//посмотреть что пришло

                          } else{
                              console.log("ERROR ",request.status)//ошибочки

                          }
                      }else{
                          console.log("Status Not Done")

                      }
                 }
        request.send()//отправляем запрос

    }


    ScrollView{
        anchors.top:parent.top
        anchors.bottom:parent.bottom
        anchors.right:parent.right
        anchors.left:parent.left
        Column{
            anchors.fill:parent
            spacing :10
            Rectangle{
                width:500
                height:50
                border.color: "black"
                border.width: 1

                TextEdit{
                    id:input_text
                    width:parent.width
                    height:50

                }
            }
            Rectangle{
                width:500
                height:50
                border.color: "black"
                border.width: 1

                TextEdit{
                    id:input_text2
                    width:parent.width
                    height:50
                }
            }
            Button{

                width:100
                height:50
                text:"GET DATA"

                onClicked: {
                    rickAndMortyModel.clear()
                    getINFO(input_text.text,input_text2.text)
                }
            }
            Repeater{
                model:rickAndMortyModel
                delegate:Rectangle{
                    width:500
                    height:150
                    color:"lightblue"
                    Column{
                        Text{
                            text:name
                        }
                        Text{
                            text:status
                        }
                        Text{
                            text:species
                        }
                        Image{
                            width:100
                            height:100
                            source:image
                        }
                    }
                }
            }
        }
    }


RickAndMorty{
    id:rickAndMortyModel
}





}
