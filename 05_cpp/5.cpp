#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<char> stacks[9], tempStacks[9];

void printStacks() {
	for (int i = 0; i < 9; i++) {
		cout << stacks[i].back();
	}
}

void startStack(string line) {
	for (int i = 0; i < line.length(); i++) {
		if ((i + 3) % 4 == 0 && line[i] != ' ') {
			stacks[i / 4].push_back(line[i]);
		}
	}
}

void SOLUTION(int part) {
	ifstream f;
	f.open("5.txt");

	string line;
	int count = 1;
	bool reversed = false;

	while (getline(f, line)) {
		if (count++ < 9)
			startStack(line);
		else if (!reversed) {
			for (int i = 0; i < 9; i++) {
				reverse(stacks[i].begin(), stacks[i].end());
			}
			reversed = true;
		} else if (line[0] == 'm') {
			stringstream ss(line);
			string token;
			vector<string> tokens;
			int move, from, to;

			while (getline(ss, token, ' ')) {
				tokens.push_back(token);
			}

			move = stoi(tokens[1]);
			from = stoi(tokens[3]) - 1;
			to = stoi(tokens[5]) - 1;
			
			if (part == 1) {
				// PART 1
				while (move-- > 0 && stacks[from].size() > 0) {
					char c = stacks[from].back();
					stacks[to].push_back(c);
					stacks[from].pop_back();
				}
			} else if (part == 2) {
				// PART 2
				int moveTemp = move;
				while (move-- > 0 && stacks[from].size() > 0) {
					char c = stacks[from].back();
					tempStacks[to].push_back(c);
					stacks[from].pop_back();
				}
				while (moveTemp-- > 0 && tempStacks[to].size() > 0) {
					char c = tempStacks[to].back();
					stacks[to].push_back(c);
					tempStacks[to].pop_back();
				}
			}
		}
	}
	printStacks();
	f.close();
}
int main() {
	SOLUTION(1);
	SOLUTION(2);
	return 0;
}