#include <fstream>
#include "QInt.h"
#include "handleString.h"
using namespace std;

int main(int argc, char* argv[]) {
	QInt a;
	a.scanQInt("11111001", "2");
	cout << a.toHex();
}