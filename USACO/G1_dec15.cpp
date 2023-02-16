#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int elsie[100005];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);

	int N; cin >> N;
	for (int i = 1; i <= N; ++i) {
		int t; cin >> t;
		elsie[t] = 1 + (i > N/2);
	}

	vector<int> E1(N/2), B1(N/2),
				E2(N/2), B2(N/2);

	int b_i1 = N/2, e_i1 = N/2,
		b_i2 = 0,	e_i2 = 0;

	for (int i = 1; i <= 2 * N; ++i)
		if (elsie[i] == 1)		E1[--e_i1] = i;
		else if (elsie[i] == 2) E2[e_i2++] = i;
		else if (b_i2 < N / 2)	B2[b_i2++] = i;
		else					B1[--b_i1] = i;
	
	int ans = 0;

	int l = 0, r = N/2 - 1; // half 1
	for (int i=0; i<N/2; ++i) {
		if (B1[l] < E1[i]) r--;
		else l++, ans++;
	}
	l = 0, r = N / 2 - 1;	// half 2
	for (int i = 0; i < N / 2; ++i) {
		if (B2[l] > E2[i]) r--;
		else l++, ans++;
	}

	cout << ans << endl;

	return 0;
}