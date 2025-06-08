/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *pagesListWidget;
    QListWidget *spellsListWidget;
    QTextEdit *spellDetailTextEdit;
    QPushButton *loadButton;
    QPushButton *AddSpellB;
    QPushButton *AddPageButton;
    QPushButton *SaveGrimoireButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        pagesListWidget = new QListWidget(centralwidget);
        pagesListWidget->setObjectName("pagesListWidget");

        horizontalLayout->addWidget(pagesListWidget);

        spellsListWidget = new QListWidget(centralwidget);
        spellsListWidget->setObjectName("spellsListWidget");

        horizontalLayout->addWidget(spellsListWidget);

        spellDetailTextEdit = new QTextEdit(centralwidget);
        spellDetailTextEdit->setObjectName("spellDetailTextEdit");
        spellDetailTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(spellDetailTextEdit);

        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Mincho")});
        font.setBold(true);
        loadButton->setFont(font);

        horizontalLayout->addWidget(loadButton);

        AddSpellB = new QPushButton(centralwidget);
        AddSpellB->setObjectName("AddSpellB");
        AddSpellB->setFont(font);

        horizontalLayout->addWidget(AddSpellB);

        AddPageButton = new QPushButton(centralwidget);
        AddPageButton->setObjectName("AddPageButton");
        AddPageButton->setFont(font);

        horizontalLayout->addWidget(AddPageButton);

        SaveGrimoireButton = new QPushButton(centralwidget);
        SaveGrimoireButton->setObjectName("SaveGrimoireButton");
        SaveGrimoireButton->setFont(font);

        horizontalLayout->addWidget(SaveGrimoireButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        AddSpellB->setText(QCoreApplication::translate("MainWindow", "Add Spell", nullptr));
        AddPageButton->setText(QCoreApplication::translate("MainWindow", "Add Page", nullptr));
        SaveGrimoireButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
