#include <iostream>
#include <fstream>
using namespace std;
#define TOP 3

void calcMax(int maxArr[TOP], int sum) {
	for (int i = TOP-1; i >= 0; i--) {
		if (sum > maxArr[i]) {
			if (i < TOP - 1)
				maxArr[i+1] = maxArr[i];
			maxArr[i] = sum;
		}
	}
}

int main() {
	ifstream file;
	string line, last;
	int sum = 0;
	int tot = 0;
	int max[TOP] = {-1};

	file.open("1.txt");

	while (getline(file, line)) {
		if (last == "") {
			calcMax(max, sum);
			sum = 0;
		}
		if (line != "") sum += stoi(line);
		last = line;
	}
	calcMax(max, sum);

	for (int i = 0; i < TOP; i++) {
		tot += max[i];
	}
	cout << max[0] << " " << tot;
	return 0;
}