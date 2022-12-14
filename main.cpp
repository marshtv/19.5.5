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
	int sectors_complete[13] = {0};
	std::ifstream questions;
	questions.open("F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\_questions.txt");

	std::cout << "To define a sector type the offset from current position of drum (from 1 to 12):" << std::endl;
	int offset;
	std::cin >> offset;


	questions.close();
	return 0;
}
