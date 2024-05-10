#pragma once
#include<iostream>
#include<vector>
#include"Minimization.h"
using namespace std;


class Subtractor
{
private:
	vector<vector<bool>> table;
	void subtractor(int);
	void check(int);
	string sdnf(int);
public:
	void CreateSubtractor();
};

