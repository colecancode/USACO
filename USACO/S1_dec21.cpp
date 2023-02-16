#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define f first
#define s second

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int K, M, N;
	cin >> K >> M >> N;
	
	vector<pair<int, int>> patches(K);
	for (auto& [p, t] : patches)
		cin >> p >> t;

	vector<int> nhoj(M);
	for (int& p : nhoj)
		cin >> p;

	sort(begin(patches), end(patches));
	sort(begin(nhoj), end(nhoj));

	vector<int> options;
	int p_i = 0;
	for (int i = 0; i <= M; ++i) {
		int l = i>0 ? nhoj[i - 1] : -1, 
			r = i<M ? nhoj[i] : -1; // might be a prob
		int rangeEnd = -1,
			rangeVal = 0;
		while (p_i < K && (patches[p_i].f < r || r == -1)) {
			auto [pos, taste] = patches[p_i];
			if (pos > l) {
				int range;
				if (l == -1)	  range = r - pos;
				else if (r == -1) range = pos - l;
				else			  range = min(pos - l, r - pos);

				if (pos - range >= rangeEnd || rangeEnd == -1) {
					if (rangeEnd != -1)
						options.emplace_back(rangeVal);
					rangeEnd = pos + range;
					rangeVal = taste;
				} else {
					rangeEnd = min(rangeEnd, pos + range);
					rangeVal += taste;
				}

				//cout << pos << ' ' << taste << "    " << range << "     " << l << ' ' << r << "      " << rangeEnd << ' ' << rangeVal << endl;
			}

			++p_i;
		}
		if(rangeVal != 0)
			options.emplace_back(rangeVal);
	}

	//for (int n : options) cout << n << ' ';
	//cout << endl;

	sort(rbegin(options), rend(options));
	ll ans = 0;
	int sz = size(options);
	for (int i = 0; i < min(N, sz); ++i)
		ans += options[i];

	cout << ans << endl;

	return 0;
}