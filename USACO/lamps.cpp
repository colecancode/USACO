/*
ID: coledou1
TASK: lamps
LANG: C++
*/

// COLE MILLER
// 12 / 25 / 22

#include <fstream>
#include <iostream>
#include <bitset>
#include <set>

using namespace std;
#define b {0, 1}

ifstream fin("lamps.in");
ofstream fout("lamps.out");

int n, c;
bool a[2][2][2][2];
bitset<4> s;
set<string> ans;

bool check() {
	if ((c == 0 && s[0] + s[1] + s[2] + s[3] != 0) || (s[0] + s[1] + s[2] + s[3]) % 2 != c % 2)
		return false;
	for(int i : b)
		for(int j : b)
			for(int k : b)
				for (int l : b)
					if (a[i][j][k][l]) {
						int m = s[3];
						if (j) m += s[0];
						if (k) m += s[1];
						if (l) m += s[2];
						if (m % 2 == i)
							return false;
					}
	return true;
}

void print() {
	string str(n, '1' - s[3]);
	if (s[0])
		for (int i = 0; i < n; i += 2)
			str[i] = (str[i] == '0') ? '1' : '0';
	if (s[1])
		for (int i = 1; i < n; i += 2)
			str[i] = (str[i] == '0') ? '1' : '0';
	if (s[2])
		for (int i = 0; i < n; i += 3)
			str[i] = (str[i] == '0') ? '1' : '0';

	ans.insert(str);
}

void dfs(int i) {
	if (i == 4) {
		if (check())
			print();
		return;
	}

	s[i] = 0;
	dfs(i + 1);
	s[i] = 1;
	dfs(i + 1);
}

int main() {
	fin >> n >> c;

	int t, i = 1;
	while (fin >> t) {
		if (t == -1) --i;
		else
			a[i][t % 2][!(t % 2)][(t - 1) % 3 == 0] = true;
	}

	dfs(0);
	
	if (ans.empty())
		fout << "IMPOSSIBLE\n";
	for (string str : ans)
		fout << str << endl;

	return 0;
}