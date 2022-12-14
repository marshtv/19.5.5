#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool sector_check(std::vector<int> sectors_complete, int sector) {
	for (int i = 0; i < sectors_complete.size(); ++i) {
		if (sector == sectors_complete[i])
			return true;
	}
	return false;
}

int main() {
	std::ifstream questions;
	questions.open("F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\_questions.txt");

	std::vector<int> sectors_complete;
	int offset;
	int sector_count = 13;
	int sector = 1;
	while (sector_count != 0) {
		std::cout << "To define a sector type the offset from current position of drum (from 1 to 12):" << std::endl;
		std::cin >> offset;
		sector += offset;
		if (sector > 13) sector -= 13;
		int count = sector_count;
		while (sector_check(sectors_complete, sector) || count > 0) {
			sector++;
			count--;
		}

		sector_count--;
	}

	questions.close();

	return 0;
}
