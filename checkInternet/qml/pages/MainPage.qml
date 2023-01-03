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
    id:page1
    objectName: "mainPage"
    allowedOrientations: Orientation.All
    state: "internet_not"
    backgroundColor: "firebrick"
 //   property string checkUrl: "http://www.google.com"
    property string checkUrl: "http://192.168.1.5"
    property alias checkUrl2 : page1.checkUrl
    states: [
        State {
            name: "internet_ok"
            PropertyChanges {
                target: page1;
                backgroundColor: "forestgreen"

            }
            PropertyChanges {
                target: label;
                text:"Internet connection ok"

            }
        },
        State {
            name: "internet_not"
            PropertyChanges {
                target: page1;
                backgroundColor: "firebrick"
            }
            PropertyChanges {
                target: label;
                text:"No Internet"

            }
        }
    ]
    Timer {
         id: timer
     }
     function delay(delayTime,cb) {
         timer.interval = delayTime;
         timer.repeat = false;
         timer.triggered.connect(cb);
         timer.start();
     }

     Timer {
          id: timer2
      }
      function repeat(delayTime,cb) {
          timer2.interval = delayTime;
          timer2.repeat = true;
          timer2.triggered.connect(cb);
          timer2.start();
      }

//    Column{
//        spacing: 2
//        height: parent.height
//        id: layout
//        objectName: "layout"
//        width: parent.width




   //     }
        Label {
            id:label
            text:  "Есть доступ в интернет"
            font.pixelSize: 42
        }
//        Text {
//                anchors.centerIn: parent
//                text: page1.checkUrl
//            }

        MouseArea{
            objectName: "mouse"
            id: mouse
            //text:"Check"
            //width: parent.width
            anchors.fill: parent
            onClicked: {
              //  while(true){


        //    }
            }
            IconButton {
                objectName: "aboutButton"
                icon.source: "image://theme/icon-m-about"
                anchors.verticalCenter: parent.verticalCenter
                onClicked:{

                    pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
                }

             }

    Timer {
        id: timer3;
        interval: 2500;
        running: true;
        repeat: true;

        onTriggered: {
            var req = new XMLHttpRequest;
            console.log(page1.checkUrl);
            req.open("GET",page1.checkUrl.toString());

            delay(1000,function(){
                req.abort();
                console.log("response", "timed out");
            })
            req.onreadystatechange = function() {
                if (req.readyState === XMLHttpRequest.DONE) {
                    timer.stop();
                    if (req.status && req.status === 200) {
                        console.log("response", req.responseText);
                        page1.state = "internet_ok";
                    } else {
                        page1.state = "internet_not";
                        console.log("HTTP:", req.status, req.statusText)
                    }
                }
            }


            req.send();


        }
    }


    }



}

