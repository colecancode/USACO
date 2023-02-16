/*
ID: coledou1
TASK: gift1
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
#include <unordered_map>

using namespace std;

typedef vector<string> vs;

int main() {
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	int n; fin >> n;

	vs names(n);
	for (int i = 0; i < n; ++i)
		fin >> names[i];

	unordered_map<string, int> balance;
	for (int i = 0; i < n; ++i) {
		string name; fin >> name;
		int total, friends; fin >> total >> friends;
		if (!friends) continue;
		balance[name] -= total - total % friends;
		int n = total / friends;
		while (friends--) {
			string s; fin >> s;
			balance[s] += n;
		}
	}

	for (string name : names)
		fout << name << ' ' << balance[name] << endl;

	return 0;
}