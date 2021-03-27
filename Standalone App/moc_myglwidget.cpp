/****************************************************************************
** Meta object code from reading C++ file 'myglwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../IslandGeneratorWindowApp/myglwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myglwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyGLWidget_t {
    QByteArrayData data[30];
    char stringdata0[370];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGLWidget_t qt_meta_stringdata_MyGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MyGLWidget"
QT_MOC_LITERAL(1, 11, 16), // "xRotationChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "angle"
QT_MOC_LITERAL(4, 35, 16), // "yRotationChanged"
QT_MOC_LITERAL(5, 52, 16), // "zRotationChanged"
QT_MOC_LITERAL(6, 69, 12), // "setXRotation"
QT_MOC_LITERAL(7, 82, 12), // "setYRotation"
QT_MOC_LITERAL(8, 95, 12), // "setZRotation"
QT_MOC_LITERAL(9, 108, 12), // "setLandNoise"
QT_MOC_LITERAL(10, 121, 6), // "amount"
QT_MOC_LITERAL(11, 128, 7), // "setLand"
QT_MOC_LITERAL(12, 136, 12), // "setFrequency"
QT_MOC_LITERAL(13, 149, 13), // "setResolution"
QT_MOC_LITERAL(14, 163, 6), // "number"
QT_MOC_LITERAL(15, 170, 13), // "setWaterNoise"
QT_MOC_LITERAL(16, 184, 8), // "setWater"
QT_MOC_LITERAL(17, 193, 10), // "setOctaves"
QT_MOC_LITERAL(18, 204, 9), // "setScroll"
QT_MOC_LITERAL(19, 214, 12), // "setRoughness"
QT_MOC_LITERAL(20, 227, 15), // "setFlatnessFreq"
QT_MOC_LITERAL(21, 243, 15), // "setFlatnessSize"
QT_MOC_LITERAL(22, 259, 19), // "setFlatnessStrength"
QT_MOC_LITERAL(23, 279, 21), // "setRoughnessFrequency"
QT_MOC_LITERAL(24, 301, 7), // "setText"
QT_MOC_LITERAL(25, 309, 4), // "name"
QT_MOC_LITERAL(26, 314, 10), // "saveToFile"
QT_MOC_LITERAL(27, 325, 15), // "setPointsString"
QT_MOC_LITERAL(28, 341, 9), // "in_string"
QT_MOC_LITERAL(29, 351, 18) // "loadPointsFromFile"

    },
    "MyGLWidget\0xRotationChanged\0\0angle\0"
    "yRotationChanged\0zRotationChanged\0"
    "setXRotation\0setYRotation\0setZRotation\0"
    "setLandNoise\0amount\0setLand\0setFrequency\0"
    "setResolution\0number\0setWaterNoise\0"
    "setWater\0setOctaves\0setScroll\0"
    "setRoughness\0setFlatnessFreq\0"
    "setFlatnessSize\0setFlatnessStrength\0"
    "setRoughnessFrequency\0setText\0name\0"
    "saveToFile\0setPointsString\0in_string\0"
    "loadPointsFromFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  129,    2, 0x06 /* Public */,
       4,    1,  132,    2, 0x06 /* Public */,
       5,    1,  135,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  138,    2, 0x0a /* Public */,
       7,    1,  141,    2, 0x0a /* Public */,
       8,    1,  144,    2, 0x0a /* Public */,
       9,    1,  147,    2, 0x0a /* Public */,
      11,    1,  150,    2, 0x0a /* Public */,
      12,    1,  153,    2, 0x0a /* Public */,
      13,    1,  156,    2, 0x0a /* Public */,
      15,    1,  159,    2, 0x0a /* Public */,
      16,    1,  162,    2, 0x0a /* Public */,
      17,    1,  165,    2, 0x0a /* Public */,
      18,    1,  168,    2, 0x0a /* Public */,
      19,    1,  171,    2, 0x0a /* Public */,
      20,    1,  174,    2, 0x0a /* Public */,
      21,    1,  177,    2, 0x0a /* Public */,
      22,    1,  180,    2, 0x0a /* Public */,
      23,    1,  183,    2, 0x0a /* Public */,
      24,    1,  186,    2, 0x0a /* Public */,
      26,    0,  189,    2, 0x0a /* Public */,
      27,    1,  190,    2, 0x0a /* Public */,
      29,    0,  193,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void,

       0        // eod
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGLWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->zRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setXRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setYRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setZRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setLandNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setLand((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setFrequency((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setResolution((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setWaterNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setWater((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setOctaves((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setScroll((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setRoughness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setFlatnessFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setFlatnessSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->setFlatnessStrength((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->setRoughnessFrequency((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->setText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->saveToFile(); break;
        case 21: _t->setPointsString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->loadPointsFromFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::xRotationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::yRotationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::zRotationChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyGLWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QGLWidget::staticMetaObject>(),
    qt_meta_stringdata_MyGLWidget.data,
    qt_meta_data_MyGLWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLWidget.stringdata0))
        return static_cast<void*>(this);
    return QGLWidget::qt_metacast(_clname);
}

int MyGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void MyGLWidget::xRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGLWidget::yRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGLWidget::zRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
