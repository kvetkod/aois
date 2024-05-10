#include<iostream>
#include<vector>
#include"Minimization.h"
using namespace std;


class Synthesis
{
private:
	vector<vector<bool>> table;
	void Sum(string, int);
	void SKNF();
	string sknf(int);
public:
	void MakeSynthesis();
};

