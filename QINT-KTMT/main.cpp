#include <fstream>
#include "QInt.h"
#include "handleString.h"
using namespace std;

int main(int argc, char* argv[]) {
	QInt a;
	a.scanQInt("1234567821412412412", "10");
	cout << a.toDec();
}