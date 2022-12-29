/*******************************************************************************
**
** Copyright (C) 2022 ru.auroraos
**
** This file is part of the Моё приложение для ОС Аврора project.
**
** Redistribution and use in source and binary forms,
** with or without modification, are permitted provided
** that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice,
**   this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
**   this list of conditions and the following disclaimer
**   in the documentation and/or other materials provided with the distribution.
** * Neither the name of the copyright holder nor the names of its contributors
**   may be used to endorse or promote products derived from this software
**   without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
** THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
** FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
** OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS;
** OR BUSINESS INTERRUPTION)
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
** EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/

import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    objectName: "mainPage"
    id: main
    allowedOrientations: Orientation.All
    backgroundColor: "white"
    property string paintColor: "red" //создание своего свойства
    states: [
        State { //cостояние в которых изменяется текст и переменная хранящая цвет
            name: "redColor"
            PropertyChanges {//изменение пользовательского свойства
                target: main
                paintColor: "red"

            }
            PropertyChanges {//изменение текста
                target: name
                text: "RED"

            }
        },
        State {
            name: "blueColor"
            PropertyChanges {
                target: main
                paintColor: "blue"
            }
            PropertyChanges {
                target: name
                text: "BLUE"

            }

        },
        State {
            name: "greenColor"
            PropertyChanges {
                target: main
                paintColor: "green"

            }
            PropertyChanges {
                target: name
                text: "GREEN"

            }
        }
    ]


    Column{
        anchors.fill:parent
        Text {
            id: name
            text: qsTr("COLORS:\t"+paintColor)//вывод текста для фиксации изменений
        }
        Row{
            width: parent.width
            Rectangle{
                color:"red"             //цвет который будет сохранен
                border.color: "black"   //цвет границы
                border.width: 2         //ширина границы
                width: 120              //размеры квадратика
                height: 120
                MouseArea{
                    anchors.fill: parent//область взаимодействие растягивается по родителю
                    onClicked: {
                        main.state = "redColor" //изменение состояния
                    }
                }
            }
            Rectangle{
                color:"blue"
                border.color: "black"
                border.width: 2
                width: 120
                height: 120
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        main.state = "blueColor"
                    }
                }
            }
            Rectangle{
                color:"green"
                border.color: "black"
                border.width: 2
                width: 120
                height: 120
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        main.state = "greenColor"
                    }
                }
            }

        }

        Column{
            width: parent.width
            Row{
                width: parent.width
                Rectangle{
                    id:rec1             //id для дальнейшего измененя
                    color: "white"      //начальный цвет
                    border.color: "black" //цве границы
                    border.width: 2     //ширина границы
                    width: 120
                    height: 120
                    MouseArea{
                        anchors.fill: parent//область взаимодействие растягивается по родителю
                        onClicked: {

                            rec1.color=main.paintColor//при нажатии изменение цвета квадратика
                        }
                    }
                }
                Rectangle{
                    id:rec2
                    color: "white"
                    border.color: "black"
                    border.width: 2
                    width: 120
                    height: 120
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {

                            rec2.color=main.paintColor
                        }
                    }
                }
                Rectangle{
                    id:rec3
                    color: "white"
                    border.color: "black"
                    border.width: 2
                    width: 120
                    height: 120
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {

                            rec3.color=main.paintColor
                        }
                    }
                }
            }
            Row{
                Rectangle{
                    id:rec4
                    color: "white"
                    border.color: "black"
                    border.width: 2
                    width: 120
                    height: 120
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {

                            rec4.color=main.paintColor
                        }
                    }
                }
                Rectangle{
                    id:rec5
                    color: "white"
                    border.color: "black"
                    border.width: 2
                    width: 120
                    height: 120
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {

                            rec5.color=main.paintColor
                        }
                    }
                }
                Rectangle{
                    id:rec6
                    color: "white"
                    border.color: "black"
                    border.width: 2
                    width: 120
                    height: 120
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {

                            rec6.color=main.paintColor
                        }
                    }
                }

            }
            Row{
                Rectangle{
                    id:rec7
                    color: "white"
                    border.color: "black"
                    border.width: 2
                    width: 120
                    height: 120
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {

                            rec7.color=main.paintColor
                        }
                    }
                }
                Rectangle{
                    id:rec8
                    color: "white"
                    border.color: "black"
                    border.width: 2
                    width: 120
                    height: 120
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {

                            rec8.color=main.paintColor
                        }
                    }
                }
                Rectangle{
                    id:rec9
                    color: "white"
                    border.color: "black"
                    border.width: 2
                    width: 120
                    height: 120
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            rec9.color=main.paintColor

                        }
                    }
                }

            }

        }
    }
}
