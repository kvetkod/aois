#include "Karno.h"


void Karno::KarnoMethod() {
	int count = 0;
	for (int i = 0; i < formulas[0].size(); i++) {

		if (formulas[0][i] != '!') {
			count++;
			atomar.push_back(formulas[0][i]);
		}
	}

	int length, width;

	if (count % 2 == 0) {
		length = count / 2; width = count / 2;
	}
	else {
		width = count / 2;
		length = count - width;
	}

	vector<string> new_formulas;
	string form; int i;
	for (i = 0; i < width; i++) {
		form.push_back(atomar[i]);
	}
	new_formulas.push_back(form);

	form = "";
	for (i; i < width + length; i++) {
		form.push_back(atomar[i]);
	}
	new_formulas.push_back(form);

	formulas = new_formulas;

	row = pow(2, width);
	col = pow(2, length);

	

	rows = CreateString(row);
	cols = CreateString(col);

	result = new bool* [row];
	for (i = 0; i < row; i++) {
		result[i] = new bool[col];
	}
	for (i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result[i][j] = 0;
		}
	}

	for (i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			string for_result;
			for_result += rows[i];
			for_result += cols[j];
			result[i][j] = Check(for_result);
		}
	}



	vector<vector<bool>> _table;
	for (int i = 0; i < row; i++) {
		vector<bool> newtable;
		for (int j = 0; j < col; j++) {
			newtable.push_back(result[i][j]);
		}
		_table.push_back(newtable);
	}

	for (int i = 0; i < _table.size(); i++) {
		for (int j = 0; j < _table[i].size(); j++) {
			cout << _table[i][j];
		}
		cout << endl;
	}



	if (sknf) findAllRectangles(_table, 0);
	else if (sdnf) findAllRectangles(_table, 1);


	Clear();

	if (sknf) CreateResult(0);
	if (sdnf) CreateResult(1);
}

void Karno::CreateResult(bool flag) {
	char sign;
	if (flag == 0) sign = '1';
	else sign = '0';

	for (int i = 0; i < squares.size(); i++) {
		string first, second;
		for (int j = 0; j < squares[i].size(); j++) {
			for (int k = 0; k < rows[squares[i][j].first].size(); k++) {
				if (rows[squares[i][j].first][k] == sign)
				{
					first.push_back('!');
					first.push_back(formulas[0][k]);
				}
				else first.push_back(formulas[0][k]);
			}
			for (int k = 0; k < cols[squares[i][j].second].size(); k++) {
				if (cols[squares[i][j].second][k] == sign)
				{
					second.push_back('!');
					second.push_back(formulas[1][k]);
				}
				else second.push_back(formulas[1][k]);
			}
		}
		string result = first + second;

		result = CheckResult(result);
		int count = 0;
		for (int k = 0; k < answer.size(); k++) {
			if (answer[k] != result) count++;
		}
		if(count == answer.size())
			answer.push_back(result);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
		if (i != answer.size() - 1) {
			if (sknf) cout << " and ";
			if (sdnf) cout << " or ";
		}
	}
}


string Karno::CheckResult(string res) {
	vector<string> new_result;

	for (int i = 0; i < res.size(); i++) {
		string word;
		if (res[i] == '!') {
			word.push_back('!');
			word.push_back(res[i+1]);
			i++;
		}
		else word.push_back(res[i]);
		int count = 0;
		for (int j = 0; j < new_result.size(); j++) {
			if (new_result[j] != word) {
				count++;
			}
		}
		if(count == new_result.size())
			new_result.push_back(word);
	}

	for (int i = 0; i < new_result.size(); i++) {
		for (int j = 0; j < new_result.size(); j++) {
			if (i != j) {
				if (new_result[i].size() == 1 and new_result[j].size() == 2) {
					if (new_result[i][0] == new_result[j][1]) {
						new_result.erase(new_result.begin() + i);
						new_result.erase(new_result.begin() + j - 1);
						i --; j--;
						break;
					}
				}
				if (new_result[j].size() == 1 and new_result[i].size() == 2) {
					if (new_result[j][0] == new_result[i][1]) {
						new_result.erase(new_result.begin() + i);
						new_result.erase(new_result.begin() + j - 1);
						i --; j--;
						break;
					}
				}
			}
		}
	}

	string result = "";
	for (int i = 0; i < new_result.size(); i++) {
		result += new_result[i];
	}
	return result;
}

