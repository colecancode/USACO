#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int find(vector<int>& par, int i) {
	if (par[i] != i)
		par[i] = find(par, par[i]);

	return par[i];
}

void join(vector<int>& par, vector<int>& rnk, int a, int b) {
	a = find(par, a), b = find(par, b);
	if (a == b) return;

	if (rnk[a] >= b) {
		par[b] = a;
		rnk[a] += b;
	} else {
		par[a] = b;
		rnk[b] += a;
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);

	int N, M; cin >> N >> M;
	vector<int> A(N), outOfPlace;
	for (int i = 0; i < N; ++i) {
		int p; cin >> p;
		A[p - 1] = i;

		if (p - 1 != i)
			outOfPlace.emplace_back(i);
	}

	if (outOfPlace.empty()) {
		cout << "-1\n";
		return 0;
	}

	vector<tuple<int, int, int>> wormholes(M);
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a, --b;
		wormholes.emplace_back(w, a, b);
	}
	sort(rbegin(wormholes), rend(wormholes));

	int l = 0, r = M - 1, ans=0;
	while (l < r) {
		vector<int> par(N), rnk(N, 1);
		for (int i = 0; i < N; ++i)
			par[i] = i;

		int mid = (l + r + 1) / 2;
		for (int i = 0; i <= mid; ++i) {
			auto [w, a, b] = wormholes[i];
			join(par, rnk, a, b);
		}
		bool flag = 1;
		for (int i : outOfPlace) {
			if (find(par, i) != find(par, A[i])) {
				flag = 0;
				break;
			}
		}

		if (flag) r = mid - 1, ans = mid;
		else l = mid;
	}
	cout << get<0>(wormholes[ans]) << endl;

	return 0;
}