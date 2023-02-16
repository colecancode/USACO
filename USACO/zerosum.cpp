/*
ID: coledou1
TASK: zerosum
LANG: C++
*/

// COLE MILLER
// 1 / 20 / 23

#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> ans;

int eval(string s) {
	int n = 0,
		m = 0,
		sign = 1;
	for (char c : s) {
		if (isdigit(c))
			m = m * 10 + c - '0';
		else if (c != ' ') {
			n += m * sign;
			m = 0;
			sign = c == '+' ? 1 : -1;
		}
	}
	n += m * sign;

	return n;
}

void solve(int i, string s) {
	if (i == N*2-1) {
		if (eval(s) == 0)
			ans.emplace_back(s);
		return;
	}

	s[i] = ' ';
	solve(i + 2, s);
	s[i] = '+';
	solve(i + 2, s);
	s[i] = '-';
	solve(i + 2, s);
}

int main() {
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);

	cin >> N;
	string s;
	for (int i = 1; i <= N; ++i) {
		s.push_back('0' + i);
		if (i < N) s.push_back(' ');
	}
	solve(1, s);

	for (string str : ans)
		cout << str << endl;

	return 0;
}