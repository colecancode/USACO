#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);

	int N, M, R;
	cin >> N >> M >> R;
	vector<int> milk(N), rent(R);
	vector<pair<int, int>> sell(M);

	for (int& e : milk) cin >> e;
	for (auto& [price, amt] : sell) cin >> amt >> price;
	for (int& e : rent) cin >> e;

	sort(milk.rbegin(), milk.rend());
	sort(sell.rbegin(), sell.rend());
	sort(rent.begin(), rent.end());

	ll ans = 0;
	int sellIdx = 0, i;
	for (i = 0; i < N; ++i) {
		int rentIdx = R - N + i;
		ll profit = 0;
		while (sellIdx < M && milk[i] > 0) {
			int dif = min(milk[i], sell[sellIdx].second);
			profit += dif * sell[sellIdx].first;
			sell[sellIdx].second -= dif;
			if (sell[sellIdx].second == 0)
				++sellIdx;
			milk[i] -= dif;
		}
		if (rentIdx < 0 || profit > rent[rentIdx])
			ans += profit;
		else
			break;
	}

	for (int j = R - N + i; j < R; ++j)
		ans += rent[j];

	cout << ans << endl;

	return 0;
}