vector<string> Karno::CreateString(int count) {
	vector<string> cols;
	if (count == 2) {
		cols = { "0", "1" };
		return cols;
	}

	if (count == 4) {
		cols = { "00", "01", "11", "10" };
	}

	if (count == 8) {
		cols = { "000", "001", "011", "010", "110", "111", "101", "100" };
	}

	return cols;
}


bool Karno::Check(string formula) {
	vector<bool> checker;

	for (int i = 0; i < formula.length(); i++)
	{
		if (formula[i] == '1') checker.push_back(1);
		if (formula[i] == '0') checker.push_back(0);
	}


	for (int i = 0; i < table.size(); i++) {
		int count = 0;
		for (int j = 0; j < checker.size(); j++)
		{
			if (checker[j] == table[i][j]) {
				count++;
			}
		}

		if (count == checker.size())
			return table[i][table[i].size() - 1];
	}
}

bool Karno::isAllTrue(const vector<vector<bool>>& table, int row, int col, int height, int width, vector<pair<int, int>>& indices, bool flag) {
	int rows = table.size();
	int cols = table[0].size();
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int wrappedRow = (row + i) % rows;
			int wrappedCol = (col + j) % cols;
			if (table[wrappedRow][wrappedCol] != flag) return false;
			pair<int, int> new_pair = make_pair(wrappedRow, wrappedCol);
			int count = 0;
			for (int k = 0; k < indices.size(); k++) {
				if (indices[k] != new_pair) count++;
			}
			if(count == indices.size())
				indices.emplace_back(wrappedRow, wrappedCol); 
		}
	}
	return true;
}


void Karno::findAllRectangles(const vector<vector<bool>>& table, bool flag) {
	int rows = table.size();
	if (rows == 0) return;
	int cols = table[0].size();


	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			for (int area = 1; area <= rows * cols; area *= 2) {
				for (int height = 1; height <= rows; ++height) {
					if (area % height == 0) {
						int width = area / height;
						vector<pair<int, int>> indices;
						if (isAllTrue(table, row, col, height, width, indices, flag)) {
							squares.push_back(indices);  
						}
					}
				}
			}
		}
	}
}

bool Karno::Check(const vector<pair<int, int>> line1, const vector<pair<int, int>> line2, int index) {
	if (index == -1) {
		for (const auto& elem2 : line2) {
			bool found = false;
			for (const auto& elem1 : line1) {
				if (elem2 == elem1) {
					found = true;
					break;
				}
			}
			if (!found) return false;
		}
		return true;
	}
	else {
		for (int i = 0; i < squares.size(); i++) {
			if (i != index) {
				int count = 0;
				for (const auto& elem2 : line2) {
					for (const auto& elem : squares[i]) {
						if (elem2 == elem) {
							count++;
							break;
						}
					}
				}
				if (count >= line2.size()) return true;
			}
		}
	}
	return false;
}

void Karno::Clear() {
	for (int i = 0; i < squares.size(); i++) {
		for (int j = 0; j < squares.size(); j++) {
			if (i != j) {
				if (squares[i].size() == squares[j].size()) {
					if (Check(squares[i], squares[j], -1)) {
						squares.erase(squares.begin() + j);
						j--;
						if (i > j) i--; 
					}
				}
				else if (squares[i].size() > squares[j].size() && Check(squares[i], squares[j], -1)) {
					squares.erase(squares.begin() + j);
					j--;
				}
				else if (squares[j].size() > squares[i].size() && Check(squares[j], squares[i], -1)) {
					squares.erase(squares.begin() + i);
					i--;
					break;
				}
			}
		}
	}

	for (int i = 0; i < squares.size(); i++) {
		if (Check(squares[i], squares[i], i)) {
			squares.erase(squares.begin() + i);
			i--;
		}
	}
}
