#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;

ll solve(vector<int>& V) {
	vector<int> idx(N);
	for (int i = 0; i < N; ++i)
		idx[V[i]] = i;

	ll cnt = 0;
	set<int> s{ idx[N - 1] };
	for (int i = N - 2; i >= 0; --i) {
		auto it = s.insert(idx[i]).first;
		if (next(it) != end(s))
			cnt += *next(it) - *it + 1;
	}
	
	return cnt;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	vector<int> a(N);
	for (int& e : a) cin >> e, e--;

	ll ans = 0;
	ans += solve(a);
	reverse(begin(a), end(a));
	ans += solve(a);

	cout << ans << endl;

	return 0;
}