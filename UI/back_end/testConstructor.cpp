#include "testConstructor.h"
Test::Test(): id(0) {}
QString Test::testGetInput() {
   // MainWindow::buffer <<  (MainWindow::getInput()).toLocal8Bit().constData();
  //  MainWindow::printOutput();
//    MainWindow::buffer.str("");
//    MainWindow::buffer << "run here\n";
//    MainWindow::printOutput();
    return MainWindow::getInput();
}

void Test::testOutput() {
    string s = "abc\ndd e f\n123";
    MainWindow::buffer << s;
    MainWindow::printOutput();
}
