import QtQuick 2.0

Text {
    width: 100; height: 100
    text: msg.author    // invokes Message::author() to get this value

    Component.onCompleted: {
        msg.author = "Cameron"  // invokes Message::setAuthor()
    }
}
