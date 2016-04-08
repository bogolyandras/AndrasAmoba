import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    title: board.title
    visible: true
    minimumWidth: 300
    minimumHeight: 250

    Component.onCompleted: {
        console.log("Window loaded!")
    }

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            Qt.quit();
        }
    }

}
