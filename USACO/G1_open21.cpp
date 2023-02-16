#include <bits/stdc++.h>

using namespace std;
#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {
private:
	vll ft;
public:
	FenwickTree(int m) { ft.assign(m + 1, 0); }

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
	
	int N; cin >> N;
	RUPQ ft(N);
	vector<int> lastSeen(N+1, 0);

	ll ans = 0;
	for (int i = 1; i <= N; ++i) {
		int k; cin >> k;
		ans += ft.point_query(lastSeen[k]+1);

		ft.range_update(lastSeen[k]+1, i, 1);
		lastSeen[k] = i;
	}

	cout << ans << endl;
	return 0;
}