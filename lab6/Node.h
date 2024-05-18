#pragma once
#include<iostream>
using namespace std;


class Node
{
private:
	int key;
	string value;
	string info;
	bool isNotOne = false;
	bool terminal = false;
public:
	//Node();
	Node(string value, string info, int key) : key(key), value(value), info(info) {};
	string GetValue() {
		return value;
	}
	string GetInfo() {
		return info;
	}
	int GetKey() {
		return key;
	}
	void SetIsNotOne() {
		isNotOne = true;
	}
	void SetTerminalTrue() {
		this->terminal = true;
	}
	void SetTerminalFalse() {
		terminal = false;
	}
	bool GetTerminal() {
		return terminal;
	}
	bool GetIsNotOne() {
		return isNotOne;
	}
};