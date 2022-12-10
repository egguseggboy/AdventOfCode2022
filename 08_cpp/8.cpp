#include <iostream>
#include <fstream>
#define SIZE 99

int main() {
	std::ifstream file;
	file.open("8.txt");

	int trees[SIZE][SIZE], seen[SIZE][SIZE] = {0};
	int x = 0, y = 0;
	std::string line;

	while (getline(file, line)) {
		x = 0;
		for (int i = 0; i < line.length(); i++) {
			trees[x++][y] = int(char(line[i])) - 48;
		}
		y++;
	}

	int lCount = 0, rCount = 0, uCount = 0, dCount = 0;
	int score = 0, maxScore = 0;
	
	for (int i = 0; i < SIZE; i++) {
		int lMax = -1, rMax = -1, uMax = -1, dMax = -1;
		for (int j = 0; j < SIZE; j++) {
			// PART 1
			int lCurr = trees[j][i];
			int rCurr = trees[SIZE-1-j][i];
			int uCurr = trees[i][j];
			int dCurr = trees[i][SIZE-1-j];

			if (lCurr > lMax) {
				lMax = lCurr;
				if (seen[j][i] == 0) {
					lCount++;
					seen[j][i] = 1;
				}
			}
			if (rCurr > rMax) {
				rMax = rCurr;
				if (seen[SIZE-1-j][i] == 0) {
					rCount++;
					seen[SIZE-1-j][i] = 1;
				}
			}
			if (uCurr > uMax) {
				uMax = uCurr;
				if (seen[i][j] == 0) {
					uCount++;
					seen[i][j] = 1;
				}
			}
			if (dCurr > dMax) {
				dMax = dCurr;
				if (seen[i][SIZE-1-j] == 0) {
					dCount++;
					seen[i][SIZE-1-j] = 1;
				}
			}

			// PART 2
			int lView = 0, rView = 0, uView = 0, dView = 0;
			int height = trees[i][j], xInd = i, yInd = j;

			while(--xInd >= 0) {
				lView++;
				if (trees[xInd][j] >= height)
					break;
			}
			xInd = i;
			while(++xInd < SIZE) {
				rView++;
				if (trees[xInd][j] >= height)
					break;
			}
			while(--yInd >= 0) {
				uView++;
				if (trees[i][yInd] >= height)
					break;
			}
			yInd = j;
			while(++yInd < SIZE) {
				dView++;
				if (trees[i][yInd] >= height)
					break;
			}

			score = lView * rView * uView * dView;
			if (score > maxScore)
				maxScore = score;
		}
	}

	std::cout << lCount + rCount + uCount + dCount << "\n" << maxScore;

	file.close();
	return 0;
}