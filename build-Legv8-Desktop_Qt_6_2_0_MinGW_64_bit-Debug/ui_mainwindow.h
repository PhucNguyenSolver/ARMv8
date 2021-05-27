/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
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
    QPushButton *RunAll;
    QPushButton *stepButton;
    QPushButton *resetButton;
    QPushButton *testButton;
    QPushButton *assembleButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QTableWidget *memTable;
    QTableWidget *labelTable;
    QLabel *label_3;
    QTableWidget *regTable;
    QLabel *label;
    QLabel *label_2;
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
        QFont font;
        font.setPointSize(12);
        codeText->setFont(font);

        gridLayout_4->addWidget(codeText, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        RunAll = new QPushButton(groupBox_2);
        RunAll->setObjectName(QString::fromUtf8("RunAll"));
        RunAll->setMaximumSize(QSize(50, 30));
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

        stepButton = new QPushButton(groupBox_2);
        stepButton->setObjectName(QString::fromUtf8("stepButton"));
        stepButton->setMaximumSize(QSize(50, 30));
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

        resetButton = new QPushButton(groupBox_2);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setMaximumSize(QSize(50, 30));
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

        testButton = new QPushButton(groupBox_2);
        testButton->setObjectName(QString::fromUtf8("testButton"));
        testButton->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(testButton, 0, 4, 1, 1);

        assembleButton = new QPushButton(groupBox_2);
        assembleButton->setObjectName(QString::fromUtf8("assembleButton"));
        assembleButton->setMaximumSize(QSize(50, 30));
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


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        memTable = new QTableWidget(groupBox_3);
        if (memTable->columnCount() < 16)
            memTable->setColumnCount(16);
        if (memTable->rowCount() < 60)
            memTable->setRowCount(60);
        memTable->setObjectName(QString::fromUtf8("memTable"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(memTable->sizePolicy().hasHeightForWidth());
        memTable->setSizePolicy(sizePolicy);
        memTable->setMinimumSize(QSize(351, 0));
        QFont font1;
        font1.setPointSize(9);
        memTable->setFont(font1);
        memTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        memTable->setAutoScrollMargin(16);
        memTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        memTable->setShowGrid(true);
        memTable->setRowCount(60);
        memTable->setColumnCount(16);
        memTable->horizontalHeader()->setVisible(true);
        memTable->horizontalHeader()->setMinimumSectionSize(10);
        memTable->horizontalHeader()->setDefaultSectionSize(35);
        memTable->verticalHeader()->setVisible(true);
        memTable->verticalHeader()->setMinimumSectionSize(15);
        memTable->verticalHeader()->setDefaultSectionSize(30);
        memTable->verticalHeader()->setHighlightSections(false);
        memTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        gridLayout_3->addWidget(memTable, 2, 1, 1, 2);

        labelTable = new QTableWidget(groupBox_3);
        if (labelTable->columnCount() < 2)
            labelTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        labelTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        labelTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        labelTable->setObjectName(QString::fromUtf8("labelTable"));
        labelTable->setMinimumSize(QSize(200, 150));
        labelTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        labelTable->setRowCount(0);
        labelTable->horizontalHeader()->setMinimumSectionSize(70);
        labelTable->horizontalHeader()->setDefaultSectionSize(200);
        labelTable->verticalHeader()->setVisible(false);

        gridLayout_3->addWidget(labelTable, 4, 0, 2, 2);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        regTable = new QTableWidget(groupBox_3);
        if (regTable->columnCount() < 2)
            regTable->setColumnCount(2);
        QFont font2;
        font2.setPointSize(8);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        regTable->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        regTable->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        if (regTable->rowCount() < 32)
            regTable->setRowCount(32);
        QFont font3;
        font3.setBold(false);
        font3.setKerning(true);
        font3.setStyleStrategy(QFont::PreferAntialias);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font3);
        regTable->setItem(0, 0, __qtablewidgetitem4);
        QFont font4;
        font4.setBold(false);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font4);
        regTable->setItem(1, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font4);
        regTable->setItem(2, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        regTable->setItem(2, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font4);
        regTable->setItem(3, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font4);
        regTable->setItem(4, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font4);
        regTable->setItem(5, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font4);
        regTable->setItem(6, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font4);
        regTable->setItem(7, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font4);
        regTable->setItem(8, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font4);
        regTable->setItem(9, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font4);
        regTable->setItem(10, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font4);
        regTable->setItem(11, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font4);
        regTable->setItem(12, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font4);
        regTable->setItem(13, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font4);
        regTable->setItem(14, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font4);
        regTable->setItem(15, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font4);
        regTable->setItem(16, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font4);
        regTable->setItem(17, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font4);
        regTable->setItem(18, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font4);
        regTable->setItem(19, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font4);
        regTable->setItem(20, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font4);
        regTable->setItem(21, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font4);
        regTable->setItem(22, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font4);
        regTable->setItem(23, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font4);
        regTable->setItem(24, 0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font4);
        regTable->setItem(25, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font4);
        regTable->setItem(26, 0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setFont(font4);
        regTable->setItem(27, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFont(font4);
        regTable->setItem(28, 0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFont(font4);
        regTable->setItem(29, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFont(font4);
        regTable->setItem(30, 0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setFont(font4);
        regTable->setItem(31, 0, __qtablewidgetitem36);
        regTable->setObjectName(QString::fromUtf8("regTable"));
        regTable->setMaximumSize(QSize(200, 16777215));
        regTable->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        regTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        regTable->setShowGrid(true);
        regTable->setGridStyle(Qt::SolidLine);
        regTable->setWordWrap(true);
        regTable->setCornerButtonEnabled(true);
        regTable->setRowCount(32);
        regTable->horizontalHeader()->setVisible(false);
        regTable->horizontalHeader()->setMinimumSectionSize(10);
        regTable->horizontalHeader()->setDefaultSectionSize(35);
        regTable->verticalHeader()->setVisible(false);
        regTable->verticalHeader()->setDefaultSectionSize(30);

        gridLayout_3->addWidget(regTable, 2, 0, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1486, 26));
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
#if QT_CONFIG(tooltip)
        RunAll->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Run-All</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        RunAll->setText(QString());
#if QT_CONFIG(tooltip)
        stepButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Run-Step</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        stepButton->setText(QString());
#if QT_CONFIG(tooltip)
        resetButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Reset</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        resetButton->setText(QString());
        testButton->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
#if QT_CONFIG(tooltip)
        assembleButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">ASSEMBLE</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        assembleButton->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        assembleButton->setText(QString());
        groupBox_3->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = labelTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = labelTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Data</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = regTable->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = regTable->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Values", nullptr));

        const bool __sortingEnabled = regTable->isSortingEnabled();
        regTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = regTable->item(0, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "X0", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = regTable->item(1, 0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "X1", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = regTable->item(2, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "X2", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = regTable->item(3, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "X3", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = regTable->item(4, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "X4", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = regTable->item(5, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "X5", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = regTable->item(6, 0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "X6", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = regTable->item(7, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "X7", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = regTable->item(8, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "X8", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = regTable->item(9, 0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "X9", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = regTable->item(10, 0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "X10", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = regTable->item(11, 0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "X11", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = regTable->item(12, 0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "X12", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = regTable->item(13, 0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "X13", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = regTable->item(14, 0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "X14", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = regTable->item(15, 0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "X15", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = regTable->item(16, 0);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "X16", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = regTable->item(17, 0);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "X17", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = regTable->item(18, 0);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "X18", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = regTable->item(19, 0);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "X19", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = regTable->item(20, 0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "X20", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = regTable->item(21, 0);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "X21", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = regTable->item(22, 0);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "X22", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = regTable->item(23, 0);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "X23", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = regTable->item(24, 0);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "X24", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = regTable->item(25, 0);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "X25", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = regTable->item(26, 0);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "X26", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = regTable->item(27, 0);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "X27", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = regTable->item(28, 0);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "SP", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = regTable->item(29, 0);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "FP", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = regTable->item(30, 0);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "LR", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = regTable->item(31, 0);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "XZR", nullptr));
        regTable->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Register</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Memory</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
