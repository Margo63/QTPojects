import QtQuick 2.15
import QtQuick.Window 2.15
import Product 1.0
import QtQuick.Controls 2.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ProductList{
        id:productModel
    }

    Column{
        anchors.fill:parent

        TextInput{
            id:name
            height: 20
            width:parent.width
        }
        TextInput{
            id:product
            height: 20
            width:parent.width
        }
        TextInput{
            id:price
            height: 20
            width:parent.width
        }

        Button{
            text:"ADD"
            onClicked: {
                /*
                    Делегат - определяет, как данные должны отображаться в представлении.
                    Делегат берет все данные в модели и инкапсулирует их. Данные доступны через делегат.
                    Делегат также может записывать данные обратно в редактируемые модели (например, в обработчик onAccepted TextField).
                */

                //ниже типо логирование и валидация (как в должно быть в контроллере), но можно все проверить и в логике внутри модели
//                console.log("Получили данные")
//                if(name.text!="" && product.text!="" && Number(price.text)>0 ){
//                    console.log("Данные правильные")

//                    productModel.add(name.text,product.text,Number(price.text))

//                }else{
//                    console.log("Данные не валидны")
//                    if(name.text===""){
//                        console.log("Имя введено неверно")
//                    }
//                    if(product.text===""){
//                        console.log("Продукт введен неверно")
//                    }
//                    if(Number(price.text)<=0){
//                        console.log("Цена введена неверно")
//                    }
//                }
                 productModel.add(name.text,product.text,Number(price.text))
            }
        }

        Repeater{//view отображение карточек пользователя
            model:productModel
            delegate:Rectangle{
                width:200
                height:50
                color:"lightblue"
                Row{
                    height:50
                    width:200
                    spacing: 10
                    Text{
                        text: name
                    }
                    Text{
                        text: product
                    }
                    Text{
                        text: price
                    }
                }

                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        productModel.remove(index)
                    }
                }
            }
        }
    }
}
