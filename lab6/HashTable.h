#pragma once
#include"Node.h"
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


class HashTable
{
private:
	int size = 20;
	vector<Node> table;
	int search(int h, int index, int key);
public:
	HashTable(int) {
		for (int i = 0; i < size; i++) {
			Node a("0", "0", 0);
			table.push_back(a);
		}
	};
	void AddElement(string, string);
	void PrintTable();
	void Update(string, string, string);
	void Delete(string);
	void Read(string);
};


