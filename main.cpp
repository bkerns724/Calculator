//  Look for ways to break with white space in odd places

#include "calculatorqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	CalculatorQt w;
	w.show();

	return a.exec();
}
