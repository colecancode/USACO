/*
ID: coledou1
TASK: prefix
LANG: C++
*/

// COLE MILLER
// 1 / 8 / 23

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");

	vector<string> prim;
	string tmp;
	while (fin >> tmp, tmp != ".")
		prim.emplace_back(tmp);

	string seq;
	while (!fin.eof()) {
		string s; fin >> s;
		seq += s;
	}

	int n = seq.size(), m = prim.size(), ans=0;
	vector<bool> good(n+1);
	good[0] = true;
	for (int i = 0; i < n; ++i) {
		if (good[i]) {
			ans = i;
			for (string p : prim) {
				int j;
				for (j=0; j<p.size() && i+j < n && p[j] == seq[i+j]; ++j);
				if (j == p.size())
					good[i + j] = true;
			}
		}
	}
	if (good[n])
		ans = n;

	fout << ans << endl;

	return 0;
}