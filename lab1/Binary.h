#pragma once
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


class Binary
{
private:
	int d_number;
	string b_number;
	int method = 0;
public:
	Binary(int number) : d_number(number) {};
	Binary(string number, int method_) : b_number(number), method(method_) {};
	void DirectCode();
	void ReverseCode();
	void AdditionalCode();
	void FromBinaryToDecimal();
	int GetDecimalNumber();
	string GetBinaryNumber();
	int WhichMethod();
};

