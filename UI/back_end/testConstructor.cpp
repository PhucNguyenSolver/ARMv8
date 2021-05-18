#include "testConstructor.h"
Test::Test(): id(0) {}
QString Test::testGetInput() {
    return MainWindow::getInput();
}

void Test::testOutput() {
    string s = "abc\ndd e f\n123";
    MainWindow::buffer << s;
}
