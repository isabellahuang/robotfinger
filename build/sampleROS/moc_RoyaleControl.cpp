/****************************************************************************
** Meta object code from reading C++ file 'RoyaleControl.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/sampleROS/inc/RoyaleControl.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RoyaleControl.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_royale_in_ros__RoyaleControl_t {
    QByteArrayData data[15];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_royale_in_ros__RoyaleControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_royale_in_ros__RoyaleControl_t qt_meta_stringdata_royale_in_ros__RoyaleControl = {
    {
QT_MOC_LITERAL(0, 0, 28), // "royale_in_ros::RoyaleControl"
QT_MOC_LITERAL(1, 29, 10), // "setUseCase"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 11), // "currentMode"
QT_MOC_LITERAL(4, 53, 15), // "setExposureTime"
QT_MOC_LITERAL(5, 69, 5), // "value"
QT_MOC_LITERAL(6, 75, 15), // "setExposureMode"
QT_MOC_LITERAL(7, 91, 11), // "isAutomatic"
QT_MOC_LITERAL(8, 103, 12), // "setMinFilter"
QT_MOC_LITERAL(9, 116, 12), // "setMaxFilter"
QT_MOC_LITERAL(10, 129, 10), // "setDivisor"
QT_MOC_LITERAL(11, 140, 26), // "preciseExposureTimeSetting"
QT_MOC_LITERAL(12, 167, 23), // "preciseMinFilterSetting"
QT_MOC_LITERAL(13, 191, 23), // "preciseMaxFilterSetting"
QT_MOC_LITERAL(14, 215, 21) // "preciseDivisorSetting"

    },
    "royale_in_ros::RoyaleControl\0setUseCase\0"
    "\0currentMode\0setExposureTime\0value\0"
    "setExposureMode\0isAutomatic\0setMinFilter\0"
    "setMaxFilter\0setDivisor\0"
    "preciseExposureTimeSetting\0"
    "preciseMinFilterSetting\0preciseMaxFilterSetting\0"
    "preciseDivisorSetting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_royale_in_ros__RoyaleControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       6,    1,   70,    2, 0x08 /* Private */,
       8,    1,   73,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      10,    1,   79,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void royale_in_ros::RoyaleControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoyaleControl *_t = static_cast<RoyaleControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setUseCase((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setExposureTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setExposureMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setMinFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setMaxFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setDivisor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->preciseExposureTimeSetting(); break;
        case 7: _t->preciseMinFilterSetting(); break;
        case 8: _t->preciseMaxFilterSetting(); break;
        case 9: _t->preciseDivisorSetting(); break;
        default: ;
        }
    }
}

const QMetaObject royale_in_ros::RoyaleControl::staticMetaObject = {
    { &rviz::Panel::staticMetaObject, qt_meta_stringdata_royale_in_ros__RoyaleControl.data,
      qt_meta_data_royale_in_ros__RoyaleControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *royale_in_ros::RoyaleControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *royale_in_ros::RoyaleControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_royale_in_ros__RoyaleControl.stringdata0))
        return static_cast<void*>(const_cast< RoyaleControl*>(this));
    return rviz::Panel::qt_metacast(_clname);
}

int royale_in_ros::RoyaleControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz::Panel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
