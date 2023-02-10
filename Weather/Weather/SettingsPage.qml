import QtQuick 2.0
import QtQuick.Controls 2.0
Item {
    Column{
        spacing:5
        anchors.fill:parent
        Button{
            width:100
            height:50
            text:"Info"

            onClicked: {
                stack.pop()
            }

        }
        Row{
            height:75
            width:parent.width
            spacing:10

            Text{
                text:"temperature"
            }
            Button{
                text:"c"
                onClicked:{
                    weather.temp = "c"

                }
                palette.button: if (text === weather.temp)
                                {
                                    return "gray"
                                }
                                else
                                {
                                    return "lightgray"
                                }


            }
            Button{
                text:"f"
                onClicked:{
                    weather.temp = "f"
                }
                palette.button: if (text === weather.temp)
                                {
                                    return "gray"
                                }
                                else
                                {
                                    return "lightgray"
                                }
            }
        }
        Row{
            height:75
            width:parent.width

            Text{
                text:"pressure"
            }
            Button{
                text:"mb"
                onClicked:{
                    weather.press = "mb"
                }
                palette.button: if (text === weather.press)
                                {
                                    return "gray"
                                }
                                else
                                {
                                    return "lightgray"
                                }
            }
            Button{
                text:"in"
                onClicked:{
                    weather.press = "in"
                }
                palette.button: if (text === weather.press)
                                {
                                    return "gray"
                                }
                                else
                                {
                                    return "lightgray"
                                }
            }
        }
        Row{
            height:75
            width:parent.width

            Text{
                text:"speed"
            }
            Button{
                text:"mph"
                onClicked:{
                    weather.speed = "mph"
                }
                palette.button: if (text === weather.speed)
                                {
                                    return "gray"
                                }
                                else
                                {
                                    return "lightgray"
                                }
            }
            Button{
                text:"kph"
                onClicked:{
                    weather.speed = "kph"
                }
                palette.button: if (text === weather.speed)
                                {
                                    return "gray"
                                }
                                else
                                {
                                    return "lightgray"
                                }
            }
        }


    }
}
