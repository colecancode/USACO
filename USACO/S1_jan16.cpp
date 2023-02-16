#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	//freopen("angry.in", "r", stdin);
	//freopen("angry.out", "w", stdout);

	int N, K;
	cin >> N >> K;
	vector<int> V(N);
	for (int& x : V) cin >> x;
	sort(begin(V), end(V));

	int l = 0, r = V[N - 1], ans = r;
	while (l <= r) {
		int mid = (l + r) / 2, k = K;
		auto ptr = begin(V);
		while (k-- && ptr!=end(V))
			ptr = upper_bound(ptr, end(V), *ptr + 2 * mid);

		if (ptr == end(V))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}

	cout << ans << endl;
	return 0;
}