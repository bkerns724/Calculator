#include "calculatorqt.h"

using namespace std;

CalculatorQt::CalculatorQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	CreateActions();
}


void CalculatorQt::CreateActions() {
	connect(ui.pushButton_0, SIGNAL(clicked()), this, SLOT(Insert0()));
	connect(ui.pushButton_1, SIGNAL(clicked()), this, SLOT(Insert1()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(Insert2()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(Insert3()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(Insert4()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(Insert5()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(Insert6()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(Insert7()));
	connect(ui.pushButton_8, SIGNAL(clicked()), this, SLOT(Insert8()));
	connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(Insert9()));
	connect(ui.pushButton_decimal, SIGNAL(clicked()), this, SLOT(InsertDecimal()));
	connect(ui.pushButton_plus, SIGNAL(clicked()), this, SLOT(InsertPlus()));
	connect(ui.pushButton_minus, SIGNAL(clicked()), this, SLOT(InsertMinus()));
	connect(ui.pushButton_multiplication, SIGNAL(clicked()), this, SLOT(InsertMult()));
	connect(ui.pushButton_division, SIGNAL(clicked()), this, SLOT(InsertDiv()));
	connect(ui.pushButton_power, SIGNAL(clicked()), this, SLOT(InsertPower()));
	connect(ui.pushButton_rightParentheses, SIGNAL(clicked()), this, SLOT(InsertRPar()));
	connect(ui.pushButton_leftParentheses, SIGNAL(clicked()), this, SLOT(InsertLPar()));

	connect(ui.pushButton_clear, SIGNAL(clicked()), this, SLOT(EquationClear()));
	connect(ui.pushButton_equals, SIGNAL(clicked()), this, SLOT(CalculateAnswer()));
}

void CalculatorQt::CalculateAnswer() {
	ui.textEdit_Output->clear();
	theEquation.NewEquation(ui.textEdit_Equation->toPlainText().toStdString());
	if (theEquation.IsValid() == true) {
		string str = to_string(theEquation.Answer());
		string cutString = "0.";  // Want to remove trailing zeros and not leave a trailing decimal point
		str.erase(str.find_last_not_of(cutString) + 1, std::string::npos);

		ui.textEdit_Output->insertPlainText(str.c_str());
	}
	else
		ui.textEdit_Output->insertPlainText(theEquation.GetErrorMessage().c_str());
}
