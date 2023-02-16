#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);

	int N; cin >> N;

	vector<int> a(N);
	for (int& x : a) cin >> x;
	sort(begin(a), end(a));

	int maxN, l, r;
	maxN = l = r = 0;
	while (r < N) { // sliding window
		while (r<N && a[r] <= a[l] + N - 1) ++r;

		if(a[l]!=a[r-1]-(N-2) || (l!=0 && r!=N))
			maxN = max(maxN, r - l);
		++l;
	}
	cout << N - maxN << endl
		 << max(a[N-1]-a[1]-1-(N-3), a[N-2]-a[0]-1-(N-3)) << endl; // good luck deciphering this xD

	return 0;
}