#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
#define MAXK 25

int dp[MAXN][MAXK][3];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	int N, K; cin >> N >> K;

	vector<int> moves(N);
	for (int& m : moves) {
		char c; cin >> c;
		m = (c == 'H' ? 0 : (c == 'P' ? 1 : 2));
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			for (int state = 0; state < 3; ++state) {
				if (j == 0)
					dp[i][j][state] = dp[i - 1][j][state] + (moves[i - 1] == state);
				else {
					dp[i][j][state] = max(
						max(
						dp[i - 1][j][state],
						dp[i - 1][j - 1][(state + 1) % 3]),
						dp[i - 1][j - 1][(state + 2) % 3]
						) + (moves[i - 1] == state);
				}
			}
		}
	}

	cout << max(dp[N][K][0], max(dp[N][K][1], dp[N][K][2])) << endl;

	return 0;
}