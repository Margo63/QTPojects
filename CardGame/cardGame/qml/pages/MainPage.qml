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
import ru.auroraos.Game 1.0

Page {
    id:mainPage
    objectName: "mainPage"
    allowedOrientations: Orientation.All

    Game{
           id:game
       }

       ListModel{                   //модель с цветами
           id:dataModel
           ListElement{color:"green";enabled:true}
           ListElement{color:"yellow";enabled:true}
           ListElement{color:"blue";enabled:true}
           ListElement{color:"green";enabled:true}
           ListElement{color:"red";enabled:true}

           ListElement{color:"yellow";enabled:true}
           ListElement{color:"green";enabled:true}
           ListElement{color:"red";enabled:true}
           ListElement{color:"blue";enabled:true}
           ListElement{color:"yellow";enabled:true}

           ListElement{color:"blue";enabled:true}
           ListElement{color:"yellow";enabled:true}
           ListElement{color:"blue";enabled:true}
           ListElement{color:"red";enabled:true}
           ListElement{color:"yellow";enabled:true}

           ListElement{color:"green";enabled:true}
           ListElement{color:"red";enabled:true}
           ListElement{color:"blue";enabled:true}
           ListElement{color:"yellow";enabled:true}
           ListElement{color:"blue";enabled:true}

           ListElement{color:"blue";enabled:true}
           ListElement{color:"yellow";enabled:true}
           ListElement{color:"red";enabled:true}
           ListElement{color:"green";enabled:true}
           ListElement{color:"blue";enabled:true}

           ListElement{color:"red";enabled:true}
           ListElement{color:"green";enabled:true}
           ListElement{color:"blue";enabled:true}
           ListElement{color:"yellow";enabled:true}
           ListElement{color:"green";enabled:true}

           ListElement{color:"blue";enabled:true}
           ListElement{color:"red";enabled:true}
           ListElement{color:"blue";enabled:true}
           ListElement{color:"green";enabled:true}
           ListElement{color:"blue";enabled:true}
       }

       Grid{
           rows:5
           columns:6
           flow: Grid.TopToBottom
           anchors.centerIn:  parent
           Repeater{
               delegate:               //автозаполнение
                   Rectangle{
                       id:rec
                       width: mainPage.width/6
                       height: mainPage.height/5
                       color:model.color
                       border.color: "lightgray"

                       MouseArea{
                           id:mouse
                           anchors.fill:parent
                           enabled: model.enabled
                           onClicked: {
                               game.setColor(model.color,index);    //отправка цвета и id по нажатию на клетку
                               if(game.change){//   если выбрано две карточки одиноковго цвета, изменяются цвет и доступ
                                   dataModel.setProperty(game.id1,"color","white")
                                   dataModel.setProperty(game.id2,"color","white")
                                   dataModel.setProperty(game.id1,"enabled",false)
                                   dataModel.setProperty(game.id2,"enabled",false)
                               }
                           }
                       }
                   }
               model:dataModel

           }
       }
}
