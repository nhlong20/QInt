#include "QInt.h"
//constructor
QInt::QInt()
{
	this->arrayBits[0] = 0;
	this->arrayBits[1] = 0;
}
//constructor từ chuỗi bit truyền vào
QInt::QInt(std::string Bin)
{
	while (Bin.size() < 128)
		Bin = '0' + Bin;

	std::bitset<64> foo1(std::string(Bin.substr(0, 64)));
	std::bitset<64> foo2(std::string(Bin.substr(64, 64)));

	this->arrayBits[0] = foo1.to_ullong();
	this->arrayBits[1] = foo2.to_ullong();

}
//copy constructor
QInt::QInt(const QInt& other)
{
	this->arrayBits[0] = other.arrayBits[0];
	this->arrayBits[1] = other.arrayBits[1];
}
//destructor
QInt::~QInt() {}
// -----------------------------
bool QInt::getBit(int pos)
{
	long long  num = this->arrayBits[pos / 64];
	return (num >> (pos % 64)) & 1;
}
void QInt::setBit(int bit, int pos)
{
	if (bit == 1)
		arrayBits[pos / 64] |= (1 << 63 - (pos % 64));
	else
		arrayBits[pos / 64] &= ~(1 << (63 - pos % 64));
}
void QInt::twoComplementQInt() {
	QInt* soMot = new QInt("1");
	*this = ~*this;
	//*this = *this + *soMot;
	delete soMot;
}

//-----------------------------------------------
std::string QInt::divByTwo_String(std::string str) {
	std::string quotient;
	int temp = str[0] - '0';
	int len = str.length();
	int i = 0;
	while (temp == 0 || temp == 1) {
		temp = (int)(str[++i] - '0') + temp * 10;
	}
	while (len > i) {
		quotient += (int)(temp / 2 + '0');
		i++;
		if (str[i]) {
			temp = (temp % 2) * 10 + (int)(str[i] - '0');
		}
	}
	return quotient;
}
std::string QInt::decToBin(std::string str) {
	bool isNegative = false;
	if (str[0] == '-') {
		isNegative = true;
		str.erase(str.begin());
	}

	//convert to Bin
	string bin;
	int remainder;

	while (str != "") {
		remainder = (int)(str[str.length() - 1] - '0') % 2;
		if (remainder == 1) {
			bin.insert(bin.begin(), '1');
		}
		else {
			bin.insert(bin.begin(), '0');
		}
		str = QInt::divByTwo_String(str);
	}
	int len = bin.length();
	if (len < N_BITS) {
		bin.insert(0, N_BITS - len, '0');
	}

	if (isNegative) {
		// lay Bin bu 2 cua String
		bin = QInt::calTwoComplement_String(bin);
	}
	return bin;
}
std::string QInt::calTwoComplement_String(std::string str) {
	//// Add zero
	//int len = str.length();
	//if (len < N_BITS) {
	//	str.insert(0, N_BITS - len, '0');
	//}
	// Fplit bit string
	int len = str.length();
	while (len > 0) {
		str[len - 1] = str[len - 1] == '1' ? '0' : '1';
		len--;
	}
	// Plus str with 1
	char Q = 0, i = N_BITS - 1;
	string sum(N_BITS, '0');
	string numberOne(N_BITS, '0');
	numberOne[N_BITS- 1] = '1';
	while (i >= 0) {
		sum[i] = (((str[i]-'0') ^ (numberOne[i]-'0')) ^ Q) +'0';
		if (Q == 1 && (((str[i]-'0') ^ (numberOne[i]-'0')) == 1)) Q = 1;
		else Q = (str[i]-'0') & (numberOne[i]-'0');
		i--;
	}
	return sum;


}
void QInt::scanQInt(std::string str, std::string base) {
	if (base == "10") {
		//12345678987654321234678->010110101010
		//convert decToBin
		str = QInt::decToBin(str);
	}
	else if (base == "16") {
		//convert 16 to bin
		//str == QInt::hexToBin(str);
	}

	std::bitset<64> foo1(std::string(str.substr(0, 64)));
	std::bitset<64> foo2(std::string(str.substr(64, 64)));

	this->arrayBits[0] = foo1.to_ullong();
	this->arrayBits[1] = foo2.to_ullong();
}

