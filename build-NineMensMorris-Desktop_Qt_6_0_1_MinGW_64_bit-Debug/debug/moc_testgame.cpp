/****************************************************************************
** Meta object code from reading C++ file 'testgame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../NineMensMorris/testgame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testgame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_testGame_t {
    const uint offsetsAndSize[10];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_testGame_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_testGame_t qt_meta_stringdata_testGame = {
    {
QT_MOC_LITERAL(0, 8), // "testGame"
QT_MOC_LITERAL(9, 4), // "init"
QT_MOC_LITERAL(14, 0), // ""
QT_MOC_LITERAL(15, 19), // "testChooseFirstTurn"
QT_MOC_LITERAL(35, 23) // "testChoosePlayerTurnGUI"

    },
    "testGame\0init\0\0testChooseFirstTurn\0"
    "testChoosePlayerTurnGUI"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_testGame[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    0 /* Private */,
       3,    0,   33,    2, 0x08,    1 /* Private */,
       4,    0,   34,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void testGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<testGame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->init(); break;
        case 1: _t->testChooseFirstTurn(); break;
        case 2: _t->testChoosePlayerTurnGUI(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject testGame::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_testGame.offsetsAndSize,
    qt_meta_data_testGame,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_testGame_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *testGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *testGame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_testGame.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int testGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
