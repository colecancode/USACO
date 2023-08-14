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

	int select(ll k) {
		int l = 1, r = ft.size() - 1;
		for (int i = 0; i < 30; ++i) {
			int mid = (l + r) / 2;
			(rsq(1, mid) < k) ? l = mid : r = mid;
		}
		return r;
	}
};

class RUPQ {
private:
	FenwickTree ft;
public:
	RUPQ(int m) : ft(FenwickTree(m)) {}
	void range_update(int ui, int uj, int v) {
		ft.update(ui, v);
		ft.update(uj + 1, -v);
	}
	ll point_query(int i) { return ft.rsq(i); }
};

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	int n; cin >> n;
	vi arr(2 * n + 1);
	for (int i = 1; i <= 2 * n; ++i) cin >> arr[i];

	RUPQ fenwick(2 * n);
	vi seen(2*n+1, -1), dp(2*n+1);
	ll ans = 0, cur = 0;
	for (int i = 1; i <= 2*n; ++i) {
		int& start = seen[arr[i]];
		if (start == -1) {
			start = i;
			++cur;
		}
		else {
			ans += cur - dp[start] + fenwick.point_query(start);
			fenwick.range_update(start, i, 2);
			--cur;
		}
		dp[i] = cur;
	}
	cout << ans / 2;
}