//------------------------------------
//lấy ra dãy bit của  QInt dưới dạng chuỗi string
std::string QInt::toBin()
{
	std::bitset<64> foo1 = this->arrayBits[0];
	std::bitset<64> foo2 = this->arrayBits[1];

	std::string Bin = foo1.to_string() + foo2.to_string();
	return Bin;
}
//overloading operator AND ( & )
QInt QInt::operator&(const QInt& other)
{
	QInt temp;
	temp.arrayBits[0] = this->arrayBits[0] & other.arrayBits[0];
	temp.arrayBits[1] = this->arrayBits[1] & other.arrayBits[0];
	return temp;
}
//overloading operator OR ( | )
QInt QInt::operator|(const QInt& other)
{
	QInt temp;
	temp.arrayBits[0] = this->arrayBits[0] | other.arrayBits[0];
	temp.arrayBits[1] = this->arrayBits[1] | other.arrayBits[1];
	return temp;
}
//overloading operator XOR ( ^ )
QInt QInt::operator^(const QInt& other)
{
	QInt temp;
	temp.arrayBits[0] = this->arrayBits[0] ^ other.arrayBits[0];
	temp.arrayBits[1] = this->arrayBits[1] ^ other.arrayBits[1];
	return temp;
}
//overloading operator NOT ( ~ )
QInt QInt::operator~()
{
	QInt temp;
	temp.arrayBits[0] = ~this->arrayBits[0];
	temp.arrayBits[1] = ~this->arrayBits[1];
	return temp;
}
//overloading operator shift left ( << )
QInt QInt::operator<<(int k)
{
	QInt temp(*this);
	for (auto i = 0; i < k; ++i)
	{
		temp.arrayBits[0] <<= 1;
		//if (temp.arrayBits[1] < 0)
		temp.arrayBits[0] |= 1;
		temp.arrayBits[1] <<= 1;
	}
	return temp;
}
//overloading operator shift right ( >> )
QInt QInt::operator>>(int k)
{
	QInt temp(*this);
	for (auto i = 0; i < k; ++i)
	{
		temp.arrayBits[1] >>= 1;
		temp.arrayBits[1] |= (temp.arrayBits[0] << (sizeof(long long) * 8 - 1));
		temp.arrayBits[0] >>= 1;
	}
	return temp;
}
//rotate left function
void QInt::rotateLeft()
{
	int temp = 0;
	if (this->arrayBits[0] < 0)
		temp = 1;
	*this = *this << 1;
	this->arrayBits[1] |= temp;
}
//ratate right function
void QInt::rotateRight()
{
	int temp = 1;
	temp &= this->arrayBits[1]; //lưu bit cuối cùng của QInt
	*this = *this >> 1;
	if (temp == 1)  //bật bit đầu tiên (bit trái cùng)
	{
		std::bitset<64> foo = this->arrayBits[0];
		foo.set(63, 1); //set bit trái cùng = 1 
		this->arrayBits[0] = foo.to_ullong();
	}
	else //tắt bit đầu tiên (bit trái cùng)
	{
		std::bitset<64> foo = this->arrayBits[0];
		foo.set(63, 0); //set bit trái cùng = 0
		this->arrayBits[0] = foo.to_ullong();
	}
}
QInt QInt::operator+(const QInt& other) {
	string thisBin = this->toBin();
	std::bitset<64> foo1 = other.arrayBits[0];
	std::bitset<64> foo2 = other.arrayBits[1];
	std::string otherBin = foo1.to_string() + foo2.to_string();
	string temp; temp.resize(128, '0');
	char Q = 0;
	for (int i = thisBin.length() - 1; i >= 0;i--) {
		temp[i] = (thisBin[i] ^ otherBin[i]) ^ Q;
		if (Q == 1 && thisBin[i] ^ otherBin[i] == 1) Q = 1;
		else Q = (thisBin[i] & otherBin[i]);
	}
	return *this;
};
QInt QInt::operator=(const QInt& other) {
	this->arrayBits[0] = other.arrayBits[0];
	this->arrayBits[1] = other.arrayBits[1];
	return *this;

}