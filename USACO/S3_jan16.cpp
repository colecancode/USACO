#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef pair<int, int> ii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("gates.in", "r", stdin);
	freopen("gates.out", "w", stdout);

	int N; cin >> N;
	string s; cin >> s;

	set<ii> V;
	V.emplace(0, 0);
	set<pair<ii, ii>> E;

	int x = 0, y = 0;
	int pX = 0, pY = 0;
	for (char c : s) {
		switch (c) {
			case 'N': ++y; break;
			case 'E': ++x; break;
			case 'S': --y; break;
			case 'W': --x; break;
		}
		ii u = mp(pX, pY), v = mp(x, y);
		E.emplace(min(u, v), max(u, v));
		V.emplace(x, y);
		pX = x, pY = y;
	}
	cout << size(E) - size(V) + 1 << endl;
	return 0;
}