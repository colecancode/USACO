#include <bits/stdc++.h>
using namespace std;
#define FOR(s, e, i) for(int i=s; i<e; ++i)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define LSOne(S) ((S) & -(S))

class FenwickTree {
private:
	vll ft;
public:
	FenwickTree(int m) { ft.assign(m + 1, 0); }

	void build(const vll& f) {
		int m = f.size() - 1;
		ft.assign(m + 1, 0);
		for (int i = 1; i <= m; ++i) {
			ft[i] += f[i];
			if (i + LSOne(i) <= m)
				ft[i + LSOne(i)] += ft[i];
		}
	}

	FenwickTree(const vll& f) { build(f); }

	FenwickTree(int m, const vi& s) {
		vll f(m + 1, 0);
		for (int i = 0; i < s.size(); ++i)
			++f[s[i]];
		build(f);
	}

	ll rsq(int j) {
		ll sum = 0;
		for (; j; j -= LSOne(j))
			sum += ft[j];
		return sum;
	}

	ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

	void update(int i, ll v) {
		for (; i < ft.size(); i += LSOne(i))
			ft[i] += v;
	}
};

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	//freopen("sleepy.in", "r", stdin);
	//freopen("sleepy.out", "w", stdout);

	int N; cin >> N;
	vi arr(N);
	for (int& x : arr)
		cin >> x;

	int K = 0;
	for (int i = N-1; i > 0; --i)
		if (arr[i] < arr[i - 1]) {
			K = i;
			break;
		}

	FenwickTree ft(N);
	for (int i = K; i < N; ++i)
		ft.update(arr[i], 1);

	cout << K << endl;
	for (int i = 0; i < K; ++i) {

		cout << K - i - 1 + ft.rsq(arr[i]);
		if (i+1 < K) cout << ' ';
		ft.update(arr[i], 1);
	}
}