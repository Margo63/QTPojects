import QtQuick 2.15
import QtQuick.Window 2.15
import Trash 1.0
import QtQuick.Controls 2.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Trash game")

    Trash {
        id: trash
    }

    Column{
        anchors.fill: parent
        Row{
            width:parent.width
            spacing :50
            Text{
                text:"Рассортируй: "+trash.text//текст из массива мусора в с++
            }
            Text{
                text:"Ошибки: "+trash.mistakes//вывод количества ошибок
            }
            Button{
                text:"RESTART"
                onClicked:{
                    trash.restart()//обновляем данные на начальные
                }
            }
            Button{
                text:"Ошибки"
                onClicked:{
                    mistakes.text = trash.getMistakeMessage()//вывод где были совершены ошибки
                }
                visible:if(trash.mistakes!=0 && trash.gameState){//если игра закончена и есть ошибки то покащываем кнопку с возможностью вызова поясняющего сообщения
                            return true;
                        }else{
                            return false;
                        }
            }
        }

        Text{
            id:mistakes
        }


        Row{
            width:parent.width
            spacing:10
            Repeater{//контейнеры
                model:[{"type":"plastic","color":"orange"},
                        {"type":"metal","color":"yellow"},
                        {"type":"paper","color":"lightblue"},
                        {"type":"organic","color":"lightgray"},
                        {"type":"special","color":"brown"}]
                delegate:Rectangle{
                    width:parent.width/5-10
                    height:60
                    color:modelData.color
                    Text{
                        text:modelData.type
                    }
                    MouseArea{
                        anchors.fill:parent
                        onClicked:{
                            trash.setText(modelData.type)//передаем выбранную категарию мусора
                        }
                    }
                }
            }
        }
    }


}
