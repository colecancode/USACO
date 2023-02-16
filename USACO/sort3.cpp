/*
ID: coledou1
TASK: sort3
LANG: C++
*/

// COLE MILLER
// 12 / 3 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");

    int n; fin >> n;

	// IDEA:
	// number of needed swaps is:
	// number of optimal swaps, i.e. where both numbers go into the right place
	// PLUS
	// number of cycles * 2 (2 swaps needed per cycle)
	//

	vector<int> arr(n), freq(3, 0);

	// count freq and initialize array
	for (int i = 0; i < n; ++i) {
		fin >> arr[i];
		++freq[arr[i]-1];
	}

	// matrix, each index i represents the numbers that are in the section that SHOULD be i+1
	vector<vector<int>> mat(3, vector<int>(3));

	// build matrix
	int idx(0);
	for (int i = 0; i < n; ++i) {
		if (!freq[idx]--) ++idx, --freq[idx];

		++mat[idx][arr[i] - 1];
	}

	// count swaps + cycles
	int swaps = 0, cycles = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (j == i) continue;
			int k = min(mat[i][j], mat[j][i]);
			swaps += k;
			mat[i][j] -= k;
			mat[j][i] -= k;
			if (i == 1) cycles += mat[i][j];
		}
	}

	// write output
	fout << swaps + cycles * 2 << endl;

	return 0;
}

// 2 2 1 3 3 3 2 3 1

// 1 2 2 3 3 3 2 3 1
// ^   ^
// 1 2 2 2 3 3 3 3 1
//       ^     ^
// 1 2 2 2 3 3 3 3 1
//   ^     ^       ^
// 1 cycle = 2 swaps
//
// 2 swaps + 1 cycle * 2 = 4