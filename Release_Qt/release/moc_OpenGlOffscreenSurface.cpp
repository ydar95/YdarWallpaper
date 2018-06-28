/****************************************************************************
** Meta object code from reading C++ file 'OpenGlOffscreenSurface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Utils/OpenGlOffscreenSurface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenGlOffscreenSurface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OpenGlOffscreenSurface_t {
    QByteArrayData data[6];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenGlOffscreenSurface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenGlOffscreenSurface_t qt_meta_stringdata_OpenGlOffscreenSurface = {
    {
QT_MOC_LITERAL(0, 0, 22), // "OpenGlOffscreenSurface"
QT_MOC_LITERAL(1, 23, 12), // "frameSwapped"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 7), // "resized"
QT_MOC_LITERAL(4, 45, 6), // "update"
QT_MOC_LITERAL(5, 52, 6) // "render"

    },
    "OpenGlOffscreenSurface\0frameSwapped\0"
    "\0resized\0update\0render"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenGlOffscreenSurface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OpenGlOffscreenSurface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OpenGlOffscreenSurface *_t = static_cast<OpenGlOffscreenSurface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->frameSwapped(); break;
        case 1: _t->resized(); break;
        case 2: _t->update(); break;
        case 3: _t->render(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OpenGlOffscreenSurface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OpenGlOffscreenSurface::frameSwapped)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (OpenGlOffscreenSurface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OpenGlOffscreenSurface::resized)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject OpenGlOffscreenSurface::staticMetaObject = {
    { &QOffscreenSurface::staticMetaObject, qt_meta_stringdata_OpenGlOffscreenSurface.data,
      qt_meta_data_OpenGlOffscreenSurface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OpenGlOffscreenSurface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenGlOffscreenSurface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OpenGlOffscreenSurface.stringdata0))
        return static_cast<void*>(const_cast< OpenGlOffscreenSurface*>(this));
    return QOffscreenSurface::qt_metacast(_clname);
}

int OpenGlOffscreenSurface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOffscreenSurface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void OpenGlOffscreenSurface::frameSwapped()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void OpenGlOffscreenSurface::resized()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
