#include "testConstructor.h"
Test::Test(): id(0) {}
QString Test::testGetInput() {
    return MainWindow::getInput();
}
