#include <fstream>
#include "QInt.h"
#include "handleString.h"
using namespace std;

int main(int argc, char* argv[]) {
	QInt a, b, c, d;
	a.scanQInt("11111001", "2");
	cout << a.toBin() << endl;
	cout << a.toDec() << endl;
	cout << a.toHex() << endl;
	cout <<"-----------"<< endl;
	b.scanQInt("12345612345678", "10");
	cout << b.toBin() << endl;
	cout << b.toDec() << endl;
	cout << b.toHex() << endl;
	cout << "-----------" << endl;
	d.scanQInt("FAFA1094BD", "16");
	cout << d.toBin() << endl;
	cout << d.toDec() << endl;
	cout << d.toHex() << endl;
}