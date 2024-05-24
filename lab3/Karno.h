#pragma once
#include<vector>
#include<utility>
#include<iostream>
#include<cmath>
using namespace std;



class Karno
{
private:
	string atomar;
	vector<string>formulas;
	vector<vector<bool>>table;
	vector<string> answer;
	int row, col;
	bool sknf, sdnf;
	bool** result;
	vector<string> rows;
	vector<string> cols;
	vector<vector<pair<int, int>>> squares;
	vector<string> CreateString(int count);
	bool Check(string);
	bool isAllTrue(const vector<vector<bool>>& table_, int, int, int, int, vector<pair<int, int>>& indices, bool);
	void findAllRectangles(const vector<vector<bool>>& table, bool);
	bool Check(vector<pair<int, int>>, vector<pair<int, int>>, int);
	void Clear();
	void CreateResult(bool);
	string CheckResult(string);
public:
	Karno(string formula, vector<vector<bool>>table_) {
		string short_formula;
		for (int i = 0; i < formula.length(); i++) {
			if (formula[i] == '|') {
				sknf = 1;
				break;
			}
			if (formula[i] == '&') {
				sdnf = 1;
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
		table = table_;
	}
	void KarnoMethod();


};

