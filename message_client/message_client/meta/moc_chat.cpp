/****************************************************************************
** Meta object code from reading C++ file 'chat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/layout/chat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatMainWindow_t {
    QByteArrayData data[22];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatMainWindow_t qt_meta_stringdata_ChatMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ChatMainWindow"
QT_MOC_LITERAL(1, 15, 11), // "messageSlot"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "payloadId"
QT_MOC_LITERAL(4, 38, 4), // "text"
QT_MOC_LITERAL(5, 43, 10), // "actionSlot"
QT_MOC_LITERAL(6, 54, 6), // "action"
QT_MOC_LITERAL(7, 61, 23), // "listUserItemClickedSlot"
QT_MOC_LITERAL(8, 85, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 102, 4), // "item"
QT_MOC_LITERAL(10, 107, 15), // "textChangedSlot"
QT_MOC_LITERAL(11, 123, 7), // "newText"
QT_MOC_LITERAL(12, 131, 15), // "sendClickedSlot"
QT_MOC_LITERAL(13, 147, 19), // "settingsClickedSlot"
QT_MOC_LITERAL(14, 167, 25), // "updateSettingsClickedSlot"
QT_MOC_LITERAL(15, 193, 17), // "reportClickedSlot"
QT_MOC_LITERAL(16, 211, 27), // "refeshConcurrentPayloadSlot"
QT_MOC_LITERAL(17, 239, 24), // "userImageURLResolverSlot"
QT_MOC_LITERAL(18, 264, 14), // "QNetworkReply*"
QT_MOC_LITERAL(19, 279, 5), // "reply"
QT_MOC_LITERAL(20, 285, 34), // "concurrentUserImageURLResolve..."
QT_MOC_LITERAL(21, 320, 17) // "buildUserListSlot"

    },
    "ChatMainWindow\0messageSlot\0\0payloadId\0"
    "text\0actionSlot\0action\0listUserItemClickedSlot\0"
    "QListWidgetItem*\0item\0textChangedSlot\0"
    "newText\0sendClickedSlot\0settingsClickedSlot\0"
    "updateSettingsClickedSlot\0reportClickedSlot\0"
    "refeshConcurrentPayloadSlot\0"
    "userImageURLResolverSlot\0QNetworkReply*\0"
    "reply\0concurrentUserImageURLResolverSlot\0"
    "buildUserListSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatMainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x08 /* Private */,
       5,    2,   79,    2, 0x08 /* Private */,
       7,    1,   84,    2, 0x08 /* Private */,
      10,    1,   87,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    1,   95,    2, 0x08 /* Private */,
      20,    1,   98,    2, 0x08 /* Private */,
      21,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,

       0        // eod
};

void ChatMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageSlot((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->actionSlot((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->listUserItemClickedSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->textChangedSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->sendClickedSlot(); break;
        case 5: _t->settingsClickedSlot(); break;
        case 6: _t->updateSettingsClickedSlot(); break;
        case 7: _t->reportClickedSlot(); break;
        case 8: _t->refeshConcurrentPayloadSlot(); break;
        case 9: _t->userImageURLResolverSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->concurrentUserImageURLResolverSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 11: _t->buildUserListSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChatMainWindow::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_ChatMainWindow.data,
    qt_meta_data_ChatMainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChatMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatMainWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::ChatMainWindow"))
        return static_cast< Ui::ChatMainWindow*>(this);
    return QDialog::qt_metacast(_clname);
}

int ChatMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
