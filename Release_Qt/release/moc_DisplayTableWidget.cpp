/****************************************************************************
** Meta object code from reading C++ file 'DisplayTableWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gui/DisplayTableWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DisplayTableWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DisplayTableWidget_t {
    QByteArrayData data[7];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DisplayTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DisplayTableWidget_t qt_meta_stringdata_DisplayTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DisplayTableWidget"
QT_MOC_LITERAL(1, 19, 27), // "m_slot_current_cell_changed"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 10), // "currentRow"
QT_MOC_LITERAL(4, 59, 13), // "currentColumn"
QT_MOC_LITERAL(5, 73, 11), // "previousRow"
QT_MOC_LITERAL(6, 85, 14) // "previousColumn"

    },
    "DisplayTableWidget\0m_slot_current_cell_changed\0"
    "\0currentRow\0currentColumn\0previousRow\0"
    "previousColumn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DisplayTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,

       0        // eod
};

void DisplayTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DisplayTableWidget *_t = static_cast<DisplayTableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->m_slot_current_cell_changed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject DisplayTableWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_DisplayTableWidget.data,
      qt_meta_data_DisplayTableWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DisplayTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplayTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DisplayTableWidget.stringdata0))
        return static_cast<void*>(const_cast< DisplayTableWidget*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int DisplayTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
