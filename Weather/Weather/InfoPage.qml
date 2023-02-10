import QtQuick 2.0
import QtQuick.Controls 2.0
Item {
    Column{
        anchors.fill:parent
        Button{
            width:100
            height:50
            text:"Settings"

            onClicked: {
                stack.push(settings_page)
            }

        }
        TextEdit{
            id:input_text
            width:parent.width
            height:50
        }
        Button{
            width:100
            height:50
            text:"GET Weather"

            onClicked: {
                getInfo(input_text.text)
            }
        }
        Text{
            text:"name: " + weather.name
        }
        Text{
            text:"country: " + weather.country
        }
        Text{
            text:"temperature: " + weather.temperature + " " + weather.temp
        }
        Text{
            text:"feelslike: " + weather.feelslike + " " + weather.temp
        }
        Text{
            text:"gust: " + weather.gust + " " + weather.speed
        }
        Text{
            text:"wind: " + weather.wind + " " + weather.speed
        }
        Text{
            text:"pressure: " + weather.pressure + " " + weather.press
        }
        Text{
            text:"humidity: " + weather.humidity + "%"
        }
    }
}
