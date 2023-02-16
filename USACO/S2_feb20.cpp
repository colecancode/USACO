#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
#define ll long long
#define MOD 1000000007
#define f first
#define s second

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);

	int N; cin >> N;
	unordered_map<int, map<int, ll>> mapX, mapY;
	while (N--) {
		int x, y;
		cin >> x >> y;
		mapX[x][y] = 0;
		mapY[y][x] = 0;
	}

	// prefix sum X values
	for (auto& [y, mp] : mapY) {
		ll pSum = 0, n = mp.size();
		for (auto it = mp.begin(); next(it, 1) != mp.end(); ++it)
			pSum += (--n) * (-(it->f) + next(it, 1)->f);

		n = size(mp) - 2;
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			it->s = pSum;
			if (next(it, 1) != mp.end())
				pSum += -n * (-(it->f) + next(it, 1)->f);
			n -= 2;
		}

	}
	// prefix sum Y values
	for (auto& [x, mp] : mapX) {
		ll pSum = 0, n = mp.size();
		for (auto it = mp.begin(); next(it, 1) != mp.end(); ++it)
			pSum += (--n) * (-(it->f) + next(it, 1)->f);

		n = mp.size() - 2;
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			it->s = pSum;
			if (next(it, 1) != mp.end())
				pSum += -n * (-(it->f) + next(it, 1)->f);
			n -= 2;
		}
	}

	ll ans = 0;
	for (auto [y, mp] : mapY)
		for (auto [x, edgeSum] : mp)
			ans = (ans + (edgeSum * mapX[x][y])) % MOD;

	cout << ans << endl;

	return 0;
}