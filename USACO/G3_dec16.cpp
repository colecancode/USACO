#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);

	int N, xL, yL, xB, yB;
	cin >> N >> xL >> yL >> xB >> yB;

	if (xL == xB || yL == yB) {
		cout << "0\n";
		return 0;
	}

	map<int, vector<int>> mapX, mapY;
	while (N--) {
		int x, y;
		cin >> x >> y;
		mapX[x].emplace_back(y);
		mapY[y].emplace_back(x);
	}

	vector<pair<int, bool>> q { {xL, false}, {yL, true} }; // ( position, isHorizontal )
	set<pair<int, bool>> seen { {xL, false}, {yL, true} }; 

	for (int depth = 1; !q.empty(); ++depth) {
		int n = size(q);
		for (int i = 0; i < n; ++i) {
			auto [pos, dir] = q[i];

			if (dir) { // horizontal (position is y value)
				for (int x : mapY[pos])
				if (!seen.count(make_pair(x, false))) {
					if (x == xB) {
						cout << depth << endl;
						return 0;
					}
					seen.emplace(x, false);
					q.emplace_back(x, false);
				}
			}
			else { // vertical (position is x value)
				for (int y : mapX[pos])
				if (!seen.count(make_pair(y, true))) {
					if (y == yB) {
						cout << depth << endl;
						return 0;
					}
					seen.emplace(y, true);
					q.emplace_back(y, true);
				}
			}
		}
		q.erase(begin(q), begin(q) + n);
	}
	cout << "-1\n";
	return 0;
}