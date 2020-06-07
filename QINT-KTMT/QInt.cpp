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
<<<<<<< HEAD

bool QInt::getBit(int pos)
{
	long long  num = this->arrayBits[pos / 64];
	return (num >> (pos % 64)) & 1;
}
void QInt::setBit(long long bit, int pos)
{
	if (bit == 1)
		arrayBits[pos / 64] |= (1 << 63 - (pos % 64));
	arrayBits[pos / 64] &= ~(1 << (63 - pos % 64));
}











//------------------------------------
=======
//lấy ra dãy bit của  QInt dưới dạng chuỗi string
std::string QInt::getBin()
{
	std::bitset<64> foo1 = this->arrayBits[0];
	std::bitset<64> foo2 = this->arrayBits[1];

	std::string Bin = foo1.to_string() + foo2.to_string();
	return Bin;
}
>>>>>>> 61866498589c89ff36eba1cc050e9fc785e54be3
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