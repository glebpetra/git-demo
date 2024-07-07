QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    another_window.cpp \
    customscene.cpp \
    data.cpp \
    main.cpp \
    mainwindow.cpp \
    save_res_window.cpp

HEADERS += \
    another_window.h \
    customscene.h \
    data.h \
    mainwindow.h \
    save_res_window.h

FORMS += \
    another_window.ui \
    data.ui \
    mainwindow.ui \
    save_res_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    music.qrc

DISTFILES += \
    image/Kat_red.png \
    image/Zubovich_red.png \
    image/bita_red.png
