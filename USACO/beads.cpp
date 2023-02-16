/*
ID: coledou1
TASK: beads
LANG: C++
*/

// COLE MILLER
// 11 / 11 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int n; fin >> n;
	string necklace; fin >> necklace;
	necklace += necklace;


	int mx = 0, i = n;
	// traverse necklace, trying most breakpoints
	while (i >= 0) {
		while (i > 0 && necklace[i + 1] == 'w') --i;

		char lClr = (necklace[i] == 'r') ? 'b' : 'r',
			 rClr = (necklace[i + 1] == 'r') ? 'b' : 'r';

		while (i > 0 && necklace[i] == 'w') --i;

		int cnt = 0, l = i, r = i+1;
		for (; l >= 0; --l) {
			// cant go further
			if (necklace[l] == lClr) {
				while (l < i && necklace[l + 1] == 'w') ++l;
				i = l;
				break;
			}
			++cnt;
		}
		if (l <= 0)
			i--;
		for (; r < 2 * n; ++r) {
			if (necklace[r] == rClr)
				break;
			++cnt;
		}
		if (cnt >= n) {
			fout << n << endl;
			return 0;
		}
		mx = max(mx, cnt);
	}

	if (mx)
		fout << mx << endl;
	else
		fout << n << endl;

	return 0;
}