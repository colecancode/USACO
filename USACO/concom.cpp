/*
ID: coledou1
TASK: concom
LANG: C++
*/

// COLE MILLER
// 2 / 3 / 23

#include <bits/stdc++.h>
using namespace std;

int N, shares[105][105];
bool owns[105][105];

void controls(int i, int j) {
	if (owns[i][j]) return;

	owns[i][j] = 1;
	for (int k = 1; k <= 100; ++k)
		shares[i][k] += shares[j][k];

	for (int k = 1; k <= 100; ++k) {
		if (owns[j][k] || shares[i][k] > 50) controls(i, k);
		if (owns[k][i]) controls(k, j);
	}
}

int main() {
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);

	for (int i = 1; i <= 100; ++i)
		owns[i][i] = 1;

	cin >> N;
	while (N--) {
		int i, j, p;
		cin >> i >> j >> p;
		for (int k = 1; k <= 100; ++k)
			if (owns[k][i])
				shares[k][j] += p;
		
		for (int k = 1; k <= 100; ++k)
			if (shares[k][j] > 50)
				controls(k, j);
	}

	for(int i=1; i<=100; ++i)
	for(int j=1; j<=100; ++j)
		if(i!=j && owns[i][j])
			cout << i << ' ' << j << endl;
	return 0;
}