#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;


class MinimizationTable
{
private:
	vector<string> formulas;
	bool sknf = 0, sdnf = 0;
	vector<string> Merge(vector<string>, bool);//
	string SameFormula(string, string);//
	bool Check(string formula1, string formula2);
	void Sort(vector<string>& formulas);
	bool FindIndex(vector<int>, int);
	void VerifyTheTable(vector<vector<bool>>&, int, vector<string>&);
	bool OccurrenceOfTheElement(vector<vector<bool>>, int, int);
	vector<int> FindDenial(string);
	vector<string> Gluing(vector<string>);
public:

	MinimizationTable(string formula);
	void TableMethod();
	void Minimization();
};

