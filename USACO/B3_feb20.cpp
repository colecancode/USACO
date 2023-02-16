#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);

	int N, A1, A2, B1, B2; 
	ll K;
	cin >> N >> K >> A1 >> A2 >> B1 >> B2;
	--A1, --A2, --B1, --B2;

	vector<int> V(N); // displacement
	for(int i=0; i<N; ++i)
		V[i] = i;
	for (int i=0; i<(A2 - A1 + 1)/2; ++i) { // swap #1
		int tmp = V[A1 + i];
		V[A1 + i] = V[A2 - i];
		V[A2 - i] = tmp;
	}
	for (int i = 0; i < (B2 - B1 + 1) / 2; ++i) { // swap #2
		int tmp = V[B1 + i];
		V[B1 + i] = V[B2 - i];
		V[B2 - i] = tmp;
	}

	vector<vector<int>> cycles(N, vector<int>(N));
	vector<int> par(N, -1), sz(N);
	int c = 0;
	for (int i = 0; i < N; ++i) {
		if (par[i] == -1) {
			int j = i;
			while (par[j] == -1) {
				par[j] = c;
				cycles[c][V[j]] = j;
				j = V[j]; // next spot
				++sz[c];
			}
			++c;
		}
	}

	vector<int> ans(N);
	for (int i = 0; i < N; ++i) {
		int n = K % sz[par[i]],
			j = i;
		while (n--)
			j = cycles[par[i]][j];
		ans[j] = i+1;
	}

	for (int n : ans)
		cout << n << endl;

	return 0;
}