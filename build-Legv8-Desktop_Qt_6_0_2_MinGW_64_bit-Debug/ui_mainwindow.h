/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <codeeditor.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QTextEdit *console;
    CodeEditor *codeText;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QPushButton *assembleButton;
    QPushButton *resetButton;
    QPushButton *stepButton;
    QPushButton *testButton;
    QPushButton *RunAll;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_2;
    QTableWidget *labelTable;
    QTableWidget *tableWidget;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1486, 998);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(1261, 611));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        console = new QTextEdit(groupBox_4);
        console->setObjectName(QString::fromUtf8("console"));
        console->setMaximumSize(QSize(16777215, 150));
        console->setReadOnly(true);

        gridLayout_4->addWidget(console, 2, 0, 1, 1);

        codeText = new CodeEditor(groupBox_4);
        codeText->setObjectName(QString::fromUtf8("codeText"));

        gridLayout_4->addWidget(codeText, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        assembleButton = new QPushButton(groupBox_2);
        assembleButton->setObjectName(QString::fromUtf8("assembleButton"));
        assembleButton->setMaximumSize(QSize(30, 30));
        assembleButton->setCursor(QCursor(Qt::PointingHandCursor));
        assembleButton->setStyleSheet(QString::fromUtf8("#assembleButton {\n"
"background-color: transparent;\n"
"border-image: url(:assemble.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#assembleButton:hover { \n"
"	background-color:  yellow;\n"
"	\n"
" }"));

        gridLayout_5->addWidget(assembleButton, 0, 1, 1, 1);

        resetButton = new QPushButton(groupBox_2);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setMaximumSize(QSize(30, 30));
        resetButton->setCursor(QCursor(Qt::PointingHandCursor));
        resetButton->setMouseTracking(false);
        resetButton->setTabletTracking(false);
        resetButton->setStyleSheet(QString::fromUtf8("#resetButton {\n"
"background-color: transparent;\n"
"border-image: url(:reset.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"\n"
"#resetButton:hover { \n"
"	background-color:  yellow;\n"
"	\n"
" }\n"
""));
        resetButton->setFlat(false);

        gridLayout_5->addWidget(resetButton, 0, 3, 1, 1);

        stepButton = new QPushButton(groupBox_2);
        stepButton->setObjectName(QString::fromUtf8("stepButton"));
        stepButton->setMaximumSize(QSize(30, 30));
        stepButton->setCursor(QCursor(Qt::PointingHandCursor));
        stepButton->setStyleSheet(QString::fromUtf8("#stepButton {\n"
"background-color: transparent;\n"
"border-image: url(:runStep.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#stepButton:hover { \n"
"	background-color:  yellow;\n"
" }"));

        gridLayout_5->addWidget(stepButton, 0, 2, 1, 1);

        testButton = new QPushButton(groupBox_2);
        testButton->setObjectName(QString::fromUtf8("testButton"));

        gridLayout_5->addWidget(testButton, 0, 4, 1, 1);

        RunAll = new QPushButton(groupBox_2);
        RunAll->setObjectName(QString::fromUtf8("RunAll"));
        RunAll->setMaximumSize(QSize(30, 30));
        RunAll->setCursor(QCursor(Qt::PointingHandCursor));
        RunAll->setStyleSheet(QString::fromUtf8("#RunAll {\n"
"background-color: transparent;\n"
"border-image: url(:runAll.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#RunAll:hover { \n"
"	background-color:  yellow;\n"
"	\n"
" }"));

        gridLayout_5->addWidget(RunAll, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableWidget_2 = new QTableWidget(groupBox_3);
        if (tableWidget_2->columnCount() < 16)
            tableWidget_2->setColumnCount(16);
        QFont font;
        font.setPointSize(14);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget_2->rowCount() < 15)
            tableWidget_2->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 0, __qtablewidgetitem1);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_2->sizePolicy().hasHeightForWidth());
        tableWidget_2->setSizePolicy(sizePolicy);
        tableWidget_2->setMinimumSize(QSize(351, 0));
        QFont font1;
        font1.setPointSize(9);
        tableWidget_2->setFont(font1);
        tableWidget_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget_2->setAutoScrollMargin(16);
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setShowGrid(true);
        tableWidget_2->setRowCount(15);
        tableWidget_2->setColumnCount(16);
        tableWidget_2->horizontalHeader()->setVisible(false);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(35);
        tableWidget_2->verticalHeader()->setVisible(false);
        tableWidget_2->verticalHeader()->setMinimumSectionSize(15);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_2->verticalHeader()->setHighlightSections(true);

        gridLayout_3->addWidget(tableWidget_2, 2, 1, 1, 2);

        labelTable = new QTableWidget(groupBox_3);
        if (labelTable->columnCount() < 2)
            labelTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        labelTable->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        labelTable->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        labelTable->setObjectName(QString::fromUtf8("labelTable"));
        labelTable->setMaximumSize(QSize(200, 16777215));
        labelTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        labelTable->setRowCount(0);
        labelTable->verticalHeader()->setVisible(false);

        gridLayout_3->addWidget(labelTable, 5, 0, 1, 1);

        tableWidget = new QTableWidget(groupBox_3);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QFont font2;
        font2.setPointSize(8);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        if (tableWidget->rowCount() < 32)
            tableWidget->setRowCount(32);
        QFont font3;
        font3.setBold(false);
        font3.setKerning(true);
        font3.setStyleStrategy(QFont::PreferAntialias);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font3);
        tableWidget->setItem(0, 0, __qtablewidgetitem6);
        QFont font4;
        font4.setBold(false);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font4);
        tableWidget->setItem(1, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font4);
        tableWidget->setItem(2, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font4);
        tableWidget->setItem(3, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font4);
        tableWidget->setItem(4, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font4);
        tableWidget->setItem(5, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font4);
        tableWidget->setItem(6, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font4);
        tableWidget->setItem(7, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font4);
        tableWidget->setItem(8, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font4);
        tableWidget->setItem(9, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font4);
        tableWidget->setItem(10, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font4);
        tableWidget->setItem(11, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font4);
        tableWidget->setItem(12, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font4);
        tableWidget->setItem(13, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font4);
        tableWidget->setItem(14, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font4);
        tableWidget->setItem(15, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font4);
        tableWidget->setItem(16, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font4);
        tableWidget->setItem(17, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font4);
        tableWidget->setItem(18, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font4);
        tableWidget->setItem(19, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font4);
        tableWidget->setItem(20, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font4);
        tableWidget->setItem(21, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font4);
        tableWidget->setItem(22, 0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font4);
        tableWidget->setItem(23, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font4);
        tableWidget->setItem(24, 0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setFont(font4);
        tableWidget->setItem(25, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFont(font4);
        tableWidget->setItem(26, 0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFont(font4);
        tableWidget->setItem(27, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFont(font4);
        tableWidget->setItem(28, 0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setFont(font4);
        tableWidget->setItem(29, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setFont(font4);
        tableWidget->setItem(30, 0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setFont(font4);
        tableWidget->setItem(31, 0, __qtablewidgetitem38);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMaximumSize(QSize(200, 16777215));
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(32);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget->horizontalHeader()->setDefaultSectionSize(35);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);

        gridLayout_3->addWidget(tableWidget, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 1, 1, 2);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1486, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        groupBox_4->setTitle(QString());
        codeText->setPlainText(QString());
        groupBox_2->setTitle(QString());
        assembleButton->setText(QString());
        resetButton->setText(QString());
        stepButton->setText(QString());
        testButton->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
        RunAll->setText(QString());
        groupBox_3->setTitle(QString());

        const bool __sortingEnabled = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        tableWidget_2->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem = labelTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = labelTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Values", nullptr));

        const bool __sortingEnabled1 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(0, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "X0", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(1, 0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "X1", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(2, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "X2", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(3, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "X3", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(4, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "X4", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(5, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "X5", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(6, 0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "X6", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(7, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "X7", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(8, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "X8", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(9, 0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "X9", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(10, 0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "X10", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(11, 0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "X11", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(12, 0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "X12", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(13, 0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "X13", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(14, 0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "X14", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(15, 0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "X15", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(16, 0);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "X16", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(17, 0);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "X17", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(18, 0);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "X18", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(19, 0);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "X19", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(20, 0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "X20", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(21, 0);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "X21", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(22, 0);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "X22", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(23, 0);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "X23", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(24, 0);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "X24", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(25, 0);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "X25", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(26, 0);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "X26", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(27, 0);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "X27", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(28, 0);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "SP", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(29, 0);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "FP", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(30, 0);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "LR", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(31, 0);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "XZR", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled1);

        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Label</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Memory</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Register</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
