import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls  2.2
import Weather 1.0
Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Weather")
    function getInfo(city){
            var request = new XMLHttpRequest()//js
            request.open("GET","http://api.weatherapi.com/v1/current.json?q="+city)   //открываем передавая тип запроса и сам url

            //добавляем headers
            request.setRequestHeader('Content-Type', 'application/json') //без этого post не работает
            request.setRequestHeader("key","9264612227c9417c81b190559231002")

            request.onreadystatechange = function() {
                          if (request.readyState === XMLHttpRequest.DONE) {
                              if (request.status && request.status === 200) {

                                  var model = JSON.parse(request.responseText)
                                  weather.setData(model.location.name,model.location.country, model.current.temp_c,model.current.temp_f,
                                                  model.current.wind_mph,model.current.wind_kph,model.current.pressure_mb, model.current.pressure_in,
                                                  model.current.humidity, model.current.feelslike_c, model.current.feelslike_f,
                                                  model.current.gust_mph, model.current.gust_kph)

                                  console.log("Result",request.responseText)

                              } else{
                                  console.log("ERROR ",request.status)//смотрим на HTTP код если что-то пошло не так
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
            initialItem: info_page
        }

        Component{
            id:info_page
            InfoPage{}
        }
        Component{
            id:settings_page
            SettingsPage{}
        }
    Weather{
        id:weather
    }
}
