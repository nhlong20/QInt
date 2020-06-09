#pragma once
#include <iostream>
#include <bitset>
using namespace std;
#define N_BITS 128
class QInt
{
private:
	long long arrayBits[2];
public:
	// Init QInt = 0;
	QInt();
	QInt(std::string);
	QInt(const QInt&);
	~QInt();
public:
	// Ham chuyen tu QInt sang co so khac
	std::string toBin();
	std::string toDec();
	std::string toHex();

	bool getBit(int pos);
	void setBit(int bit, int pos);

	void twoComplementQInt(); // So bu 2

	//Chuyển string sang nhị phân đưa vào QInt
	static std::string decToBin(std::string);
	static std::string hexToBin(std::string);
	// Chuyển từ chuỗi số nguyên lớn sang chuỗi nhị phân 128 bit
	static std::string divByTwo_String(std::string);
	static std::string calTwoComplement_String(std::string);
	void scanQInt(std::string, std::string);
public:
	QInt operator=(const QInt&);
	QInt operator+(const QInt&);
	//QInt operator-(const QInt&);
	//QInt operator*(const QInt&);
	//QInt operator/(const QInt&);


	//operator and or xor not
	QInt operator&(const QInt&);
	QInt operator|(const QInt&);
	QInt operator^(const QInt&);
	QInt operator~();

	//operator dịch trái dịch phải
	QInt operator<<(int);
	QInt operator>>(int);

	void rotateLeft();
	void rotateRight();
};