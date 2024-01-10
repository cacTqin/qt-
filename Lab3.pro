QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    departview.cpp \
    doctoreditview.cpp \
    doctorview.cpp \
    idatabase.cpp \
    loginview.cpp \
    main.cpp \
    masterview.cpp \
    medicineseditview.cpp \
    medicinesview.cpp \
    patienteditview.cpp \
    patientview.cpp \
    welcomeview.cpp

HEADERS += \
    departview.h \
    doctoreditview.h \
    doctorview.h \
    idatabase.h \
    loginview.h \
    masterview.h \
    medicineseditview.h \
    medicinesview.h \
    patienteditview.h \
    patientview.h \
    welcomeview.h

FORMS += \
    departview.ui \
    doctoreditview.ui \
    doctorview.ui \
    loginview.ui \
    masterview.ui \
    medicineseditview.ui \
    medicinesview.ui \
    patienteditview.ui \
    patientview.ui \
    welcomeview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
