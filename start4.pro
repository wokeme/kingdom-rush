QT       += core gui multimedia designer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


QT += uitools



CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common.cpp \
    enemy.cpp \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    model.cpp \
    mybottom.cpp \
    tower.cpp \
    viewmodel.cpp

HEADERS += \
    common.h \
    enemy.h \
    gamewindow.h \
    mainwindow.h \
    map.h \
    model.h \
    mybottom.h \
    tower.h \
    viewmodel.h

FORMS += \
    gamewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourse.qrc
