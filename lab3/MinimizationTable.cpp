#include "MinimizationTable.h"



MinimizationTable::MinimizationTable(string formula) {
	string short_formula;
	for (int i = 0; i < formula.length(); i++) {
		if (formula[i] == '&') {
			sdnf = 1;
			break;
		}
		if (formula[i] == '|') {
			sknf = 1;
			break;
		}
	}

	for (int i = 0; i < formula.length(); i++) {
		if (formula[i] == '(') {
			short_formula.clear();
			continue;
		}
		if (formula[i] == ')') {
			formulas.push_back(short_formula);
			continue;
		}
		if (formula[i] != '&' and formula[i] != '|') {
			short_formula.push_back(formula[i]);
		}
	}
}


string MinimizationTable::SameFormula(string formula1, string formula2) {
	string formula = "";
	vector<string> formulas1, formulas2;

	for (int i = 0; i < formula1.length(); i++) {
		if (formula1[i] == '!') {
			formula.clear();
			formula.push_back('!');
			formula.push_back(formula1[i + 1]);
			formulas1.push_back(formula);
			i++;
		}
		else {
			formula.clear();
			formula.push_back(formula1[i]);
			formulas1.push_back(formula);
		}
	}

	for (int i = 0; i < formula2.length(); i++) {
		if (formula2[i] == '!') {
			formula.clear();
			formula.push_back('!');
			formula.push_back(formula2[i + 1]);
			formulas2.push_back(formula);
			i++;
		}
		else {
			formula.clear();
			formula.push_back(formula2[i]);
			formulas2.push_back(formula);
		}
	}

	formula.clear();

	for (int i = 0; i < formulas1.size(); i++) {
		for (int j = 0; j < formulas2.size(); j++) {
			if (formulas1[i] == formulas2[j]) {
				for (int k = 0; k < formulas1[i].length(); k++) {
					formula.push_back(formulas1[i][k]);
				}
			}

		}
	}


	return formula;
}

vector<string> MinimizationTable::Merge(vector<string> formulas, bool flag) {
	vector<string> result;
	string formula;


	for (int i = 0; i < formulas.size(); i++) {
		for (int j = i + 1; j < formulas.size(); j++) {
			formula = SameFormula(formulas[i], formulas[j]);
			if (formula.length() != 0) {
				if (formula.length() == 1) {
					if (flag) {
						cout << formulas[i] << " and " << formulas[j] << ": ";
						cout << formula << endl;
						result.push_back(formula); break;
					}
				}
				else {
					cout << formulas[i] << " and " << formulas[j] << ": ";
					cout << formula << endl;
					result.push_back(formula);
				}
			}
		}
	}

	return result;
}


bool MinimizationTable::Check(string formula1, string formula2) {
	int check = 0;
	for (int i = 0; i < formula1.length(); i++) {
		for (int j = 0; j < formula2.length(); j++) {
			if (formula2[j] == formula1[i]) {
				if (formula2[j] != '!') {
					if (i != 0 and j != 0) {
						if (formula1[i - 1] == '!' and formula2[j - 1] == '!') check++;
						else if (formula1[i - 1] != '!' and formula2[j - 1] != '!') check++;
					}
					else if (i == 0 and j == 0) {
						check++;
					}
					else if (i == 0) {
						if (j != 0 and formula2[j - 1] != '!') check++;
					}
					else if (j == 0) {
						if (i != 0 and formula1[i - 1] != '!') check++;
					}
				}
				else {
					i++;
					if (formula2[j + 1] == formula1[i]) {
						check += 2;
						break;
					}
				}
			}
		}
	}

	if (check == formula2.size()) return true;
	else return false;
}


void MinimizationTable::Sort(vector<string>& formulas) {
	for (int i = 0; i < formulas.size(); i++) {
		for (int j = i + 1; j < formulas.size(); j++) {
			if (formulas[i] == formulas[j]) {
				formulas.erase(formulas.begin() + j);
				j--;
			}
		}
	}
}


