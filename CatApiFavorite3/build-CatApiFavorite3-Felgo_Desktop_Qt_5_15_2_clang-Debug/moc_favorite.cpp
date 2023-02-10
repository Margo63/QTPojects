/****************************************************************************
** Meta object code from reading C++ file 'favorite.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CatApiFavorite3/favorite.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'favorite.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Favorite_t {
    QByteArrayData data[13];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Favorite_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Favorite_t qt_meta_stringdata_Favorite = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Favorite"
QT_MOC_LITERAL(1, 9, 15), // "addCatImageList"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 2), // "id"
QT_MOC_LITERAL(4, 29, 3), // "url"
QT_MOC_LITERAL(5, 33, 11), // "addFavorite"
QT_MOC_LITERAL(6, 45, 8), // "image_id"
QT_MOC_LITERAL(7, 54, 11), // "favorite_id"
QT_MOC_LITERAL(8, 66, 12), // "postFavorite"
QT_MOC_LITERAL(9, 79, 5), // "index"
QT_MOC_LITERAL(10, 85, 14), // "deleteFavorite"
QT_MOC_LITERAL(11, 100, 12), // "onlyFavorite"
QT_MOC_LITERAL(12, 113, 9) // "null_size"

    },
    "Favorite\0addCatImageList\0\0id\0url\0"
    "addFavorite\0image_id\0favorite_id\0"
    "postFavorite\0index\0deleteFavorite\0"
    "onlyFavorite\0null_size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Favorite[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x0a /* Public */,
       5,    3,   49,    2, 0x0a /* Public */,
       8,    2,   56,    2, 0x0a /* Public */,
      10,    1,   61,    2, 0x0a /* Public */,
      11,    0,   64,    2, 0x0a /* Public */,
      12,    0,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    6,    7,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,    3,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Favorite::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Favorite *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addCatImageList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->addFavorite((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->postFavorite((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->deleteFavorite((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onlyFavorite(); break;
        case 5: _t->null_size(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Favorite::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_Favorite.data,
    qt_meta_data_Favorite,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Favorite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Favorite::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Favorite.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int Favorite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
