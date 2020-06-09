#include "QInt.h"
#include <fstream>
#include <iostream>
using namespace std;
//// Read and write file
//void handleFileInt() {
//
//}

//void handleFile(string fiName, string foName)
//{	
//	ifstream fi;
//	ofstream fo;
//	fi.open(fiName.c_str());
//	fo.open(foName.c_str());
//	handleFileInt();
//	fi.close();
//	fo.close();
//
//}

int main(int argc, char* argv[]) {
	/*string fiName, foName;
	cin >> fiName >> foName;

	handleFile(fiName, foName);*/
	QInt a;
	a.scanQInt("A0D6", "16");
	cout << a.toBin() << endl;
	QInt b("1011");
}