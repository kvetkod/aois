#include "FloatBinary.h"

string FloatNumber::DirectCodeForExp() {
	double number_;
	double num1 = modf(number, &number_);
	Binary num(number_);
	num.DirectCode();
	string floatnumber = num.GetBinaryNumber();
	return floatnumber;
}

void FloatNumber::DirectCodeForMantissa() {
	string result = "";
	double number_, num1;
	number_ = modf(number, &num1);
	while (number_ != 0) {
		number_ = number_ * 2;
		if (number_ < 1)
			result += '0';
		else {
			result += '1';
			number_ -= 1;
		}
	}
	mantissa = result;
}

void FloatNumber::DirectCode() {
	DirectCodeForMantissa();
	string exp_ = DirectCodeForExp();
	string _number = DirectCodeForExp() + "." + mantissa;
	_number.erase(0, 1);
	first = _number[0];
	int count = 0;
	for (int i = 1; i < _number.length(); i++) {
		if (_number[i] == '.') break;
		else count++;
	}
	Binary num(count + 127);
	num.DirectCode();
	exp = num.GetBinaryNumber();
	if(exp.length()!=8)
		exp.erase(0, 1);
	
	for (int i = 0; i <= count; i++) {
		mantissa = exp_[exp_.length() - i] + mantissa;
	}
	mantissa.erase(remove(mantissa.begin(), mantissa.end(), '\0'), mantissa.end());
}


void FloatNumber::FromBinaryToDecimal() {

	Binary number_('0' + exp, 1);
	number_.FromBinaryToDecimal();
	int number1 = number_.GetDecimalNumber() - 127;

	string result = "1";
	for (int i = 0; i < number1; i++) {
		result.push_back(mantissa[i]);
	}
	for (int i = 0; i < number1; i++) {
		mantissa.erase(0, 1);
	}
	Binary number2('0' + result, 1);
	number2.FromBinaryToDecimal();
	number = number2.GetDecimalNumber();

	for (int i = 0; i < mantissa.size(); i++) {
		if (mantissa[i] == '1') {
			number += pow(2, -(i + 1));
		}
	}
}
