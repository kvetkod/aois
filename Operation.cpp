#include "Operation.h"

string Operation::SumHelper(string number1, string number2, bool& flag) {
	string result = "";
	for (int i = number1.length(); i >= 0; i--) {
		if (number1[i] == '1' && number2[i] == '1') {
			if (flag) {
				result = '1' + result;
				flag = true;
			}
			else {
				result = '0' + result;
				flag = true;
			}
		}
		if (number1[i] == '0' && number2[i] == '0') {
			if (flag) {
				result = '1' + result;
				flag = false;
			}
			else {
				result = '0' + result;
			}
		}
		if (number1[i] == '1' && number2[i] == '0') {
			if (flag) {
				result = '0' + result;
				flag = true;
			}
			else {
				result = '1' + result;
			}
		}
		if (number2[i] == '1' && number1[i] == '0') {
			if (flag) {
				result = '0' + result;
				flag = true;
			}
			else {
				result = '1' + result;
			}
		}
	}
	return result;
}

void Operation::SameSizeHelper(string& number1, string& number2) {
	if (number1.length() == number2.length()) return;
	if (number1.length() > number2.length()) {
		char symbol = number2[0];
		number2.erase(0, 1);
		int size = number2.length();
		for (int i = 1; i < number1.length() - size; i++) {
			number2 = '0' + number2;
		}
		number2 = symbol + number2;
		return;
	}
	if (number1.length() < number2.length()) {
		char symbol = number1[0];
		number1.erase(0, 1);
		int size = number1.length();
		for (int i = 1; i < number2.length() - size; i++) {
			number1 = '0' + number1;
		}
		number1 = symbol + number1;
		return;
	}
}

int Operation::SameSize(string& number1, string& number2, int method1, int method2) {
	Binary num1(d_number1), num2(d_number2);
	if (method1 == 1 && method2 == 1) {
		num1.DirectCode(); num2.DirectCode();
		number1 = num1.GetBinaryNumber(); number2 = num2.GetBinaryNumber();
		SameSizeHelper(number1, number2);
		return 0;
	}
	if (method1 == 1 && method2 == 3) {
		num1.DirectCode(); num2.DirectCode();
		number1 = num1.GetBinaryNumber(); number2 = num2.GetBinaryNumber();
		SameSizeHelper(number1, number2);
		Binary b_number2(number2, 1);
		b_number2.AdditionalCode();
		number2 = b_number2.GetBinaryNumber();
		return 1;
	}
	if (method2 == 1 && method1 == 3) {
		num2.DirectCode(); num1.DirectCode();
		number1 = num1.GetBinaryNumber(); number2 = num2.GetBinaryNumber();
		SameSizeHelper(number1, number2);
		Binary b_number1(number1, 1);
		b_number1.AdditionalCode();
		number1 = b_number1.GetBinaryNumber();
		return 1;
	}
	if (method1 == 3 && method2 == 3) {
		num1.DirectCode(); num2.DirectCode();
		number1 = num1.GetBinaryNumber(); number2 = num2.GetBinaryNumber();
		SameSizeHelper(number1, number2);
		Binary b_number1(number1, 1), b_number2(number2, 1);
		b_number2.AdditionalCode(); b_number1.AdditionalCode();
		number2 = b_number2.GetBinaryNumber(); number1 = b_number1.GetBinaryNumber();
		return 2;
	}
}

string Operation::Sum() {
	int state;


	if (d_number1 > 0 && d_number2 > 0) {
		state = SameSize(b_number1, b_number2, 1, 1);
	}
	else if (d_number1 < 0 && d_number2 < 0) {
		state = SameSize(b_number1, b_number2, 3, 3);
	}
	else if (d_number1 > 0 && d_number2 < 0) {
		state = SameSize(b_number1, b_number2, 1, 3);
	}
	else if (d_number1 < 0 && d_number2 > 0) {
		state = SameSize(b_number1, b_number2, 3, 1);
	}



	string result = "";
	bool flag = false;
	result = SumHelper(b_number1, b_number2, flag);

	if (state == 1) {
		if (result[0] == '0') return result;
		else {
			Binary f_result(result, 1);
			f_result.AdditionalCode();
			result = f_result.GetBinaryNumber();
		}
	}
	else if (state == 0) {
		if (flag) {
			result = "01" + result;
		}
		else result = '0' + result;
	}
	else if (state == 2) {
		result = '1' + result;
		Binary f_result(result, 1);
		f_result.AdditionalCode();
		result = f_result.GetBinaryNumber();
		return result;
	}
	return result;
}

