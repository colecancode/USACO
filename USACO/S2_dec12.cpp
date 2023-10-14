#include <bits/stdc++.h>
using namespace std;

int a[2005];
double dp[2005];
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	freopen("wifi.in", "r", stdin);
	freopen("wifi.out", "w", stdout);
	int N, A, B;
	cin >> N >> A >> B;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];
	sort(a+1, a+1+N);

	for (int i = 1; i <= N; ++i) {
		dp[i] = DBL_MAX;
		for (int j = i; j >= 1; --j)
			dp[i] = min(dp[i], dp[j-1] + A + (a[i] - a[j]) / 2.0 * B);
	}
	cout << (int)dp[N];
	if (dp[N] > (int)dp[N]) cout << ".5";
}