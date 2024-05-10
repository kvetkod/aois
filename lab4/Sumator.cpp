#include "Sumator.h"



void Sumator::CreateSumator() {
	for (int i = 0; i < 8; i++) {
		vector<bool> table1 = { 0, 0, 0, 0, 0 };
		table.push_back(table1);
	}
	int j = 0, rows1 = 4, count = 0;
	while (j < 3) {
		vector<bool> table1;
		count = 1;
		for (int i = 0; i < 8; i++) {
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


	for (int i = 0; i < 8; i++) {
		if (table[i][0] == 0 and table[i][1] == 1) {
			if (table[i][2] == 0) {
				table[i][3] = 1;
			}
			if (table[i][2] == 1) {
				table[i][3] = 0;
				table[i][4] = 1;
			}
		}
		if (table[i][0] == 0 and table[i][1] == 0) {
			if (table[i][2] == 0) {
				table[i][3] = 0;
			}
			if (table[i][2] == 1) {
				table[i][3] = 1;
			}
		}
		if (table[i][0] == 1 and table[i][1] == 0) {
			if (table[i][2] == 0) {
				table[i][3] = 1;
			}
			if (table[i][2] == 1) {
				table[i][3] = 0;
				table[i][4] = 1;
			}
		}
		if (table[i][0] == 1 and table[i][1] == 1) {
			if (table[i][2] == 0) {
				table[i][3] = 0;
				table[i][4] = 1;
			}
			if (table[i][2] == 1) {
				table[i][3] = 1;
				table[i][4] = 1;
			}
		}
	}
	cout << "ABCSP" << endl;
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j];
		}
		cout << endl;
	}
	SKNF();
	cout << "Minimization for S" << endl;
	Minimization a;
	a.MinimizationSKNF(sknf(3));
	cout << "Minimization for P" << endl;
	a.MinimizationSKNF(sknf(4));
}

string Sumator::sknf(int index) {
	string result;
	for (int i = 0; i < 8; i++) {
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
			result.push_back(')');
			result.push_back('&');
		}
	}
	result.erase(result.size() - 1, 1);
	return result;
}

void Sumator::SKNF() {
	cout << "SKNF for S" << endl;
	cout << sknf(3) << endl;
	cout << "SKNF for P" << endl;
	cout << sknf(4) << endl;
}

