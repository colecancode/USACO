#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> mat, V;

bool query(int i, int j) {
	if (mat[i][j] != -1)
		return mat[i][j];

	mat[i][j] = 0;
	for (int n : V[i])
	if (query(n, j))
		return mat[i][j] = 1;

	return 0;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> N;
	mat.resize(N+1, vector<int>(N+1, -1));
	V.resize(N+1);

	for (int i = 1; i <= N; ++i) {
		bool flag = 0;
		for (int j = 1; j <= N; ++j) {
			int k; cin >> k;
			flag |= k == i;
			if (!flag) {
				mat[i][k] = 1;
				V[i].emplace_back(k);
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		bool flag = 0;
		for (int n : V[i])
		if (query(n, i)) {
			flag = 1;
			cout << n << endl;
			break;
		}

		if (!flag) cout << i << endl;
	}

	return 0;
}