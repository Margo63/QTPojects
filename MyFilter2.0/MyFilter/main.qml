import QtQuick 2.15
import QtQuick.Window 2.15
import Products 1.0
import QtQuick.Controls 2.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    Products{
        id:prod
    }

    ListModel{
        id:lm
    }
    Column{
        id:col
        spacing: 10
        width:parent.width

        TextEdit{
            height:20
            width:640
            text:"product"
            id:product
        }
        TextEdit{
            height:20
            width:640
            text:"0"
            id:price
        }
        Button{

            text:"ADD"
            onClicked: {
                if(Number(price.text)){
                    prod.add(price.text,product.text)
                    lm.append({m_product:product.text,m_price:price.text})
                }

            }  
        }
        Button{

            text:"SORT PRICE"
            onClicked: {
                //console.log(lm.count)
                prod.priceSort()
                for(var i=0;i<lm.count;i++){
                    lm.set(i,{m_product:prod.getProduct(i),m_price:prod.getPrice(i).toString()})
                }
            }
        }


    }
    ListView{
        width:parent.width
        anchors.top:col.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        model:lm
        delegate: Rectangle{
            width:150
            height:50
            color:"lightblue"

            Row{
                width:parent.width
                height:70
                Text{
                    text:m_product
                }
                Text{
                    text:m_price
                }
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    prod.remove(m_price,m_product)
                    lm.remove(index)
                }
            }
        }
    }

}
