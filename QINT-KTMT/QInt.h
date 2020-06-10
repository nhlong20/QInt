#pragma once
#include <iostream>
#include <bitset>
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
	// So QInt bu 2
	void twoComplementQInt(); 
	// Đọc số QInt từ một chuõi
	void scanQInt(std::string str, std::string base);
	// Chuyển số QInt thành chuỗi Bin
	std::string toBin();
	// Chuyển số QInt thành chuỗi Dec
	std::string toDec();
	// Chuyển số QInt thành chuỗi Hex
	std::string toHex();
public:
	//QInt operator=(const QInt&);
	//QInt operator+(const QInt&);
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