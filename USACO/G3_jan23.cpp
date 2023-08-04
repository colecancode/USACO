#include <bits/stdc++.h>
using namespace std;
#define FOR(s, e, i) for(int i=s; i<e; ++i)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

ll ans = 1;

int n;
vi arr;

const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;

ll fact[MAXN];

int multinv(int n, int m) {
	/* Multiplicative inverse of n mod m in log(m) */
	if (m == 1) return 0;
	int m0 = m, y = 0, x = 1, t;

	while (n > 1) {
		t = y;
		y = x - n / m * y;
		x = t;

		t = m;
		m = n % m;
		n = t;
	}

	return x < 0 ? x + m0 : x;
}

int nCk(int N, int K) {
	if (K <= 0) return 1;
	//cout << "                " << N << ' ' << K << endl;
	return fact[N] * multinv(fact[N-K] * fact[K] % MOD, MOD) % MOD;
}

void solve(int i, int below, bool flag) {
	int amt = arr[i];
	for (int j = i+1; arr[j]; ++j)
		amt = min(amt, arr[j]);

	cout << i << ' ' << amt << ' ' << below << endl;
	int k = i;
	for (int j = i; arr[j]; ++j)
		if (arr[j] -= amt)
			k = j+1;

	for (int j = i; j < k; ++j)
		if (arr[j])
			solve(j, below+amt, true);
	if (flag) (ans *= nCk(amt+below-(i != 0), below-(i != 0))) %= MOD;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = (fact[i - 1] * i) % MOD;
	
	cin >> n;
	arr.resize(n);
	for (int& x : arr) {
		cin >> x;
		x /= 2;
	}
	arr.push_back(0);

	solve(0, 0, 0);
	cout << ans;
}