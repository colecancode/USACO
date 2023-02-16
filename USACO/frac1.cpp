/*
ID: coledou1
TASK: frac1
LANG: C++
*/

// COLE MILLER
// 12 / 3 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");

	int n; fin >> n;

	vector<pair<int, int>> lst;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if(gcd(i, j)==1)
				lst.emplace_back(j, i);

	sort(lst.begin(), lst.end(), [](pair<int, int> a, pair<int, int> b) { return (float)a.first / a.second < (float)b.first / b.second; });

	fout << "0/1" << endl;
	for (pair<int, int> frac : lst)
		fout << frac.first << '/' << frac.second << endl;
	fout << "1/1" << endl;

	return 0;
}