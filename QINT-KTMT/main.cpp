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
<<<<<<< HEAD
	/*string fiName, foName;
	cin >> fiName >> foName;

	handleFile(fiName, foName);*/

=======
>>>>>>> 61866498589c89ff36eba1cc050e9fc785e54be3
	return 0;
}