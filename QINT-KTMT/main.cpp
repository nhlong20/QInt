#include "QInt.h"
#include <fstream>
int checkBit() {
	return 1;
}

// Read and write file
void handleFileInt() {

}

void handleFile(string fiName, string foName)
{	
	ifstream fi;
	ofstream fo;
	fi.open(fiName.c_str());
	fo.open(foName.c_str());
	handleFileInt();
	fi.close();
	fo.close();

}

int main() {
	/*string fiName, foName;
	cin >> fiName >> foName;

	handleFile(fiName, foName);*/

	return 0;
}