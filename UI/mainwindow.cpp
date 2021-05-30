#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "back_end/program.cpp"
Ui::MainWindow* MainWindow::ui = new Ui::MainWindow;
bool MainWindow::checkAssemble(false);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , /*ui(new Ui::MainWindow),*/ t(), p()
{
    ui->setupUi(this);
    ui->regTable->setColumnWidth(0, 50);
    ui->regTable->setColumnWidth(1, 100);
    int rowNum = ui->memTable->rowCount();
    int colNum = ui->memTable->columnCount();
//    ui->memTable->setItem(0, 0, new QTableWidgetItem(tr("Address")));
//    for (int i = 1; i<rowNum; i++)
//        ui->memTable->setItem(i, 0, new QTableWidgetItem(tr((to_string((i-1)*16)).c_str())));
    //QObject::connect(this, SIGNAL(getOutputSignal()), this, SLOT(printOutput()));
    //ui->memTable->horizontalHeaderItem(0)->setText("Last");
 //   ui->memTable->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Address")));
    for(int i = 0; i<rowNum; i++) {
        char cstr[128];
        sprintf(cstr, "%#010x", i*16);
        string out = cstr;
        ui->memTable->setVerticalHeaderItem(i, new QTableWidgetItem(tr(out.c_str())));
    }
    for(int i = 0; i<colNum; i++) {
        ui->memTable->setHorizontalHeaderItem(i, new QTableWidgetItem(tr(to_string(i).c_str())));
    }
    ui->memTable->setStyleSheet("QHeaderView::section { background-color:#BEBEBE }");
    preNum = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getInput() {
    QString text = "";
    while (text == "")
    text = QInputDialog::getText(new QWidget(), tr("QInputDialog::getText()"),tr(""), QLineEdit::Normal);
    return text;
}

QString MainWindow::getInputWithMessage(string msg) {
    QString text = "";
    while (text == "")
    text = QInputDialog::getText(new QWidget(), tr((msg.c_str())) ,tr(""), QLineEdit::Normal);
    return text;
}

stringstream MainWindow::buffer;


void MainWindow::printOutput() {
    string s = buffer.str();
    QString qstr = QString::fromStdString(s);
    ui->console->insertPlainText(qstr);
    QTextCursor c = ui->console->textCursor();
    c.movePosition(QTextCursor::End);
    ui->console->setTextCursor(c);
    buffer.str("");
}

void MainWindow::printOutput(string msg) {
    MainWindow::buffer << msg;
    MainWindow::printOutput();
}

void MainWindow::highlightLine(QPlainTextEdit* edit, int number, int previous) {
    //QTextDocument *doc = edit->document();
    ///QTextEdit::ExtraSelection selection = doc->findBlockByLineNumber(number);

//    QTextCharFormat fmt;
//    fmt.setBackground(Qt::yellow);

//    QTextCursor cursor(edit->document());
//    cursor.setPosition(number, QTextCursor::MoveAnchor);
//    cursor.setPosition(number+1, QTextCursor::KeepAnchor);
//    cursor.setCharFormat(fmt);
    QTextCursor coursor(edit->document()->findBlockByLineNumber(number));
    QTextBlockFormat frmt = coursor.blockFormat();
    frmt.setBackground(QBrush(Qt::yellow));
    coursor.setBlockFormat(frmt);


    QTextCursor pre_coursor(edit->document()->findBlockByLineNumber(previous));
    QTextBlockFormat pre_frmt = pre_coursor.blockFormat();
    pre_frmt.setBackground(QBrush(Qt::white));
    pre_coursor.setBlockFormat(pre_frmt);
}

void MainWindow::on_RunAll_clicked()
{
 //  ui->groupBox_3->
    //ui->tableWidget->setItem(0, 0, new QTableWidgetItem(tr("123")));
  //  ui->tableWidget->setItem(0, 1, new QTableWidgetItem(tr("456")));
//    for(int i = 1; i<4; i++)
//       // ui->tableWidget->setItem(i, 0, new QTableWidgetItem(tr((to_string(i*3)).c_str())));
//       ui->tableWidget->item(i,0)->setText(((to_string(i*3)).c_str()));
    p.setSource((ui->codeText->toPlainText()).toStdString());
    if (p.assembleSuccessfully())
        printOutput("-----Assembled succesfully-----\n");
    else
        printOutput(); // Print error messages from buffer
    p.runAll();
    MainWindow::updateRegisterTable();
    MainWindow::updateMemoryTable();
}



//void MainWindow::on_testButton_clicked()
//{
//    //    QLineEdit* a = new QLineEdit(" ",this);
//    //    a->showFullScreen();
//    //    ui->testButton->setDisabled(true);
//    //    for (int i = 0; i<10; i++) {
//    //    if(SIGNAL(a->editingFinished())) {
//    //      //  delete a;
//    //        ui->console->insertPlainText("a->displayText()");
//    //    }
//    //        ui->console->insertPlainText((to_string(i)).c_str());
//    //    }
//        //a->show();
////    for (int i = 0; i<10; i++) {
////    QString input = t.testGetInput();
////    ui->console->insertPlainText(input);
////    }
//    //t.testGetInput();
//   // ui->console->insertPlainText(t.testGetInput());
////        QString text = "";
////        while (text == "")
////        text = QInputDialog::getText(this, tr("QInputDialog::getText()"),tr(""), QLineEdit::Normal);
////        ui->console->insertPlainText(text);
//}


void MainWindow::on_resetButton_clicked()
{
    if(!checkAssemble) return;
    this->highlightLine(ui->codeText, -1, p.getLineNumber(p.getPC()));
    checkAssemble = false;
    p.reset();
    MainWindow::updateRegisterTable();
    MainWindow::updateMemoryTable();
    ui->console->clear();
    ui->labelTable->clearContents();
    ui->labelTable->setRowCount(0);
}

void MainWindow::on_stepButton_clicked()
{
    if(!checkAssemble) MainWindow::on_assembleButton_clicked();
    int previous_instruction = p.getLineNumber(p.getPC());
    if(!p.executeSuccessfully(-1))
    {
        printOutput(); // display error messages from buffer
        return;
    }

    printOutput(" | ");

  //  int previous_instruction = p.getLineNumber(p.getPC());
//    printOutput(to_string(previous_instruction));
//    printOutput(to_string(p.getLineNumber(p.getPC())));
    highlightLine(ui->codeText, p.getLineNumber(p.getPC()), previous_instruction);
    MainWindow::updateRegisterTable();
    MainWindow::updateMemoryTable();
//    this->highlightLine(ui->codeText, p.getPC(), previous_instruction);
//    ui->console->insertPlainText(QString::fromStdString(to_string(p.getPC())));
//    ui->console->insertPlainText(QString::fromStdString(" "));
//    ui->console->insertPlainText(QString::fromStdString(to_string(p.getLineNumber(p.getPC()))));
}
void MainWindow::on_assembleButton_clicked()
{
    if(checkAssemble) {return;}
    p.reset();
    printOutput("Assembling...\n");
    if((ui->codeText->toPlainText()).toStdString() == "") {
        printOutput("Empty File!!!!!!!\n");
        return;
   }
   p.setSource((ui->codeText->toPlainText()).toStdString());

    if(!p.assembleSuccessfully())
    {
        printOutput(); // print error messages from buffer
        return;
    }

    printOutput("-------Assembled succesfully-------\n");
    checkAssemble = true;
    MainWindow::updateRegisterTable();
    this->highlightLine(ui->codeText, p.getLineNumber(p.getPC()), 0);
    MainWindow::updateRegisterTable();
    MainWindow::updateMemoryTable();
    MainWindow::updateLabelTable();

}

void MainWindow::updateRegisterTable() {
    for(int i = 0; i<32; i++)
        ui->regTable->setItem(i, 1, new QTableWidgetItem(tr((to_string(p.getRegisterValue(i))).c_str())));
       //ui->tableWidget->item(i,0)->setText(((to_string(i)).c_str()));
}

void MainWindow::updateMemoryTable() {
    int rowNum = ui->memTable->rowCount();
    int colNum = ui->memTable->columnCount();
    //int memNum = rowNum*colNum;
    for(int i = 0; i< rowNum; i++)
        for(int j = 0; j< colNum; j++)
            ui->memTable->setItem(i, j, new QTableWidgetItem(tr((to_string(p.getMemoryValue((i)*colNum + j))).c_str())));
}

void MainWindow::updateLabelTable() {
//   map<string, int> mapLabel = p.getLabel();
   map<string, int> mapData = p.getData();
//   int rowNum1 = mapLabel.size();
   int rowNum2 = mapData.size();
//   int rowNum = rowNum1 + rowNum2;
   ui->labelTable->setRowCount(rowNum2);
   int i = 0;
//   for (std::map<string,int>::reverse_iterator rit=mapLabel.rbegin(); rit!=mapLabel.rend(); ++rit, ++i) {
//       ui->labelTable->setItem(i, 0, new QTableWidgetItem(tr((rit->first).c_str())));
//       ui->labelTable->setItem(i, 1, new QTableWidgetItem(tr((to_string(rit->second)).c_str())));
//   }
   for (std::map<string,int>::reverse_iterator rit=mapData.rbegin(); rit!=mapData.rend(); ++rit, ++i) {
       ui->labelTable->setItem(i, 0, new QTableWidgetItem(tr((rit->first).c_str())));
       ui->labelTable->setItem(i, 1, new QTableWidgetItem(tr((to_string(rit->second)).c_str())));
   }
}

void MainWindow::on_textEdit_textChanged() {
//    if(ui->textEdit->toPl
    QString textEdit = ui->textEdit->toPlainText();
//    if(textEdit.contains("\n")) {
//        textEdit.clear();
//        ui->textEdit->clear();
//    }
    ui->memTable->item(preNum/16, preNum%16)->setBackground(Qt::white);
    if(textEdit.isEmpty()) return;
    int num = textEdit.toInt();
    if(num >= 0) {
        preNum = num;
        ui->memTable->item(num/16, num%16)->setBackground(Qt::gray);
    }
}

