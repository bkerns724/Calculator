#pragma once

#include <QtWidgets/QMainWindow>
#include <string>

#include "ui_calculator_window.h"
#include "equation.h"

class CalculatorQt : public QMainWindow{
	Q_OBJECT

public:
	CalculatorQt(QWidget *parent = Q_NULLPTR);

public slots:

	void CalculateAnswer();

	void Insert0() { ui.textEdit_Equation->insertPlainText("0"); }
	void Insert1() { ui.textEdit_Equation->insertPlainText("1"); }
	void Insert2() { ui.textEdit_Equation->insertPlainText("2"); }
	void Insert3() { ui.textEdit_Equation->insertPlainText("3"); }
	void Insert4() { ui.textEdit_Equation->insertPlainText("4"); }
	void Insert5() { ui.textEdit_Equation->insertPlainText("5"); }
	void Insert6() { ui.textEdit_Equation->insertPlainText("6"); }
	void Insert7() { ui.textEdit_Equation->insertPlainText("7"); }
	void Insert8() { ui.textEdit_Equation->insertPlainText("8"); }
	void Insert9() { ui.textEdit_Equation->insertPlainText("9"); }
	void InsertDecimal() { ui.textEdit_Equation->insertPlainText("."); }
	void InsertPlus() { ui.textEdit_Equation->insertPlainText("+"); }
	void InsertMinus() { ui.textEdit_Equation->insertPlainText("-"); }
	void InsertMult() { ui.textEdit_Equation->insertPlainText("*"); }
	void InsertDiv() { ui.textEdit_Equation->insertPlainText("/"); }
	void InsertPower() { ui.textEdit_Equation->insertPlainText("^"); }
	void InsertLPar() { ui.textEdit_Equation->insertPlainText("("); }
	void InsertRPar() { ui.textEdit_Equation->insertPlainText(")"); }
	void EquationClear() { ui.textEdit_Equation->clear(); }

private:
	void CreateActions();

	Ui::calculator_window ui;

	equation theEquation;
};
