#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <iostream>
#include <string.h>
#include <string>
#include <QWidget>
#include <QPlainTextEdit>
#include <QPainter>
#include <QTextBlock>
#include <QLineEdit>
#include "CodeEditor.h"
#include <QLayout>
#include <QString>
#include "LineNumberArea.h"
//<<<<<<< HEAD
#include <QInputDialog>
//=======
#include "back_end/Program.h"
//>>>>>>> ad5a9568f681aa045900787ac5ba772d64298af2
#include "testConstructor.h"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QString getInput();

private slots:

    void on_RunAll_clicked();
    void on_testButton_clicked();

private:
    Ui::MainWindow *ui;
    Test t;
    Program p;
};
#endif // MAINWINDOW_H
