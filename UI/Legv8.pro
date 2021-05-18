QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CodeEditor.cpp \
    LineNumberArea.cpp \
    back_end/testConstructor.cpp \
    main.cpp \
    mainwindow.cpp \
    back_end/FloatRegister.cpp \
    back_end/Hardware.cpp \
    back_end/Instruction.cpp \
    back_end/memory.cpp \
    back_end/program.cpp \
    back_end/register.cpp \
    back_end/utils.cpp

HEADERS += \
    CodeEditor.h \
    LineNumberArea.h \
    back_end/Program.h \
    mainwindow.h \
    testConstructor.h \
    back_end/FloatRegister.h \
    back_end/Hardware.h \
    back_end/Instruction.h \
    back_end/Memory.h \
    back_end/Register.h \
    back_end/Utils.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
