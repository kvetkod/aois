#include "Subtractor.h"


void Subtractor::CreateSubtractor() {
	for (int i = 0; i < 32; i++) {
		vector<bool> table1 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		table.push_back(table1);
	}
	int j = 0, rows1 = 16, count = 0;
	while (j < 5) {
		vector<bool> table1;
		count = 1;
		for (int i = 0; i < 32; i++) {
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

	reverse(table.begin(), table.end());
	for (int i = 0; i < table.size()/2; i++) {
		subtractor(i);
	}
	for (int i = 0; i < table.size() / 2; i++) {
		check(i);
	}

	cout << "V12341234ABCD" << endl;
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j];
		}
		cout << endl;
	}
	cout << endl;

	Minimization a;
	
	cout << "SDNF for A:" << endl;
	cout << sdnf(9) << endl;
	cout << "Minimization:" << endl;
	a.MinimizationSKNF(sdnf(9));
	cout << endl;

	cout << "SDNF for B:" << endl;
	cout << sdnf(10) << endl;
	cout << "Minimization:" << endl;
	a.MinimizationSKNF(sdnf(10));
	cout << endl;

	cout << "SDNF for C:" << endl;
	cout << sdnf(11) << endl;
	cout << "Minimization:" << endl;
	a.MinimizationSKNF(sdnf(11));
	cout << endl;

	cout << "SDNF for D:" << endl;
	cout << sdnf(12) << endl;
	cout << "Minimization:" << endl;
	a.MinimizationSKNF(sdnf(12));
	cout << endl;

}

void Subtractor::subtractor(int index) {
	for (int j = 1; j < 5; j++) {
		table[index][j + 4] = table[index + 1][j];
	}
}

void Subtractor::check(int index) {
	for (int j = 1; j < 5; j++) {
		if (table[index][j] != table[index][j + 4]) table[index][j + 8] = 1;
	}
}

string Subtractor::sdnf(int index) {
	string result;
	for (int i = 0; i < table.size()/2; i++) {
		if (table[i][index] == 1) {
			result.push_back('(');
			if (table[i][0] == 1) result.push_back('V');
			if (table[i][0] == 0) {
				result.push_back('!');
				result.push_back('V');
			}
			result.push_back('&');
			if (table[i][1] == 1) result.push_back('1');
			if (table[i][1] == 0) {
				result.push_back('!');
				result.push_back('1');
			}
			result.push_back('&');
			if (table[i][2] == 1) result.push_back('2');
			if (table[i][2] == 0) {
				result.push_back('!');
				result.push_back('2');
			}
			result.push_back('&');
			if (table[i][3] == 1) result.push_back('3');
			if (table[i][3] == 0) {
				result.push_back('!');
				result.push_back('3');
			}
			result.push_back('&');
			if (table[i][4] == 1) result.push_back('4');
			if (table[i][4] == 0) {
				result.push_back('!');
				result.push_back('4');
			}
			result.push_back(')');
			result.push_back('|');
		}
	}
	result.erase(result.size() - 1, 1);
	return result;
}