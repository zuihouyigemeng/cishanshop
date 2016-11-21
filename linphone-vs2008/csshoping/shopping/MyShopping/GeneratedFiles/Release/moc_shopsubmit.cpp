/****************************************************************************
** Meta object code from reading C++ file 'shopsubmit.h'
**
** Created: Tue Jun 23 17:10:17 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../shopsubmit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shopsubmit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_shopsubmit[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      35,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      88,   11,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,
     140,   11,   11,   11, 0x08,
     163,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     216,   11,   11,   11, 0x08,
     241,   11,   11,   11, 0x08,
     267,   11,   11,   11, 0x08,
     293,   11,   11,   11, 0x08,
     318,   11,   11,   11, 0x08,
     343,   11,   11,   11, 0x08,
     370,   11,   11,   11, 0x08,
     381,   11,   11,   11, 0x08,
     407,   11,   11,   11, 0x08,
     431,   11,   11,   11, 0x08,
     458,   11,   11,   11, 0x08,
     488,  483,   11,   11, 0x08,
     520,  483,   11,   11, 0x08,
     554,  483,   11,   11, 0x08,
     596,  590,   11,   11, 0x08,
     627,  590,   11,   11, 0x08,
     661,  590,   11,   11, 0x08,
     694,  590,   11,   11, 0x08,
     729,  590,   11,   11, 0x08,
     764,  590,   11,   11, 0x08,
     796,  590,   11,   11, 0x08,
     829,  590,   11,   11, 0x08,
     865,   11,   11,   11, 0x08,
     904,  896,   11,   11, 0x08,
     931,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_shopsubmit[] = {
    "shopsubmit\0\0on_manageBtn_clicked()\0"
    "on_addProductBtn_clicked()\0"
    "on_xgProductBtn_clicked()\0"
    "on_classOkBtn_clicked()\0"
    "on_goodsInfoOkBtn_clicked()\0"
    "on_bigpicBtn_clicked()\0on_smallpicBtn_clicked()\0"
    "on_productModeBtn_clicked()\0"
    "on_goodsDelBtn_clicked()\0"
    "on_requireShBtn_clicked()\0"
    "on_goodsBackBtn_clicked()\0"
    "on_spUploadBtn_clicked()\0"
    "on_bigpicBtn_2_clicked()\0"
    "on_smallpicBtn_2_clicked()\0setJiShi()\0"
    "on_shProductBtn_clicked()\0"
    "on_xgClassBtn_clicked()\0"
    "on_addClassOkBtn_clicked()\0"
    "on_classDelBtn_clicked()\0item\0"
    "getClassItem(QTableWidgetItem*)\0"
    "getProductItem(QTableWidgetItem*)\0"
    "getShProductItem(QTableWidgetItem*)\0"
    "reply\0replyClassConn(QNetworkReply*)\0"
    "replyClassDelConn(QNetworkReply*)\0"
    "replyProductConn(QNetworkReply*)\0"
    "replyshProductConn(QNetworkReply*)\0"
    "replyRequireShConn(QNetworkReply*)\0"
    "replyUploadConn(QNetworkReply*)\0"
    "replyProductMode(QNetworkReply*)\0"
    "replyProductDelConn(QNetworkReply*)\0"
    "uploadFinished(QNetworkReply*)\0context\0"
    "shBoxValueChanged(QString)\0initClassList()\0"
};

const QMetaObject shopsubmit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_shopsubmit,
      qt_meta_data_shopsubmit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &shopsubmit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *shopsubmit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *shopsubmit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_shopsubmit))
        return static_cast<void*>(const_cast< shopsubmit*>(this));
    return QWidget::qt_metacast(_clname);
}

int shopsubmit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_manageBtn_clicked(); break;
        case 1: on_addProductBtn_clicked(); break;
        case 2: on_xgProductBtn_clicked(); break;
        case 3: on_classOkBtn_clicked(); break;
        case 4: on_goodsInfoOkBtn_clicked(); break;
        case 5: on_bigpicBtn_clicked(); break;
        case 6: on_smallpicBtn_clicked(); break;
        case 7: on_productModeBtn_clicked(); break;
        case 8: on_goodsDelBtn_clicked(); break;
        case 9: on_requireShBtn_clicked(); break;
        case 10: on_goodsBackBtn_clicked(); break;
        case 11: on_spUploadBtn_clicked(); break;
        case 12: on_bigpicBtn_2_clicked(); break;
        case 13: on_smallpicBtn_2_clicked(); break;
        case 14: setJiShi(); break;
        case 15: on_shProductBtn_clicked(); break;
        case 16: on_xgClassBtn_clicked(); break;
        case 17: on_addClassOkBtn_clicked(); break;
        case 18: on_classDelBtn_clicked(); break;
        case 19: getClassItem((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 20: getProductItem((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 21: getShProductItem((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 22: replyClassConn((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 23: replyClassDelConn((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 24: replyProductConn((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 25: replyshProductConn((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 26: replyRequireShConn((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 27: replyUploadConn((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 28: replyProductMode((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 29: replyProductDelConn((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 30: uploadFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 31: shBoxValueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: initClassList(); break;
        default: ;
        }
        _id -= 33;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
