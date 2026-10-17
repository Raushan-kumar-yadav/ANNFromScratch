import QtQuick
import CustomGraph 1.0 

Rectangle {
     width: 600
    height: 400
    color: "#222222"  

    Ploter {
        id: customPloter
        objectName: "myPloter"  
        anchors.fill: parent
        anchors.margins: 20
    }
}