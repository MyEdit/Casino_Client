/****************************************************************************
** Meta object code from reading C++ file 'window_admin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/window_admin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_admin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_Admin_t {
    QByteArrayData data[8];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_Admin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_Admin_t qt_meta_stringdata_Window_Admin = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Window_Admin"
QT_MOC_LITERAL(1, 13, 21), // "on_buttonExit_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 31), // "on_buttonExistingTables_clicked"
QT_MOC_LITERAL(4, 68, 25), // "on_buttonAllUsers_clicked"
QT_MOC_LITERAL(5, 94, 22), // "on_buttonStaff_clicked"
QT_MOC_LITERAL(6, 117, 26), // "on_buttonBlackList_clicked"
QT_MOC_LITERAL(7, 144, 33) // "on_buttonLoanApplocations_cli..."

    },
    "Window_Admin\0on_buttonExit_clicked\0\0"
    "on_buttonExistingTables_clicked\0"
    "on_buttonAllUsers_clicked\0"
    "on_buttonStaff_clicked\0"
    "on_buttonBlackList_clicked\0"
    "on_buttonLoanApplocations_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window_Admin[] = {

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
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Window_Admin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Window_Admin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_buttonExit_clicked(); break;
        case 1: _t->on_buttonExistingTables_clicked(); break;
        case 2: _t->on_buttonAllUsers_clicked(); break;
        case 3: _t->on_buttonStaff_clicked(); break;
        case 4: _t->on_buttonBlackList_clicked(); break;
        case 5: _t->on_buttonLoanApplocations_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Window_Admin::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Window_Admin.data,
    qt_meta_data_Window_Admin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Window_Admin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window_Admin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window_Admin.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Window_Admin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
