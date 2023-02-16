#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef long long ll;

int n;
ll avg;
vector<ll> hay, sub_total;
vector<vector<int>> adj;
vector<tuple<int, int, ll>> orders;

void fill(int node = 0, int par = 0) {
	// DFS
	sub_total[node] = hay[node] - avg;
	for (int child : adj[node]) {
		if (child != par) {
			fill(child, node);
			sub_total[node] += sub_total[child];
		}
	}
}

void order(int node = 0, int par = 0) {
	for (int child : adj[node]) {
		if (child != par) {
			if (sub_total[child] >= 0)
				order(child, node);
			if (sub_total[child] > 0)
				orders.emplace_back(child, node, sub_total[child]);
		}
	}

	for (int child : adj[node]) {
		if (child != par && sub_total[child] < 0) {
			orders.emplace_back(node, child, -sub_total[child]);
			order(child, node);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	hay.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> hay[i];
		avg += hay[i];
	}
	avg /= n;

	adj.resize(n);
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b;
		adj[--a].emplace_back(--b);
		adj[b].emplace_back(a);
	}

	sub_total.resize(n);
	fill();
	order();

	cout << size(orders) << endl;
	for (auto [u, v, n] : orders)
		cout << ++u << ' ' << ++v << ' ' << n << endl;

	return 0;
}