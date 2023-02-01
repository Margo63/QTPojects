/****************************************************************************
** Meta object code from reading C++ file 'delivery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../DeliveryFilter/delivery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'delivery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Delivery_t {
    QByteArrayData data[13];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Delivery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Delivery_t qt_meta_stringdata_Delivery = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Delivery"
QT_MOC_LITERAL(1, 9, 10), // "filtration"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "filter_value"
QT_MOC_LITERAL(4, 34, 11), // "filter_type"
QT_MOC_LITERAL(5, 46, 10), // "pizzaCount"
QT_MOC_LITERAL(6, 57, 11), // "filterCount"
QT_MOC_LITERAL(7, 69, 8), // "getPrice"
QT_MOC_LITERAL(8, 78, 5), // "index"
QT_MOC_LITERAL(9, 84, 4), // "list"
QT_MOC_LITERAL(10, 89, 7), // "getType"
QT_MOC_LITERAL(11, 97, 9), // "getRegion"
QT_MOC_LITERAL(12, 107, 7) // "getName"

    },
    "Delivery\0filtration\0\0filter_value\0"
    "filter_type\0pizzaCount\0filterCount\0"
    "getPrice\0index\0list\0getType\0getRegion\0"
    "getName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Delivery[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x02 /* Public */,
       5,    0,   54,    2, 0x02 /* Public */,
       6,    0,   55,    2, 0x02 /* Public */,
       7,    2,   56,    2, 0x02 /* Public */,
      10,    2,   61,    2, 0x02 /* Public */,
      11,    2,   66,    2, 0x02 /* Public */,
      12,    2,   71,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::QString, QMetaType::Int, QMetaType::Int,    8,    9,

       0        // eod
};

void Delivery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Delivery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filtration((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: { int _r = _t->pizzaCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->filterCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->getPrice((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->getType((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->getRegion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getName((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Delivery::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Delivery.data,
    qt_meta_data_Delivery,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Delivery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Delivery::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Delivery.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Delivery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
