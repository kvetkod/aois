#pragma once
#include<iostream>
#include<vector>
using namespace std;


class Matrix
{
private:
	vector<vector<bool>> table;
	bool search(string, string);
public:
	Matrix(vector<vector<bool>> table_): table(table_) {};
	void Print();
	string GetWord(int);
	string GetAddress(int);
	void SetWord(int, string);
	void SetAddress(int, string);
	void LogicFunction1(int, int, int);
	void LogicFunction2(int, int, int);
	void Sum(string);
	void SearchUp(int);
	void SearchDown(int);
};

