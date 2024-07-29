QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bahar.cpp \
    Battle.cpp \
    Card.cpp \
    CombatCard.cpp \
    Deck.cpp \
    Game.cpp \
    Map.cpp \
    Matarsak.cpp \
    Player.cpp \
    Province.cpp \
    RishSefid.cpp \
    ShahDokht.cpp \
    SpecialCard.cpp \
    TablZan.cpp \
    Zemestan.cpp \
    gamewindow.cpp \
    initplayerswindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Bahar.h \
    Battle.h \
    Card.h \
    CombatCard.h \
    Deck.h \
    Game.h \
    Map.h \
    Matarsak.h \
    Player.h \
    Province.h \
    RishSefid.h \
    ShahDokht.h \
    SpecialCard.h \
    TablZan.h \
    Zemestan.h \
    gamewindow.h \
    initplayerswindow.h \
    mainwindow.h

FORMS += \
    gamewindow.ui \
    initplayerswindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    assets/background.jpg \
    background.jpg

RESOURCES += \
    mainBackground.qrc
