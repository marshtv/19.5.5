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

std::string answer_define(int sector) {
	std::string answer_file_path, answer_str;
	switch (sector) {
		case 1:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_1.txt";
			break;
		case 2:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_2.txt";
			break;
		case 3:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_3.txt";
			break;
		case 4:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_4.txt";
			break;
		case 5:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_5.txt";
			break;
		case 6:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_6.txt";
			break;
		case 7:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_7.txt";
			break;
		case 8:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_8.txt";
			break;
		case 9:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_9.txt";
			break;
		case 10:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_10.txt";
			break;
		case 11:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_11.txt";
			break;
		case 12:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_12.txt";
			break;
		case 13:
			answer_file_path = "F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\answer_13.txt";
			break;
	}
	std::ifstream answer_file;
	answer_file.open(answer_file_path);
	answer_file >> answer_str;
	answer_file.close();
	return answer_str;
}

int main() {
	std::ifstream questions_file;
	questions_file.open("F:\\__C++\\Skillbox\\19\\19.5.5\\Files\\_questions.txt");

	std::vector<int> sectors_complete;
	int round = 1;
	int offset;
	int sector_count = 13;
	int sector = 1;
	int sector_pos = sector;
	std::string question;
	std::string answer, answer_user;
	int points_user = 0, points_tv_viewer = 0;

	std::cout << "*********************************************************************************" << std::endl;
	while (sector_count != 0) {
		std::cout << "Round " << round << std::endl;
		std::cout << "*********************************************************************************" << std::endl;
		std::cout << "To define a sector, type the offset from current position of drum (from 0 to 12):" << std::endl;
		std::cin >> offset;
		sector_pos += offset;
		if (sector_pos > 13)
			sector_pos -= 13;

		int check_count = sector_count;
		while (sector_check(sectors_complete, sector_pos) && check_count > 0) {
			sector_pos++;
			check_count--;
		}
		if (check_count == 0)
			break;
		sectors_complete.push_back(sector_pos);

		std::cout << "*********************************************************************************" << std::endl;
		questions_file.seekg(0);
		for (int i = 1; i <= sector_pos; ++i) {
			questions_file >> sector;
			std::getline(questions_file, question);
		}
		std::cout << "Sector " << sector << ":" << std::endl;
		std::cout << "Question:" << std::endl;
		std::cout << question << std::endl;
		std::cout << "Your Answer:" << std::endl;
		std::cin >> answer_user;

		if (answer_define(sector) == answer_user) {
			points_user += 1;
			std::cout << "Answer is right!" << std::endl;
			std::cout << "One point goes to Expert!" << std::endl;
		} else {
			points_tv_viewer += 1;
			std::cout << "Sorry, but answer is not right!" << std::endl;
			std::cout << "Right answer is:" << std::endl;
			std::cout << answer_define(sector) << std::endl;
			std::cout << "One point goes to TV viewers!" << std::endl;
		}

		std::cout 	<< "Current score: Expert - " << points_user
					<< ", TV viewers - " << points_tv_viewer << std::endl;

		sector_pos++;
		sector_count--;
		round++;
		std::cout << "We goes to next round!!" << std::endl;
		std::cout << "*********************************************************************************" << std::endl;
	}

	std::cout 	<< "Game is over!" << std::endl;
	std::cout 	<< "Final score: Expert - " << points_user
				<< ", TV viewers - " << points_tv_viewer << std::endl;
	if (points_user > points_tv_viewer)
		std::cout 	<< "Winner is Expert!" << std::endl;
	else
		std::cout 	<< "Winner is TV viewers!" << std::endl;

	questions_file.close();

	return 0;
}
