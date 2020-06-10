#include "QInt.h"
#include "handleString.h"
//constructor
QInt::QInt()
{
	this->arrayBits[0] = 0;
	this->arrayBits[1] = 0;
}
//constructor từ chuỗi bit truyền vào
QInt::QInt(std::string bin)
{
	if (bin.length() < N_BITS) {
		bin.insert(0, N_BITS - bin.length(), '0');
	}

	std::bitset<64> foo1(std::string(bin.substr(0, 64)));
	std::bitset<64> foo2(std::string(bin.substr(64, 64)));

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
void QInt::twoComplementQInt() {
	QInt* soMot = new QInt("1");
	*this = ~*this;
	//*this = *this + *soMot;
	delete soMot;
}

//-----------------------------------------------
void QInt::scanQInt(std::string str, std::string base) {
	if (base == "10") {
		//convert decToBin
		str = decToBin(str);
	}
	else if (base == "16") {
		//convert 16 to bin
		str = hexToBin(str);
	}
	if (str.length() < N_BITS) {
		str.insert(0, N_BITS - str.length(), '0');
	}
	std::bitset<64> foo1(std::string(str.substr(0, 64)));
	std::bitset<64> foo2(std::string(str.substr(64, 64)));

	this->arrayBits[0] = foo1.to_ullong();
	this->arrayBits[1] = foo2.to_ullong();
}

//------------------------------------
std::string QInt::toBin(){
	std::bitset<64> foo1 = this->arrayBits[0];
	std::bitset<64> foo2 = this->arrayBits[1];

	std::string Bin = foo1.to_string() + foo2.to_string();
	return Bin;
}

std::string QInt::toDec() {
	std::string bin = this->toBin();
	std::string dec = binToDec(bin);
	return dec;
}
std::string QInt::toHex() {
	std::string bin = this->toBin();
	std::string hex = binToHex(bin);
	return hex;
}

//overloading operator AND ( & )
QInt QInt::operator&(const QInt& other){
	QInt temp;
	temp.arrayBits[0] = this->arrayBits[0] & other.arrayBits[0];
	temp.arrayBits[1] = this->arrayBits[1] & other.arrayBits[0];
	return temp;
}
//overloading operator OR ( | )
QInt QInt::operator|(const QInt& other){
	QInt temp;
	temp.arrayBits[0] = this->arrayBits[0] | other.arrayBits[0];
	temp.arrayBits[1] = this->arrayBits[1] | other.arrayBits[1];
	return temp;
}
//overloading operator XOR ( ^ )
QInt QInt::operator^(const QInt& other){
	QInt temp;
	temp.arrayBits[0] = this->arrayBits[0] ^ other.arrayBits[0];
	temp.arrayBits[1] = this->arrayBits[1] ^ other.arrayBits[1];
	return temp;
}
//overloading operator NOT ( ~ )
QInt QInt::operator~(){
	QInt temp;
	temp.arrayBits[0] = ~this->arrayBits[0];
	temp.arrayBits[1] = ~this->arrayBits[1];
	return temp;
}
//overloading operator shift left ( << )
QInt QInt::operator<<(int k){
	QInt temp(*this);
	for (auto i = 0; i < k; ++i){
		temp.arrayBits[0] <<= 1;
		//if (temp.arrayBits[1] < 0)
		temp.arrayBits[0] |= 1;
		temp.arrayBits[1] <<= 1;
	}
	return temp;
}
//overloading operator shift right ( >> )
QInt QInt::operator>>(int k){
	QInt temp(*this);
	for (auto i = 0; i < k; ++i){
		temp.arrayBits[1] >>= 1;
		temp.arrayBits[1] |= (temp.arrayBits[0] << (sizeof(long long) * 8 - 1));
		temp.arrayBits[0] >>= 1;
	}
	return temp;
}
//rotate left function
void QInt::rotateLeft(){
	int temp = 0;
	if (this->arrayBits[0] < 0)
		temp = 1;
	*this = *this << 1;
	this->arrayBits[1] |= temp;
}
//ratate right function
void QInt::rotateRight(){
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
