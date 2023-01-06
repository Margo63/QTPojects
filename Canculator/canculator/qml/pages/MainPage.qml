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
import ru.auroraos.Calculator 1.0

Page {
    id: mainPage
    objectName: "mainPage"
    allowedOrientations: Orientation.All

    Calculator{
        id:calculator
    }

    Column{
          anchors.fill:parent
          Text{
              text:calculator.text||"0"
          }
          ListModel {//CLEAN=0, DIV, MULTI, MINUS, PLUS, RESULT
                    //шаблон для заполнения
              id: dataModel
              ListElement { operation: 0;  text: "C" }
              ListElement { operation: 1;  text: "/" }
              ListElement { operation: 2;  text: "*" }
              ListElement { operation: 5;  text: "=" }

              ListElement {operation: -1; text: "7" }
              ListElement {operation: -1; text: "8" }
              ListElement {operation: -1; text: "9" }
              ListElement { operation: 3;  text: "-" }

              ListElement {operation: -1; text: "4" }
              ListElement {operation: -1; text: "5" }
              ListElement {operation: -1; text: "6" }
              ListElement { operation: 4; text: "+" }

              ListElement {operation: -1; text: "1" }
              ListElement {operation: -1; text: "2" }
              ListElement {operation: -1; text: "3" }


              ListElement {operation: -1; text: "0" }
          }

          Grid{
              rows: 5
              columns: 4
              flow: Grid.TopLeft
              anchors.left: parent.left
                     Repeater{
                         delegate:               //автозаполнение
                             Rectangle{
                                 id:rec
                                 width: mainPage.width/4
                                 height:mainPage.height/9
                                 color:"white"
                                 border.color: "lightgray"
                                 Text{
                                     anchors.centerIn: rec
                                     text:model.text  //текст из модели
                                 }

                                 MouseArea{
                                     id:mouse
                                     anchors.fill:parent
                                     onClicked: calculator.getNumber(model.text,model.operation)//при нажатии вызывается функция изменения текста


                                 }

                             }

                         model:dataModel

                     }
          }





      }
}
