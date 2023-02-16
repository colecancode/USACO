#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> cowsN, cowsE; // (x, y, index)
	for (int i = 0; i < n; ++i) {
		char dir;
		int x, y; cin >> dir >> x >> y;
		if (dir == 'N') cowsN.push_back({ x, y, i });
		else cowsE.push_back({ x, y, i });
	}
	sort(begin(cowsN), end(cowsN));
	sort(begin(cowsE), end(cowsE));

	vector<vector<int>> collisions; // (time, cow, rut)
	int l = 0;
	for (auto a : cowsE) {
		int x = a[0], y = a[1], i = a[2];
		while (l < size(cowsN) && x >= cowsN[l][0])
			++l;
		for (int j = l; j < size(cowsN); ++j) {
			int dx = cowsN[j][0] - x,
				dy = y - cowsN[j][1];
			if (dy >= 0) {
				if (dy < dx)
					collisions.push_back({ dx, i, cowsN[j][2], dy });
				else if (dy > dx)
					collisions.push_back({ dy, cowsN[j][2], i, dx });
			}
		}
	}

	vector<int> ans(n, 0);
	sort(begin(collisions), end(collisions));
	for (auto a : collisions) {
		if (ans[a[1]] == 0 && (ans[a[2]] == 0 || ans[a[2]] >= a[3])) {
			ans[a[1]] = a[0];
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (ans[i] > 0)
			cout << ans[i] << endl;
		else
			cout << "Infinity\n";
	}

	return 0;
}