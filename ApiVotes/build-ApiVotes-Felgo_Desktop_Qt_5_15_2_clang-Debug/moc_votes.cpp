/****************************************************************************
** Meta object code from reading C++ file 'votes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ApiVotes/votes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'votes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Votes_t {
    QByteArrayData data[13];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Votes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Votes_t qt_meta_stringdata_Votes = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Votes"
QT_MOC_LITERAL(1, 6, 15), // "addCatImageList"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 2), // "id"
QT_MOC_LITERAL(4, 26, 3), // "url"
QT_MOC_LITERAL(5, 30, 7), // "addVote"
QT_MOC_LITERAL(6, 38, 8), // "image_id"
QT_MOC_LITERAL(7, 47, 7), // "vote_id"
QT_MOC_LITERAL(8, 55, 8), // "postVote"
QT_MOC_LITERAL(9, 64, 5), // "index"
QT_MOC_LITERAL(10, 70, 10), // "deleteVote"
QT_MOC_LITERAL(11, 81, 8), // "onlyVote"
QT_MOC_LITERAL(12, 90, 9) // "null_size"

    },
    "Votes\0addCatImageList\0\0id\0url\0addVote\0"
    "image_id\0vote_id\0postVote\0index\0"
    "deleteVote\0onlyVote\0null_size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Votes[] = {

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

void Votes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Votes *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addCatImageList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->addVote((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->postVote((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->deleteVote((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onlyVote(); break;
        case 5: _t->null_size(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Votes::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_Votes.data,
    qt_meta_data_Votes,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Votes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Votes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Votes.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int Votes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
