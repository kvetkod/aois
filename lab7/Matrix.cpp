#include "Matrix.h"

void Matrix::Print() {
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

string Matrix::GetWord(int index) {
	if (index < 0 or index > 15) return "error";
	int i = index, j = index;
	string result;
	for (i; i < 16; i++) {
		//for (j; j < 16; j++) {
			if (table[i][j] == 0) result.push_back('0');
			if (table[i][j] == 1) result.push_back('1');
		//}
	}
	if (result.size() < 16) {
		for (i = 0; i < index; i++) {
			if (table[i][j] == 0) result.push_back('0');
			if (table[i][j] == 1) result.push_back('1');
		}
	}
	return result;
}

string Matrix::GetAddress(int index) {
	if (index < 0 or index > 15) return "error";
	int i, j;
	i = index;
	j = 0;
	string result;
	while (i < 16) {
		if (table[i][j] == 0) result.push_back('0');
		if (table[i][j] == 1) result.push_back('1');
		i++; j++;
	}
	if (result.size() < 16) {
		i = 0; 
		while (i < index) {
			if (table[i][j] == 0) result.push_back('0');
			if (table[i][j] == 1) result.push_back('1');
			i++;
			j++;
		}
	}
	return result;
}

void Matrix::SetWord(int index, string word) {
	if (word.size() < 16 or word.size() > 16) {
		cout << "Incorrect size of the word" << endl;
		return;
	}
	int count = 0;
	for (int i = 0; i < 16; i++) {
		if (word[i] == '0' or word[i] == '1') {
			count++;
		}
	}
	if (count != 16) {
		cout << "The wrong word" << endl;
		return;
	}

	int i, j, k;
	i = j = index;
	k = 0;
	for (i; i < 16; i++) {
		if (word[k] == '0') table[i][j] = 0;
		if (word[k] == '1') table[i][j] = 1;
		k++;
	}
	if (index != 0) {
		for (i = 0; i < index; i++) {
			if (word[k] == '0') table[i][j] = 0;
			if (word[k] == '1') table[i][j] = 1;
			k++;
		}
	}
}

void Matrix::SetAddress(int index, string address) {
	if (address.size() < 16 or address.size() > 16) {
		cout << "Wrong size" << endl;
		return;
	}
	int count = 0;
	for (int i = 0; i < 16; i++) {
		if (address[i] == '0' or address[i] == '1') {
			count++;
		}
	}
	if (count != 16) {
		cout << "Wrong address" << endl;
		return;
	}
	int i = index;
	int j = 0;
	while (i < 16) {
		if (address[j] == '0') table[i][j] = 0;
		if (address[j] == '1') table[i][j] = 1;
		i++; j++;
	}
	if (index != 0) {
		i = 0;
		while (i < index) {
			if (address[j] == '0') table[i][j] = 0;
			if (address[j] == '1') table[i][j] = 1;
			i++; j++;
		}
	}
}

void Matrix::LogicFunction1(int index1, int index2, int index3) {
	string word1 = this->GetWord(index1);
	string word2 = this->GetWord(index2);

	string result;
	for (int i = 0; i < 16; i++) {
		if (word1[i] == '1' and word2[i] == '1')
			result.push_back('0');
		else result.push_back('1');
	}
	this->SetWord(index3, result);
}

void Matrix::LogicFunction2(int index1, int index2, int index3) {
	string word1 = this->GetWord(index1);

	string result;
	for (int i = 0; i < 16; i++) {
		if (word1[i] == '0') result.push_back('1');
		if (word1[i] == '1') result.push_back('0');
	}
	this->SetWord(index3, result);
}

void Matrix::Sum(string key) {
	if (key.size() < 3) {
		cout << "Wrong size" << endl;
		return;
	}
	int count = 0;
	for (int i = 0; i < key.size(); i++) {
		if (key[i] == '0' or key[i] == '1') {
			count++;
		}
	}
	if (count != 3) {
		cout << "Wrong key" << endl;
		return;
	}

	string word; int index = -1;
	for (int i = 0; i < 16; i++) {
		count = 0;
		word = this->GetWord(i);
		for (int j = 0; j < 3; j++) {
			if (key[i] == word[i]) count++;
		}
		if (count == 3) { index = i;  break; }
		word.clear();
	}
	if (index == -1) return;
	string first, second;

	for (int i = 3; i < 7; i++) {
		first.push_back(word[i]);
	}
	for (int i = 7; i < 11; i++) {
		second.push_back(word[i]);
	}
	string result; bool flag = false;
	for (int i = 3; i >= 0; i--) {
		if (first[i] == '1' and second[i] == '1') {
			if (flag) {
				result.push_back('1');
				flag = true;
				continue;
			}
			else {
				result.push_back('0');
				flag = true;
				continue;
			}
		}
		if (first[i] == '1' and second[i] == '0') {
			if (flag) {
				result.push_back('0');
				flag = true;
				continue;
			}
			else {
				result.push_back('1');
				continue;
			}
		}
		if (first[i] == '0' and second[i] == '1') {
			if (flag) {
				result.push_back('0');
				flag = true;
				continue;
			}
			else {
				result.push_back('1');
				continue;
			}
		}
		if (first[i] == '0' and second[i] == '0') {
			if (flag) {
				result.push_back('1');
				flag = false;
				continue;
			}
			else {
				result.push_back('0');
				continue;
			}
		}
	}

	if (flag) {
		result = '1' + result;
	}
	else result = '0' + result;

	string new_word = key + first + second + result;
	this->SetWord(index, new_word);

	cout << word << endl;
	cout << first << "  " << second << "  " << result << endl;
	cout << this->GetWord(index);
}
