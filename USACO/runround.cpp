/*
ID: coledou1
TASK: runround
LANG: C++
*/

// COLE MILLER
// 12 / 22 / 22

#include <fstream>
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

ifstream fin("runround.in");
ofstream fout("runround.out");

int n;
string ans;

bool check(string s) {
	int i = 0;
	while (s[i] != 'X') {
		int tmp = s[i] - '0';
		s[i] = 'X';
		i = (i + tmp) % size(s);
	}
	if (i != 0)
		return false;
	for (char c : s)
		if (c != 'X')
			return false;
	return true;
}

void permutation(string& s, bitset<10> used, int cur) {
	if (cur == size(s)) {
		if (stoi(s) > n && check(s)) {
			fout << s << endl;
			exit(0);
		}
		return;
	}

	for (int i = 1; i < 10; ++i) {
		if (!used[i]) {
			s[cur] = i + '0';
			used[i] = true;
			permutation(s, used, cur + 1);
			used[i] = false;
		}
	}
}

int main() {

	string inp; fin >> inp;
	n = stoi(inp);

	string s(size(inp), '0');
	bitset<10> used;
	permutation(s, used, 0);
	s = string(size(inp) + 1, '0');
	permutation(s, used, 0);

	return 0;
}