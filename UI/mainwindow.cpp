#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "back_end/program.cpp"
Ui::MainWindow* MainWindow::ui = new Ui::MainWindow;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , /*ui(new Ui::MainWindow),*/ t(), p()
{
    ui->setupUi(this);
    //QObject::connect(this, SIGNAL(getOutputSignal()), this, SLOT(printOutput()));
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

stringstream MainWindow::buffer;


void MainWindow::printOutput() {
    string s = buffer.str();
    QString qstr = QString::fromStdString(s);
    ui->console->insertPlainText(qstr);
    buffer.str("");
}

void MainWindow::highlightLine(QPlainTextEdit* edit, int number) {
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
    string s = "false";
   if(p.assembleSuccessfully()) s = "true";
    QString qstr = QString::fromStdString(s);
    ui->console->insertPlainText(qstr);
    p.runAll();
    //MainWindow::updateRegisterTable();
}



void MainWindow::on_testButton_clicked()
{
    //    QLineEdit* a = new QLineEdit(" ",this);
    //    a->showFullScreen();
    //    ui->testButton->setDisabled(true);
    //    for (int i = 0; i<10; i++) {
    //    if(SIGNAL(a->editingFinished())) {
    //      //  delete a;
    //        ui->console->insertPlainText("a->displayText()");
    //    }
    //        ui->console->insertPlainText((to_string(i)).c_str());
    //    }
        //a->show();
//    for (int i = 0; i<10; i++) {
//    QString input = t.testGetInput();
//    ui->console->insertPlainText(input);
//    }
    //t.testGetInput();
   // ui->console->insertPlainText(t.testGetInput());
//        QString text = "";
//        while (text == "")
//        text = QInputDialog::getText(this, tr("QInputDialog::getText()"),tr(""), QLineEdit::Normal);
//        ui->console->insertPlainText(text);
}


void MainWindow::on_resetButton_clicked()
{
    p.reset();
    MainWindow::updateRegisterTable();
}

void MainWindow::on_stepButton_clicked()
{
    string s = "false\n";
   if(p.executeSuccessfully(p.getPC())) s = "true\n";
    QString qstr = QString::fromStdString(s);
    ui->console->insertPlainText(qstr);
    MainWindow::updateRegisterTable();
    this->highlightLine(ui->codeText, p.getPC());
}

void MainWindow::on_assembleButton_clicked()
{
    p.setSource((ui->codeText->toPlainText()).toStdString());
    string s = "false\n";
   if(p.assembleSuccessfully()) s = "true\n";
    QString qstr = QString::fromStdString(s);
    ui->console->insertPlainText(qstr);
}

void MainWindow::updateRegisterTable() {
    for(int i = 0; i<32; i++)
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(tr((to_string(p.getRegisterValue(i))).c_str())));
       //ui->tableWidget->item(i,0)->setText(((to_string(i)).c_str()));
}
