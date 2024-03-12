#include "Binary.h"

string Binary::GetBinaryNumber() {
	return b_number;
}

int Binary::WhichMethod() {
	return method;
}



int Binary::GetDecimalNumber() {
	return d_number;
}

void Binary::FromBinaryToDecimal() {
	d_number = 0;
	if (method == 2) { ReverseCode(); }
	if (method == 3) {
		ReverseCode();
		AdditionalCode();
	}
	bool flag = true;
	if (b_number[0] == '1') flag = false;
	int k = 0;
	for (int i = b_number.length() - 1; i > 0; i--) {
		if (b_number[i] == '1') {
			d_number += pow(2, k);
		}
		k++;
	}
	if (!flag) d_number *= (-1);
}

void Binary::DirectCode() {
	method = 1;
	int n = abs(d_number);
	string result = "";

	while (n > 0) {
		if (n == 1) { result = '1' + result; break; }
		if (n % 2 == 1) result = '1' + result;
		if (n % 2 == 0) result = '0' + result;
		n = n / 2;
	}
	if (d_number > 0) result = '0' + result;
	else result = '1' + result;
	b_number = result;
	return;
}

void Binary::ReverseCode() {
	if (method != 1) DirectCode();
	method = 2;
	for (int i = 1; i < b_number.length(); i++) {
		if (b_number[i] == '1') b_number[i] = '0';
		else b_number[i] = '1';
	}
}


void Binary::AdditionalCode() {
	if (method == 0) DirectCode();
	if (method == 1) ReverseCode();
	method = 3;
	bool flag = true;

	for (int i = b_number.length() - 1; i > 0; i--) {
		if (b_number[i] == '1') {
			if (flag) {
				b_number[i] = '0';
				flag = true;
				continue;
			}
			else {
				b_number[i] = '1';
				continue;
			}
		}
		if (b_number[i] == '0') {
			if (flag) {
				b_number[i] = '1';
				flag = false;
			}
			else {
				b_number[i] = '0';
			}
		}
	}
	if (flag) {
		char symbol = b_number[0];
		b_number = '1' + b_number;
		b_number = symbol + b_number;
	}
	return;
}
