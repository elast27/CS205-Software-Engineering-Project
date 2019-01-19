import QtQuick 2.10
import QtQuick.Controls 2.2
import QtQuick.Window 2.10
import QtPositioning 5.5
import QtLocation 5.6
//import io.qt.locationfinder 1.0
Window {
    id: root
    visible: true
    width: 640
    height: 480
    property alias root: root
    title: qsTr("Rescue Me")

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(40.6415, -75.2276) // Easton
        zoomLevel: 15
    }

    Rectangle {
        id: menu
        x: 208
        y: 72
        width: 225
        height: 308
        color: "#e40000"
        radius: 11
        visible: true
        border.width: 3

        Rectangle {
            id: menuItem_Fire
            x: 12
            y: 41
            width: 200
            height: 46
            color: "#fd7d2c"
            border.width: 2
            border.color: "#000000"

            Image {
                id: image5
                x: 1
                y: 2
                width: 42
                height: 42
                source: "../fire.png"
            }

            Text {
                id: text7
                x: 136
                y: 16
                width: 62
                height: 14
                text: qsTr("Report Fire")
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: menuItem_Shooter
            x: 12
            y: 145
            width: 200
            height: 46
            color: "#fd7d2c"
            border.width: 2

            Text {
                id: text3
                x: 79
                y: 16
                width: 121
                text: qsTr("Report Active Shooter")
                font.pixelSize: 12
            }

            Image {
                id: image2
                x: 1
                y: 2
                width: 42
                height: 42
                source: "../shooter.png"
            }
        }

        Rectangle {
            id: menuItem_Natural
            x: 12
            y: 197
            width: 200
            height: 46
            color: "#fd7d2c"
            border.width: 2

            Text {
                id: text4
                x: 74
                y: 16
                width: 126
                text: qsTr("Report Natural Disaster")
                font.pixelSize: 12
            }

            Image {
                id: image3
                x: 1
                y: 2
                width: 42
                height: 42
                source: "../natural.png"
            }
        }

        Rectangle {
            id: menuItem_Medical
            x: 12
            y: 93
            width: 200
            height: 46
            color: "#fd7d2c"
            border.width: 2

            Text {
                id: text5
                x: 55
                y: 16
                width: 145
                height: 14
                text: qsTr("Report Medical Emergency")
                font.pixelSize: 12
            }

            Image {
                id: image1
                x: 1
                y: 2
                width: 42
                height: 42
                source: "../medical.png"
            }
        }

        Rectangle {
            id: menuItem_Other
            x: 12
            y: 249
            width: 200
            height: 46
            color: "#fd7d2c"
            border.width: 2

            Text {
                id: text6
                x: 65
                y: 16
                width: 135
                text: qsTr("Report Other Emergency")
                font.pixelSize: 12
            }

            Image {
                id: image4
                x: 1
                y: 2
                width: 42
                height: 42
                source: "../!.png"
            }
        }
    }

    Rectangle {
        id: reportButton
        x: 540
        y: 380
        width: 100
        height: 100
        color: "#d20000"
        radius: 50
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        border.width: 10
        border.color: "#320000"

        MouseArea{
            onClicked: {
                menu.visible = true;
                visible = false;
            }
        }

        Text {
            id: text1
            x: 40
            y: 14
            color: "#ffe936"
            text: qsTr("!")
            font.weight: Font.ExtraBold
            font.bold: true
            font.family: "Times New Roman"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 63
        }
    }

//    LocationFinder{
//        id: lf
//    }



    PositionSource{
        id:positionSource
        updateInterval: 1000
        active: true
    }

    Plugin {
        id: mapPlugin
        name: "mapboxgl"

    }
}
