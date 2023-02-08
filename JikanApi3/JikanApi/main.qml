import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import Processing 1.0
//https://docs.api.jikan.moe/#tag/users
//чтоб не потерять
Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Jikan")
    property var model
    property bool check: true
    //функция куда передаем имя
    function getINFO(username){
        var request = new XMLHttpRequest()  //создаем объект
        request.open('GET',"https://api.jikan.moe/v4/users/"+username)//формируем запрос
        //первый параметр тип запроса, далее url (если нужно с параметрами, они указываются после ?, между собой разделяются &)
        //в данном случае просто path

        request.setRequestHeader('Content-Type', 'application/json')//устанавливаем Headers

        request.onreadystatechange = function() {//определяем функцию, которая будет выполняться при изменении readyState
                      if (request.readyState === XMLHttpRequest.DONE) {
                          //200 - код успешного завершения
                          if (request.status && request.status === 200) {
                              window.model = JSON.parse(request.responseText)//преобразование в объект
                              processing.setParameters(model.data.mal_id,model.data.username,model.data.url,model.data.images.jpg.image_url,
                                                       model.data.images.webp.image_url,model.data.last_online,model.data.gender,model.data.birthday,
                                                       model.data.location,model.data.joined);
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





        Text{
            text:processing.username

        }
        Text{
            text:processing.malId
        }
        Text{
            text:processing.url
        }
        Text{
            text:processing.lastOnline
        }
        Text{
            text:processing.gender
        }
        Text{
            text:processing.birthday
        }
        Text{
            text:processing.location
        }
        Text{
            text:processing.joined
        }
        Image{
            width:150
            height:150
            source:processing.imageJpg
        }


    }


    Processing{
        id:processing
    }






}
