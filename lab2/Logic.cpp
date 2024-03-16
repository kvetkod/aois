#include "Logic.h"


int Logic::cols(string formula) {
	string letters = "";
	int count = 0;

	for (int i = 0; i < formula.length(); i++) {
		if (formula[i] == '>') continue;
		if (formula[i] == '!' or formula[i] == '|' or formula[i] == '&' or formula[i] == '~' or formula[i] == '-') {
			count++;
		}
		else if (formula[i] == ')' or formula[i] == '(') continue;
		else {
			if (letters.length() == 0)
			{
				atomar.push_back(formula[i]);
				atomar_formula++;
				count++;
			}
			else {
				int ii;
				for (ii = 0; ii < letters.length(); ii++) {
					if (letters[ii] == formula[i]) break;
				}
				if (ii == letters.length() - 1) {
					atomar.push_back(formula[i]);
					atomar_formula++;
					count++;
					letters.push_back(formula[i]);
				}
			}
		}

	}

	return count;
}


bool Logic::conjunction(bool first, bool second) {
	if (first == 1 and second == 1) return 1;
	else return 0;
}

bool Logic::disjunction(bool first, bool second) {
	if (first == 0 and second == 0) return 0;
	else return 1;
}

bool Logic::denial(bool first) {
	if (first == true) return 0;
	else return 1;
}

bool Logic::equivalence(bool first, bool second) {
	if (first == 1 and second == 1) return 1;
	if (first == 0 and second == 0) return 1;
	else return 0;
}

bool Logic::implication(bool first, bool second) {
	if (second == 1) return 1;
	else {
		if (first == 1) return 0;
		if (first == 0) return 1;
	}
}


void Logic::solve(string formula, int& index, int rows) {
	char first, second;
	if (formula.length() < 3) {
		int i1;
		for (int i = 0; i < atomar.length(); i++) {
			for (int ii = 0; ii < formula.length(); ii++) {
				if (formula[ii] == atomar[i]) i1 = i;
			}
		}
		for (int j = 0; j < rows; j++) {
			table[j][index] = denial(table[j][i1]);
		}
	}
	else if(formula.length() == 3) {
		first = formula[0]; second = formula[2];
		int i1, i2;
		for (int i = 0; i < atomar.length(); i++) {
			if (first == atomar[i]) i1 = i;
			if (second == atomar[i]) i2 = i;
		}
		if (formula[1] == '|') {
			for (int j = 0; j < rows; j++) {
				table[j][index] = disjunction(table[j][i1], table[j][i2]);
			}
		}
		if (formula[1] == '&') {
			for (int j = 0; j < rows; j++) {
				table[j][index] = conjunction(table[j][i1], table[j][i2]);
			}
		}
		if (formula[1] == '~') {
			for (int j = 0; j < rows; j++) {
				table[j][index] = equivalence(table[j][i1], table[j][i2]);
			}
		}
	}
	else if (formula.length() == 4) {
		first = formula[0]; second = formula[3];
		int i1, i2;
		for (int i = 0; i < atomar.length(); i++) {
			if (first == atomar[i]) i1 = i;
			if (second == atomar[i]) i2 = i;
		}
		for (int j = 0; j < rows; j++) {
			table[j][index] = implication(table[j][i1], table[j][i2]);
		}

	}


	index++;
}



