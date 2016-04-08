import QtQuick 2.4
import QtQuick.Layouts 1.3

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    GridLayout {
        Component.onCompleted: {
            console.log("Gridlayout loaded!")

        }
        id: gridLayout1
        anchors.fill: parent
        columns: 3
        children: [
            Text { text: "Three"; font.bold: true; },
            Text { text: "words"; color: "red" },
            Text { text: "in"; font.underline: true },
            Text { text: "a"; font.pixelSize: 20 },
            Text { text: "row"; font.strikeout: true }]
    }

}
