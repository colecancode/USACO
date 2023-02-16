#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int N, K;
	cin >> N >> K;
	vector<int> V(N);
	for (int& e : V) cin >> e;

	sort(begin(V), end(V));
	vector<int> rng(N);
	for (int i = 0; i < N; ++i)
		rng[i] = upper_bound(begin(V), end(V), V[i] + K) - begin(V) - i;

	vector<int> maxRng(N+1);
	int m = 0;
	for (int i = N - 1; i >= 0; --i) {
		m = max(m, rng[i]);
		maxRng[i] = m;
	}

	int best = 0;
	for (int i = 0; i < N; ++i)
		best = max(best, rng[i] + maxRng[i + rng[i]]);

	cout << best << endl;

	return 0;
}