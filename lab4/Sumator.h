#include<iostream>
#include<vector>
#include"Minimization.h"

using namespace std;


class Sumator {
private:
	vector<vector<bool>> table;
	void SKNF();
	string sknf(int);

public:
	void CreateSumator();

};