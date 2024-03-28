#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include"Binary.h"
using namespace std;


class FloatNumber
{
private:
	double number;
	char symbol = '0';
	char first;
	string exp;
	string mantissa;
	string DirectCodeForExp();
	void DirectCodeForMantissa();
public:
	FloatNumber(string exp_, string mantissa_) : exp(exp_), mantissa(mantissa_) {};
	FloatNumber(double number_) : number(number_) {};
	void SetFirst(char symbol) { first = symbol; };

	void Print() {
		cout << symbol << "|" << exp << "|" << mantissa << endl;
	}
	void DirectCode();
	string GetExp() {
		return exp;
	}
	string GetMantissa() {
		return mantissa;
	}
	char GetFirst() {
		return first;
	}


	void FromBinaryToDecimal();

	double GetDecimal() {
		return number;
	}
};