string Operation::Subtraction() {
	d_number2 = d_number2 * (-1);
	return Sum();
}

string Operation::MultiplicationHelper(string number1, char number2, int index, int size) {
	string result = "";
	if (number2 == '0') {
		for (int i = 0; i < size; i++) {
			result = '0' + result;
		}
	}
	else {
		for (int i = 0; i < index; i++) {
			result = '0' + result;
		}
		result = number1 + result;
		for (int i = result.length(); i < size; i++) {
			result = '0' + result;
		}
	}
	return result;
}

string Operation::Multiplication() {
	Binary num1(d_number1), num2(d_number2);
	num1.DirectCode(); num2.DirectCode();
	b_number1 = num1.GetBinaryNumber();
	b_number2 = num2.GetBinaryNumber();
	SameSizeHelper(b_number1, b_number2);
	char symbol = '0';
	if (b_number1[0] == '1' && b_number2[0] == '0') symbol = '1';
	if (b_number1[0] == '0' && b_number2[0] == '1') symbol = '1';
	b_number2.erase(0, 1); b_number1.erase(0, 1);
	int size = b_number1.length() + b_number2.length() - 1;
	string number2 = b_number2;
	reverse(number2.begin(), number2.end());
	string first = MultiplicationHelper(b_number1, number2[0], 0, size);
	string second; int size1 = b_number1.length();
	bool flag;
	for (int i = 1; i < number2.length(); i++) {
		flag = false;
		second = MultiplicationHelper(b_number1, number2[i], i, size);
		first = SumHelper(first, second, flag);
		if (flag) {
			size++;
			first = '1' + first;
		}
	}
	first = symbol + first;
	return first;
}

bool Operation::Comparison(string number1, string number2) {
	if (number1.length() < number2.length()) {
		return false;
	}
	for (int i = 0; i < number2.length(); i++) {
		if (number1[i] == '1' && number2[i] == '0') return true;
		if (number1[i] == '0' && number2[i] == '1')
			return false;
	}
	return true;
}

string Operation::DivisionHelper(string number1, string number2) {
	bool flag = false;
	string number1_ = number1;
	string number2_ = number2;

	if (number2_.length() < number1_.length()) {
		int size = number2_.length();
		for (int i = 0; i < number1_.length() - size; i++) {
			number2_ = '0' + number2_;
		}
	}
	string result = "";
	for (int i = number2_.length() - 1; i >= 0; i--) {
		if (number1_[i] == '0' && number2_[i] == '1') {
			if (flag) {
				result = '0' + result;
				flag = true;
			}
			else {
				result = '1' + result;
				flag = true;
			}
		}
		if (number1_[i] == '0' && number2_[i] == '0') {
			if (flag) {
				result = '1' + result;
				flag = true;
			}
			else {
				result = '0' + result;
			}
		}
		if (number1_[i] == '1' && number2_[i] == '1') {
			if (flag) {
				result = '1' + result;
				flag = true;
			}
			else {
				result = '0' + result;
			}
		}
		if (number1_[i] == '1' && number2_[i] == '0') {
			if (flag) {
				result = '0' + result;
				flag = false;
			}
			else {
				result = '1' + result;
			}
		}
	}
	ZeroRemover(result);

	return result;
}



int Operation::ZeroRemover(string& number) {
	if (number.length() == 1) return 0;
	int k = 0;
	for (int i = 0; i < number.length() - 1; i++) {
		if (number[i] != '0') return k;
		number.erase(0, 1);
		k++;
		i--;
	}
	return k;
}


