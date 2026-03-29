#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

class mMatrix
{
public:
	mMatrix();
	mMatrix(unsigned char rows, unsigned char column);
	void SetData(unsigned char rows, unsigned char column);
	void Generate();
	void Print();
	vector<unsigned char> Find1();
	int Find1_RowNo();
	~mMatrix();
private:
	inline void initBuffer(unsigned char rows, unsigned char column);

private:
	uint16_t rows;
	uint16_t column;
	unsigned char* pBuf;
};

void test();