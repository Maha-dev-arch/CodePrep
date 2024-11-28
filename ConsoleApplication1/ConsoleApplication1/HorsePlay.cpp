#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define MAX_RANK_FILE 8

int main() {
	string input;
	cin >> input;
	vector<string> output;

	int rank = input.at(1) - '0';
	int file = input.at(0) - 'a' + 1;

	/* 
	** 8 max ways to traverse for horse. 4 directions and 2 ways in each direction.
	** In each direction, 3 steps horizontal and 2 steps vertical and vice versa.
	**  2*4 max ways.
	*/
	for (int j = 1; j <= 2; j++) {
		int rankIncr;
		int fileIncr;
		if (j == 1) {
			rankIncr = 1;
			fileIncr = 2;
		}
		else
		{
			rankIncr = 2;
			fileIncr = 1;
		}
		int directions = 1;
		while (directions <= 4) {
			int newRank;
			int newFile;
			char newRankChar[2] = {'\0'};
			char newFileChar;
			string newPos = "  ";

			switch(directions++) {
			case 1:

				newRank = rank + rankIncr;
				newFile = file + fileIncr;
				if (newRank <= MAX_RANK_FILE && newRank >= 1 && newFile <= MAX_RANK_FILE && newFile >= 1) {
					newPos[0] = newFile + 'a' - 1;
					newPos[1] = newRank + '0';
					output.push_back(newPos);
				}
				break;

			case 2:

				newRank = rank - rankIncr;
				newFile = file - fileIncr;
				if (newRank <= MAX_RANK_FILE && newRank >= 1 && newFile <= MAX_RANK_FILE && newFile >= 1) {
					newPos[0] = newFile + 'a' - 1;
					newPos[1] = newRank + '0';
					output.push_back(newPos);
				}
				break;

			case 3:

				newRank = rank + rankIncr;
				newFile = file - fileIncr;
				if (newRank <= MAX_RANK_FILE && newRank >= 1 && newFile <= MAX_RANK_FILE && newFile >= 1) {
					newPos[0] = newFile + 'a' - 1;
					newPos[1] = newRank + '0';
					output.push_back(newPos);
				}
				break;

			case 4:

				newRank = rank - rankIncr;
				newFile = file + fileIncr;
				if (newRank <= MAX_RANK_FILE && newRank >= 1 && newFile <= MAX_RANK_FILE && newFile >= 1) {
					newPos[0] = newFile + 'a' - 1;
					newPos[1] = newRank + '0';
					output.push_back(newPos);
				}
				break;

			}
		}
	}

	for (string str : output)
		cout << str << endl;
	return 0;
}