string Operation::Division() {
	Binary num1(d_number1), num2(d_number2);
	num1.DirectCode(); num2.DirectCode();
	b_number1 = num1.GetBinaryNumber();
	b_number2 = num2.GetBinaryNumber();
	char symbol = '0';
	if (b_number1[0] == '1' && b_number2[0] == '0') symbol = '1';
	if (b_number1[0] == '0' && b_number2[0] == '1') symbol = '1';
	string number1 = b_number1, number2 = b_number2;
	number2.erase(0, 1); number1.erase(0, 1);

	for (int i = 0; i < number1.length(); i++) {
		if (number1[i] != '0') break;
		number1.erase(0, 1);
	}
	for (int i = 0; i < number2.length(); i++) {
		if (number2[i] != '0') break;
		number2.erase(0, 1);
	}



	string result = ""; bool flag = false; int count = 0;
	string ostatok = ""; int k = -1;
	if (number2.length() > number1.length()) {
		result = "0."; k = 0;
		for (int i = 0; i < number2.length() - number1.length(); i++) {
			number1 += '0';
		}
		ostatok = number1;
		number1 = "0";
	}
	else {
		for (int i = 0; i < number2.length(); i++) {
			ostatok += number1[i];
		}
		for (int i = 0; i < number2.length(); i++) {
			number1.erase(0, 1);
		}
	}


	while (k < 6) {

		if (ostatok.length() > number2.length() || Comparison(ostatok, number2)) {
			count = 0;
			flag = false;
			result += '1';
			ostatok = DivisionHelper(ostatok, number2);
		}
		else {

			if (number1.size() == 0 && ostatok[0] == '0' && ostatok.length() == 1) {
				break;
			}


			if (number1.length() == 0) {

				if (k == -1) {
					k++;
					result += '.';
				}

				number1 += '0';

			}
			if (number1.length() != 0) {
				if (number1[0] == '1') {
					ostatok += number1[0];
					number1.erase(0, 1);

				}
				else {
					bool check = false;

					for (int i = 0; i < ostatok.length(); i++) {
						if (ostatok[i] == '1') {
							check = true; break;
						}

					}
					if (check) {
						count = 0;
						ostatok += number1[0];
						number1.erase(0, 1);
					}
					else {
						if (number1.length() == 1) count++;
						number1.erase(0, 1);

					}
				}
				if (flag) {
					result += '0';
				}
				else flag = false;
			}
		}
		if (k > -1) {
			k++;
		}
	}



	result = symbol + result;
	return result;
}


string Operation::SumForFloat() {
	FloatNumber num1(f_number1), num2(f_number2);
	num1.DirectCode(); num2.DirectCode();
	string exp1 = num1.GetExp(), exp2 = num2.GetExp();
	string mantissa1 = num1.GetMantissa(), mantissa2 = num2.GetMantissa();
	Binary number1('0' + exp1, 1), number2('0' + exp2, 1);
	number1.FromBinaryToDecimal(); number2.FromBinaryToDecimal();
	int count1 = number1.GetDecimalNumber(), count2 = number2.GetDecimalNumber();
	string exp = exp1;
	if (count1 != count2)
	{
		if (count1 > count2) {
			exp = exp2;
			mantissa2 = num2.GetFirst() + mantissa2;
			for (int i = 1; i < count1 - count2; i++) {
				mantissa2 = '0' + mantissa2;
			}
		}
		if (count1 < count2) {
			exp = exp1;
			mantissa1 = num1.GetFirst() + mantissa1; 
			for (int i = 1; i < count2 - count1; i++) {
				mantissa1 = '0' + mantissa1;
			}
		}
	}
	reverse(mantissa1.begin(), mantissa1.end());
	reverse(mantissa2.begin(), mantissa2.end());
	mantissa1 = '0' + mantissa1; mantissa2 = '0' + mantissa2;
	SameSizeHelper(mantissa1, mantissa2);
	reverse(mantissa1.begin(), mantissa1.end());
	reverse(mantissa2.begin(), mantissa2.end());
	//mantissa1.erase(0, 1); mantissa2.erase(0, 1);
	bool flag = false;
	string result = SumHelper(mantissa1, mantissa2, flag);
	if (flag) {
		flag = false;
		result = '0' + result;
		string exp = SumHelper(exp, "00000001", flag);
	}
	FloatNumber number(exp, result);
	number.Print();
	return "";
}