void MinimizationTable::VerifyTheTable(vector<vector<bool>>& table, int cols, vector<string> &formula) {

	int count = 0, expected = 0;
	for (int i = 0; i < table.size(); i++) {
		vector<bool> for_check = table[i]; count = 0; expected = 0;

		for (int j = 0; j < for_check.size(); j++) {
			if (for_check[j] == 1) {
				expected++;
				if (OccurrenceOfTheElement(table, i, j)) {
					count++;
					continue;
				}
			}
		}

		if (expected == count) {
			formula.erase(formula.begin() + i);
			table.erase(table.begin() + i);
			i--;
		}
	}
}


bool MinimizationTable::OccurrenceOfTheElement(vector<vector<bool>> table, int index, int col) {
	for (int i = 0; i < table.size(); i++) {
		if (i != index) {
			if (table[i][col] == 1) {
				return true;
			}
		}
	}
	return false;
}


void MinimizationTable::TableMethod() {
	vector<string> s_formulas, helper = formulas;
	vector<int> index = FindDenial(helper[0]);
	int size = helper[0].size();
	for (int i = 0; i < size - index.size(); i++) {
		s_formulas = Gluing(helper);
		helper = s_formulas;
	}



	int rows = s_formulas.size();
	int cols = formulas.size();

	vector<vector<bool>> table;

	for (int i = 0; i < rows; i++) {
		vector<bool> for_table;
		for (int j = 0; j < cols; j++) {
			for_table.push_back(Check(formulas[j], s_formulas[i]));
		}
		table.push_back(for_table);
	}

	for (int i = 0; i < formulas.size(); i++) {
		cout << " " << formulas[i];
	}
	cout << endl;

	for (int i = 0; i < table.size(); i++) {
		cout << s_formulas[i];
		for (int j = 0; j < cols; j++) {
			cout << "  " << table[i][j];
		}
		cout << endl;
	}



	VerifyTheTable(table, cols, s_formulas);

	for (int i = 0; i < formulas.size(); i++) {
		cout << " " << formulas[i];
	}
	cout << endl;

	for (int i = 0; i < table.size(); i++) {
		cout << s_formulas[i];
		for (int j = 0; j < cols; j++) {
			cout << "  " << table[i][j];
		}
		cout << endl;
	}
}


bool MinimizationTable::FindIndex(vector<int> index, int i) {
	if (index.size() == 0) return true;
	for (int j = 0; j < index.size(); j++) {
		if (i == index[j]) return false;
	}
	return true;
}

vector<int> MinimizationTable::FindDenial(string formula) {
	vector<int> index;
	for (int i = 0; i < formula.length(); i++) {
		if (formula[i] == '!') {
			index.push_back(i);
		}
	}

	return index;
}

vector<string> MinimizationTable::Gluing(vector<string> formula) {
	vector<string> s_formula;
	vector<int> index;
	bool flag = true;
	for (int i = 0; i < formula.size(); i++) {
		vector<int> places = FindDenial(formula[i]); int place;
		for (int p = 0; p < places.size(); p++) {
			place = places[p];
			string to_find;
			char element = formula[i][place + 1];
			for (int j = 0; j < formula[i].length(); j++) {
				if (j != place) {
					to_find.push_back(formula[i][j]);
				}
			}
			for (int j = 0; j < formula.size(); j++) {
				if (j != i) {
					if (formula[j] == to_find) {
						string new_formula;
						for (int k = 0; k < to_find.length(); k++) {
							if (to_find[k] != element) {
								new_formula.push_back(to_find[k]);
							}
						}
						flag = false;
						cout << formula[i] << " and " << formula[j] << ": ";
						cout << new_formula << endl;
						s_formula.push_back(new_formula);
						index.push_back(i);
						index.push_back(j);
					}
				}
			}
		}

	}


	for (int i = 0; i < formula.size(); i++) {
		if (FindIndex(index, i)) {
			s_formula.push_back(formula[i]);
		}
	}

	Sort(s_formula);


	if (!flag) {
		cout << "result: ";
		for (int i = 0; i < s_formula.size(); i++) {
			cout << s_formula[i] << " ";
		}
		cout << endl;


		cout << endl;
	}
	return s_formula;
}


void MinimizationTable::Minimization() {
	vector<string> s_formulas, helper = formulas;
	vector<int> index = FindDenial(helper[0]);
	int size = helper[0].size();
	for (int i = 0; i < size - index.size(); i++) {
		s_formulas = Gluing(helper);
		helper = s_formulas;
	}



}