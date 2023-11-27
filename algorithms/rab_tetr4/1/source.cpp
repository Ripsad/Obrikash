#include <iostream>
#include <vector>

class HashTable {
private:
	std::vector<int> table;

	int hash(int key) {
		return key % table.size();
	}

public:
	HashTable() : table(7, -1) {}

	void insert(int key)
	{
		int index = hash(key);
		if (table[index] == -1) {
			table[index] = key;
		}
		else {
			int next_index = index;
			while (table[next_index] != -1) {
				next_index = (next_index + 1) % table.size();
			}
			table[next_index] = key;
		}
	}

	void display() {
		for (int i = 0; i < table.size(); ++i) {
			std::cout << i << " --> ";
			if (table[i] != -1) {
				std::cout << table[i] << std::endl;
			}
			else {
				std::cout << std::endl;
			}
		}
	}

};
int main()
{
	HashTable hash_table;
	std::vector<int> numbers = { 86, 90, 21, 29, 39, 38, 40 };
	for (int num : numbers) {
		hash_table.insert(num);
	}

	hash_table.display();

	return 0;
}