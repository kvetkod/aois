#include "HashTable.h"


void HashTable::AddElement(string value, string info) {
	int key = static_cast<int>(value[0] + 64) * 33 + static_cast<int>(value[1] + 32);
	Node a(value, info, key);
	int hash;
	hash = key%size;
	if (table[hash].GetKey() != 0 and table[hash].GetValue() != "0") {
		table[hash].SetIsNotOne();
		hash = search(2, hash, key);
		table[hash] = a;
		table[hash].SetTerminalTrue();
		return;
	}
	else 
		table[hash] = a;

}

void HashTable::PrintTable() {
	for (int i = 0; i < size; i++) {
		cout << i+1 <<". " << table[i].GetValue() << " " << table[i].GetInfo() << " " << table[i].GetKey() << " " << table[i].GetTerminal() << endl;
	}
}

int HashTable::search(int h, int index, int key) {
	int i = 1;
	while (true) {
		int hash = index + i * h;
		if (hash >= 20) {
			while (hash >= 20)
				hash -= 20;
		}
		if (table[hash].GetKey() == 0 and table[hash].GetValue() == "0")
			return hash;
		else {
			if (table[hash].GetKey() == key) {
				table[hash].SetIsNotOne();
				table[hash].SetTerminalFalse();
			}
			i++;
		}
	}
}

void HashTable::Update(string v_key, string value, string info) {
	int key = static_cast<int>(v_key[0] + 64) * 33 + static_cast<int>(v_key[1] + 32);
	int hash = key % size;
	if (table[hash].GetKey() != key) cout << "На ключ " << key << " нет ячейки" << endl;
	else if(table[hash].GetKey() == key and table[hash].GetValue() == v_key) {
		if (table[hash].GetIsNotOne()) {
			if (table[hash].GetTerminal()) {
				int j = hash - 2;
				if (table[j].GetKey() == key and table[j].GetIsNotOne()) {
					table[j].SetTerminalTrue();
				}

			}
		}
		Node a(value, info, key);
		table[hash] = a;
	}
	else{
		if (table[hash].GetValue() != v_key and table[hash].GetKey() == key) {
			int i = 1;
			int index = hash;
			while (true) {
				if (i > 20) break;
				index = index + 2 * i;
				if (table[index].GetValue() == v_key) {
					if (table[index].GetIsNotOne()) {
						if (table[index].GetTerminal()) {
							int j = index - 2;
							if (table[j].GetKey() == key and table[j].GetIsNotOne()) {
								table[j].SetTerminalTrue();
							}

						}
					}
					Node a(value, info, key);
					table[index] = a;
					break;
				}
			}
		}
	}
}

void HashTable::Delete(string value) {
	int key = static_cast<int>(value[0] + 64) * 33 + static_cast<int>(value[1] + 32);
	int hash = key % size;
	if (table[hash].GetKey() == 0 and table[hash].GetValue() == "0") {
		cout << "Ячейка пуста" << endl; return;
	}
	else if (table[hash].GetValue() == value)
	{
		Node a("0", "0", 0);
		table[hash] = a;
	}
	else if(table[hash].GetValue() != value and table[hash].GetKey() == key) {
		int i = 1; int h = 2; int index = hash;
		while (true) {
			if (i > 20) break;
			int hash = index + i * h;
			if (hash >= 20) {
				while (hash >= 20)
					hash -= 20;
			}
			if (table[hash].GetKey() == key and table[hash].GetValue() == value)
			{
				if (table[hash].GetTerminal() == true) {
					int j = i-1;
					while (j != 1) {

						if (table[index + j * h].GetKey() == key) {
							table[index + j * h].SetTerminalTrue();
							break;
						}
						else {
							j--;
						}
					}
				}
				Node a("0", "0", 0);
				table[hash] = a;
				return;
			}

			else {
				i++;
			}


		}
	}
}

void HashTable::Read(string value) {
	int key = static_cast<int>(value[0] + 64) * 33 + static_cast<int>(value[1] + 32);
	int hash = key % size;
	if (table[hash].GetKey() == 0 and table[hash].GetValue() == "0") {
		cout << "Пустая ячейка." << endl;
	}
	else {
		if (table[hash].GetValue() == value) {
			cout << table[hash].GetValue() << " " << table[hash].GetInfo() << endl;
		}
		else {
			if (table[hash].GetKey() == key and table[hash].GetIsNotOne()) {
				int i = 1;
				while (true) {
					if (i > 20) break;
					hash = hash + i * 2;
					if (hash >= 20) {
						while (hash >= 20)
							hash -= 20;
					}
					if (table[hash].GetValue() == value) {
						cout << table[hash].GetValue() << " " << table[hash].GetInfo() << endl;
						break;
					}
					i++;
				}
			}
		}
	}
}