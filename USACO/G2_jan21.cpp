#include <bits/stdc++.h>
using namespace std;
#define FOR(s, e, i) for(int i=s; i<e; ++i)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, K; cin >> N >> K;
	vi arr(N); for(int& m : arr) cin >> m;
	vector<vi> idx(K+1), V(K+1); // occurences, compatible breeds
	FOR(0, N, i) idx[arr[i]].emplace_back(i);
	FOR(1, K+1, i) FOR(1, K+1, j) {
		char c; cin >> c;
		if (c == '1') V[j].emplace_back(i);
	}

	priority_queue<ii, vector<ii>, greater<ii>> pq; pq.emplace(0, N-1);
	vi dist(N, 1e8); dist[N-1]=0;
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop(); // vertex
		int b = arr[u]; // breed

		if (u == 0) {
			cout << N-1 + 2*dist[u] << endl;
			return 0;
		}

		for (int i : V[b]) {
			for (int j : idx[i]) {
				if (u!=j && dist[j] > dist[u]+max(0, j-u)) {
					dist[j] = dist[u]+max(0, j-u);
					pq.emplace(dist[j], j);
				}
			}
		}
	}
	cout << "-1\n";
	return 0;
}