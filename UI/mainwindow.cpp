#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "back_end/program.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), t(), p()
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getInput() {
    QString text = "";
    while (text == "")
    text = QInputDialog::getText(new MainWindow(), tr("QInputDialog::getText()"),tr(""), QLineEdit::Normal);
    return text;
}

stringstream MainWindow::buffer;



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
    t.testOutput();
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