void Logic::TableOfTruth(string formula) {
	col = cols(formula); 
	rows = pow(2, atomar_formula); 
	

	table = new bool* [rows];
	for (int i = 0; i < rows; i++) {
		table[i] = new bool[col];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < col; j++) {
			table[i][j] = 0;
		}
	}
	int j = 0, rows1 = rows / 2, count = 0;
	while (j < atomar_formula) {
		count = 1;
		for (int i = 0; i < rows; i++) {
			for (i; i < rows1*count; i++) {
				table[i][j] = 0;
			}
			count++;
			for (i; i < rows1*count; i++) {
				table[i][j] = 1;
			}
			count++;
		}
		j++;
		rows1 = rows1 / 2;
	}

	int index = -1; count = 0;
	string formula1;
	index = formula.find('!');

	while (index!=-1) {
		
		if (formula[index + 1] != '(') {
			count++;
			formula1.push_back('!');
			formula1.push_back(formula[index + 1]);
			formula.erase(index + 1, 1);
			formula[index] = static_cast<char>(count + '0');
			atomar.push_back(static_cast<char>(count+'0'));
			solve(formula1, j, rows);
		}
		formula1.clear();
		index = formula.find('!');
	}

	int count1 = count;
	count = 0;

	for (int i = 0; i < formula.length(); i++) {
		if (formula.length() == 0) break;
		if (formula[i] == '(') {
			formula1.clear();
			count = 0;
			continue;
			
		}
		if (formula[i] != ')') {
			formula1.push_back(formula[i]);
			count++;
			continue;
		}
		if (formula[i] == ')') {
			count1++;
			atomar.push_back(static_cast<char>(count1+'0'));
			for (int ii = i - count; ii < i; ii++) {
				formula.erase(ii, 1);
				i--;
				ii--;
			}
			formula.erase(i, 1);
			formula[i - 1] = atomar[atomar.length() - 1];
			solve(formula1, j, rows);
			i = -1;

		}
	}
}


void Logic::PrintTable() {
	cout << atomar << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < col; j++) {
			cout << table[i][j];
		}
		cout << endl;
	}

}

Logic::~Logic() {
	for (int i = 0; i < rows; i++) {
		delete[] table[i];
	}
	delete[] table;
}


void Logic::IndexForm() {
	int j = col - 1;
	for (int i = 0; i < rows; i++) {
		index_form.push_back(table[i][j]);
	}

}

void Logic::NumericForm() {
	if (index_form.empty()) IndexForm();

	for (int i = 0; i < index_form.size(); i++) {
		if (index_form[i] == 0) {
			numeric_form_sknf.push_back(i);
		}
		else numeric_form_sdnf.push_back(i);
	}


}

void Logic::PrintIndexForm() {
	for (int i = 0; i < index_form.size(); i++) {
		cout << index_form[i];
	}
	cout << endl;
}


void Logic::PrintNumericForm() {
	for (int i = 0; i < numeric_form_sknf.size(); i++) {
		cout << numeric_form_sknf[i] << " ";
	}
	cout << '&' << endl;
	for (int i = 0; i < numeric_form_sdnf.size(); i++) {
		cout << numeric_form_sdnf[i] << " ";
	}
	cout << "|" << endl;
}

void Logic::SKNF() {
	if (numeric_form_sknf.size() == 0) NumericForm();

	for (int i = 0; i < numeric_form_sknf.size(); i++) {
		sknf.push_back('(');
		for (int j = 0; j < atomar_formula; j++) {
			if (table[numeric_form_sknf[i]][j] == 1) {
				sknf.push_back('!');
			}
			sknf.push_back(atomar[j]);
			if (j != atomar_formula-1) sknf.push_back('|');
		}
		sknf.push_back(')');
		if (i != numeric_form_sknf.size()-1) sknf.push_back('&');
	}


	cout << sknf << endl;
}

void Logic::SDNF() {
	if (numeric_form_sdnf.size() == 0) NumericForm();

	for (int i = 0; i < numeric_form_sdnf.size(); i++) {
		sdnf.push_back('(');
		for (int j = 0; j < atomar_formula; j++) {
			if (table[numeric_form_sdnf[i]][j] == 0) {
				sdnf.push_back('!');
			}
			sdnf.push_back(atomar[j]);
			if (j != atomar_formula - 1) sdnf.push_back('&');
		}
		sdnf.push_back(')');
		if (i != numeric_form_sdnf.size() - 1) sdnf.push_back('|');
	}


	cout << sdnf << endl;
}