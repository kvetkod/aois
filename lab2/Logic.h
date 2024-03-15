#pragma once
#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

class Logic
{
private:
	int atomar_formula = 0;
	vector<bool> index_form;
	vector<int> numeric_form0;
	vector<int> numeric_form1;
	string sknf, sdnf;
	int col, rows;
	string atomar;
	bool** table;
	int cols(string formula);
	bool conjunction(bool first, bool second);
	bool disjunction(bool first, bool second);
	bool implication(bool first, bool second);
	bool denial(bool first);
	bool equivalence(bool first, bool second);
	void solve(string formula, int& index, int rows);
public:
	~Logic();
	void table_of_truth(string formula);
	void print_table();
	void IndexForm();
	void NumericForm();
	void PrintIndexForm();
	void PrintNumericForm();
	void SKNF();
	void SDNF();
};

