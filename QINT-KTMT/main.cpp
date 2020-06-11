#include <fstream>
#include "QInt.h"
#include "handleString.h"
using namespace std;

int main(int argc, char* argv[]) {
	QInt a("1010");
	cout << a.toDec() << endl;
	cout << a.toHex() << endl;
	cout << "-------------" << endl;
	a.twoComplementQInt();
	cout << a.toDec() << endl;
	cout << a.toHex() << endl;
	return 0;
}