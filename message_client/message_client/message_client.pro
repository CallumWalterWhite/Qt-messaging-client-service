QT += dbus widgets network

HEADERS += src/layout/chat.h
SOURCES += src/layout/chat.cpp
FORMS += form/chatmainwindow.ui form/chatloginregister.ui

DBUS_ADAPTORS += org.example.chat.xml
DBUS_INTERFACES += org.example.chat.xml

# install
target.path = $$[QT_INSTALL_EXAMPLES]/dbus/chat
INSTALLS += target
