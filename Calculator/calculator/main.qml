import QtQuick 2.15
import QtQuick.Window 2.15
import ru.auroraos.Calculator 1.0
Window {
    id:mainPage
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")



    Calculator{
        id:calculator
    }

    Column{
       anchors.fill:parent
       Text{
           text:calculator.text||"0"
       }
       ListModel {//CLEAN=0, DIV, MULTI, MINUS, PLUS, RESULT
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
                              color:"white"   //выбор цвета в зависимоти от наведения мыши
                              border.color: "lightgray"
                              Text{
                                  anchors.centerIn: rec
                                  text:model.text  //текст для визуализации автазаполнения
                              }

                              MouseArea{
                                  id:mouse
                                  anchors.fill:parent
                                  onClicked: calculator.getNumber(model.text,model.operation)


                              }

                              //Changes{id:visibility}          //QObject типа Changes
                          }

                      model:dataModel

                  }
       }





   }
}
