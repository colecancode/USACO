#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("cereal.in", "r", stdin);
	freopen("cereal.out", "w", stdout);

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> fav(N);
	for (auto& [f, s] : fav) { cin >> f >> s; --f, --s; }

	int happy = 0;
	vector<int> cereal(M, -1), ans(N);
	for (int i = N-1; i >= 0; --i) {
		auto [fst, sec] = fav[i];
		int& cow = cereal[fst];

		if (cow != -1) {

			int curCow = cow, curCereal = fst;
			while (curCow != -1 && curCereal == fav[curCow].first && (cereal[fav[curCow].second] > curCow || cereal[fav[curCow].second] == -1)) {
				int tmp = curCow;
				curCow = cereal[fav[curCow].second];
				curCereal = fav[tmp].second;
				cereal[fav[tmp].second] = tmp;
			}
			if (curCow == -1) ++happy;
		}
		else ++happy;
		cow = i;

		ans[i] = happy;
	}

	for (int k : ans) cout << k << endl;
	return 0;
}