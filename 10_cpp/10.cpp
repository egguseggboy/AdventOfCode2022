#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream file;
	file.open("10.txt");

	std::string line;
	int cycles = 0, add = 1, sum = 0;
	int x = 0, y = 0;
	char CRT[40][6];

	while (getline(file, line)) {
		bool spaceFound = line.find(' ') != std::string::npos;
		int loops = spaceFound ? 2 : 1;

		while (loops-- > 0) {
			if ((++cycles + 20) % 40 == 0)
				sum += add * cycles;

			x = (cycles - 1) % 40;
			y = (cycles - 1) / 40;
			CRT[x][y] = (x == add-1 || x == add || x == add+1) ? '#' : ' ';
		}

		if (spaceFound)
			add += stoi(line.substr(line.find(' ')));
	}

	std::cout << sum;

	for (int i = 0; i < 6; i++) {
		std::cout << "\n";

		for (int j = 0; j < 40; j++) {
			std::cout << CRT[j][i];
		}
	}

	file.close();
	return 0;
}