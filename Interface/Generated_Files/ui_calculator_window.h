/********************************************************************************
** Form generated from reading UI file 'calculator_window.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_WINDOW_H
#define UI_CALCULATOR_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calculator_window
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_3;
    QPushButton *pushButton_0;
    QPushButton *pushButton_decimal;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_multiplication;
    QPushButton *pushButton_division;
    QPushButton *pushButton_equals;
    QTextEdit *textEdit_Equation;
    QTextEdit *textEdit_Output;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_leftParentheses;
    QPushButton *pushButton_rightParentheses;
    QPushButton *pushButton_power;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *calculator_window)
    {
        if (calculator_window->objectName().isEmpty())
            calculator_window->setObjectName(QString::fromUtf8("calculator_window"));
        calculator_window->resize(494, 604);
        centralwidget = new QWidget(calculator_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 120, 71, 71));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        pushButton_7->setFont(font);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(120, 120, 71, 71));
        pushButton_8->setBaseSize(QSize(60, 60));
        pushButton_8->setFont(font);
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(210, 120, 71, 71));
        pushButton_9->setBaseSize(QSize(60, 60));
        pushButton_9->setFont(font);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(120, 210, 71, 71));
        pushButton_5->setBaseSize(QSize(60, 60));
        pushButton_5->setFont(font);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 210, 71, 71));
        pushButton_4->setFont(font);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(210, 210, 71, 71));
        pushButton_6->setBaseSize(QSize(60, 60));
        pushButton_6->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 300, 71, 71));
        pushButton_2->setBaseSize(QSize(60, 60));
        pushButton_2->setFont(font);
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(30, 300, 71, 71));
        pushButton_1->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 300, 71, 71));
        pushButton_3->setBaseSize(QSize(60, 60));
        pushButton_3->setFont(font);
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(120, 390, 71, 71));
        pushButton_0->setBaseSize(QSize(60, 60));
        pushButton_0->setFont(font);
        pushButton_decimal = new QPushButton(centralwidget);
        pushButton_decimal->setObjectName(QString::fromUtf8("pushButton_decimal"));
        pushButton_decimal->setGeometry(QRect(210, 390, 71, 71));
        pushButton_decimal->setBaseSize(QSize(60, 60));
        pushButton_decimal->setFont(font);
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(300, 120, 71, 71));
        pushButton_plus->setBaseSize(QSize(60, 60));
        pushButton_plus->setFont(font);
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(300, 210, 71, 71));
        pushButton_minus->setBaseSize(QSize(60, 60));
        pushButton_minus->setFont(font);
        pushButton_multiplication = new QPushButton(centralwidget);
        pushButton_multiplication->setObjectName(QString::fromUtf8("pushButton_multiplication"));
        pushButton_multiplication->setGeometry(QRect(300, 300, 71, 71));
        pushButton_multiplication->setBaseSize(QSize(60, 60));
        pushButton_multiplication->setFont(font);
        pushButton_division = new QPushButton(centralwidget);
        pushButton_division->setObjectName(QString::fromUtf8("pushButton_division"));
        pushButton_division->setGeometry(QRect(300, 390, 71, 71));
        pushButton_division->setBaseSize(QSize(60, 60));
        pushButton_division->setFont(font);
        pushButton_equals = new QPushButton(centralwidget);
        pushButton_equals->setObjectName(QString::fromUtf8("pushButton_equals"));
        pushButton_equals->setGeometry(QRect(390, 390, 71, 71));
        pushButton_equals->setFont(font);
        textEdit_Equation = new QTextEdit(centralwidget);
        textEdit_Equation->setObjectName(QString::fromUtf8("textEdit_Equation"));
        textEdit_Equation->setGeometry(QRect(30, 30, 431, 71));
        QFont font1;
        font1.setPointSize(12);
        textEdit_Equation->setFont(font1);
        textEdit_Equation->setLayoutDirection(Qt::LeftToRight);
        textEdit_Equation->setInputMethodHints(Qt::ImhNone);
        textEdit_Output = new QTextEdit(centralwidget);
        textEdit_Output->setObjectName(QString::fromUtf8("textEdit_Output"));
        textEdit_Output->setGeometry(QRect(30, 480, 431, 71));
        textEdit_Output->setFont(font1);
        textEdit_Output->setAcceptDrops(false);
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(30, 390, 71, 71));
        pushButton_clear->setFont(font);
        pushButton_leftParentheses = new QPushButton(centralwidget);
        pushButton_leftParentheses->setObjectName(QString::fromUtf8("pushButton_leftParentheses"));
        pushButton_leftParentheses->setGeometry(QRect(390, 120, 71, 71));
        pushButton_leftParentheses->setFont(font);
        pushButton_rightParentheses = new QPushButton(centralwidget);
        pushButton_rightParentheses->setObjectName(QString::fromUtf8("pushButton_rightParentheses"));
        pushButton_rightParentheses->setGeometry(QRect(390, 210, 71, 71));
        pushButton_rightParentheses->setFont(font);
        pushButton_power = new QPushButton(centralwidget);
        pushButton_power->setObjectName(QString::fromUtf8("pushButton_power"));
        pushButton_power->setGeometry(QRect(390, 300, 71, 71));
        pushButton_power->setFont(font);
        calculator_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(calculator_window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 494, 21));
        calculator_window->setMenuBar(menubar);
        statusbar = new QStatusBar(calculator_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        calculator_window->setStatusBar(statusbar);

        retranslateUi(calculator_window);

        QMetaObject::connectSlotsByName(calculator_window);
    } // setupUi

    void retranslateUi(QMainWindow *calculator_window)
    {
        calculator_window->setWindowTitle(QCoreApplication::translate("calculator_window", "Calculator", nullptr));
        pushButton_7->setText(QCoreApplication::translate("calculator_window", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("calculator_window", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("calculator_window", "9", nullptr));
        pushButton_5->setText(QCoreApplication::translate("calculator_window", "5", nullptr));
        pushButton_4->setText(QCoreApplication::translate("calculator_window", "4", nullptr));
        pushButton_6->setText(QCoreApplication::translate("calculator_window", "6", nullptr));
        pushButton_2->setText(QCoreApplication::translate("calculator_window", "2", nullptr));
        pushButton_1->setText(QCoreApplication::translate("calculator_window", "1", nullptr));
        pushButton_3->setText(QCoreApplication::translate("calculator_window", "3", nullptr));
        pushButton_0->setText(QCoreApplication::translate("calculator_window", "0", nullptr));
        pushButton_decimal->setText(QCoreApplication::translate("calculator_window", ".", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("calculator_window", "+", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("calculator_window", "-", nullptr));
        pushButton_multiplication->setText(QCoreApplication::translate("calculator_window", "*", nullptr));
        pushButton_division->setText(QCoreApplication::translate("calculator_window", "/", nullptr));
        pushButton_equals->setText(QCoreApplication::translate("calculator_window", "=", nullptr));
        textEdit_Equation->setHtml(QCoreApplication::translate("calculator_window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p></body></html>", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("calculator_window", "Clear", nullptr));
        pushButton_leftParentheses->setText(QCoreApplication::translate("calculator_window", "(", nullptr));
        pushButton_rightParentheses->setText(QCoreApplication::translate("calculator_window", ")", nullptr));
        pushButton_power->setText(QCoreApplication::translate("calculator_window", "^", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calculator_window: public Ui_calculator_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_WINDOW_H
