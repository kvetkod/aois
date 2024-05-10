#include "Synthesis.h"



void Synthesis::MakeSynthesis() {
	for (int i = 0; i < 16; i++) {
		vector<bool> table1 = { 0, 0, 0, 0, 0, 0, 0, 0 };
		table.push_back(table1);
	}
	int j = 0, rows1 = 8, count = 0;
	while (j < 4) {
		vector<bool> table1;
		count = 1;
		for (int i = 0; i < 16; i++) {
			for (i; i < rows1 * count; i++) {
				table[i][j] = 0;
			}
			count++;
			for (i; i < rows1 * count; i++) {
				table[i][j] = 1;
			}
			count++;
		}
		j++;
		rows1 = rows1 / 2;
	}

	for (int i = 0; i < 6; i++) {
		table.erase(table.begin() + table.size() - 1);
	}

	/*for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j];
		}
		cout << endl;
	}*/

	for (int i = 0; i < table.size(); i++) {
		string for_sum;
		for (int j = 0; j < 4; j++) {
			if (table[i][j] == 0) for_sum.push_back('0');
			if (table[i][j] == 1) for_sum.push_back('1');
		}
		Sum(for_sum, i);
	}

	cout << "ABSDEFGH" << endl;
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j];
		}
		cout << endl;
	}
	SKNF();
}

void Synthesis::Sum(string number, int index) {
	string result = ""; bool flag = true;
	for (int j = 0; j < 2; j++) {
		result = ""; flag = true;
		for (int i = number.size() - 1; i >= 0; i--) {
			if (number[i] == '0') {
				if (flag) {
					result = '1' + result;
					flag = false;
				}
				else {
					result = '0' + result;
				}
			}
			if (number[i] == '1') {
				if (flag) {
					result = '0' + result;
				}
				else {
					result = '1' + result;
				}
			}
		}
		number = result;
	}

	for (int i = 0; i < 4; i++) {
		if (result[i] == '0') table[index][i + 4] = 0;
		if (result[i] == '1') table[index][i + 4] = 1;
	}
}

string Synthesis::sknf(int index) {
	string result;
	for (int i = 0; i < 10; i++) {
		if (table[i][index] == 0) {
			result.push_back('(');
			if (table[i][0] == 0) result.push_back('A');
			if (table[i][0] == 1) {
				result.push_back('!');
				result.push_back('A');
			}
			result.push_back('|');
			if (table[i][1] == 0) result.push_back('B');
			if (table[i][1] == 1) {
				result.push_back('!');
				result.push_back('B');
			}
			result.push_back('|');
			if (table[i][2] == 0) result.push_back('C');
			if (table[i][2] == 1) {
				result.push_back('!');
				result.push_back('C');
			}
			result.push_back('|');
			if (table[i][3] == 0) result.push_back('D');
			if (table[i][3] == 1) {
				result.push_back('!');
				result.push_back('D');
			}
			result.push_back(')');
			result.push_back('&');
		}
	}
	result.erase(result.size() - 1, 1);
	return result;
}

void Synthesis::SKNF() {
	Minimization a;
	cout << "SKNF for E" << endl;
	cout << sknf(4) << endl;
	a.MinimizationSKNF(sknf(4));
	cout << "SKNF for F" << endl;
	cout << sknf(5) << endl;
	a.MinimizationSKNF(sknf(5));
	cout << "SKNF for G" << endl;
	cout << sknf(6) << endl;
	a.MinimizationSKNF(sknf(6));
	cout << "SKNF for H" << endl;
	cout << sknf(7) << endl;
	a.MinimizationSKNF(sknf(7));
}
