#pragma once
#include<iostream>
#include"Binary.h"
#include"FloatBinary.h"
#include<string>
#include<algorithm>

using namespace std;


class Operation
{
private:
	int d_number1, d_number2;
	double f_number1, f_number2;
	string b_number1, b_number2;
	Operation(string number1, string number2) : b_number1(number1), b_number2(number2) {};
	string SumHelper(string number1, string number2, bool& flag);
	int SameSize(string& number1, string& number2, int method1, int method2);
	void SameSizeHelper(string& number1, string& number2);
	string MultiplicationHelper(string number1, char number2, int i, int size);
	string DivisionHelper(string number1, string number2);
	int ZeroRemover(string& number);
	bool check(string, string);
public:
	Operation(int number1, int number2) : d_number1(number1), d_number2(number2) {};
	Operation(double number1, double number2) : f_number1(number1), f_number2(number2) {};
	string SumForFloat();
	string Sum();
	string Subtraction();
	string Multiplication();
	string Division();
};


