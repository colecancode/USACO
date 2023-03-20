#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define ii pair<int, int>

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	//freopen("cowmbat.in", "r", stdin);
	//freopen("cowmbat.out", "w", stdout);

	int N, M, K;
	string S;
	cin >> N >> M >> K >> S;

	vector<vector<int>> E(M, vector<int>(M)), dist(M, vector<int>(M, INF));
	for (auto& row : E)
	for (int& col : row)
		cin >> col;

    for (int i = 0; i < M; ++i) {
        priority_queue<ii, vector<ii>, greater<ii>> pq;
		dist[i][i] = 0;
        pq.push(make_pair(0, i));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (int v = 0; v < M; ++v) {
				int weight = E[u][v];

                if (dist[i][v] > dist[i][u] + weight) {
                    dist[i][v] = dist[i][u] + weight;
                    pq.push(make_pair(dist[i][v], v));
                }
            }
        }
    }

	vector<vector<int>> dp(N+1, vector<int>(M+1)), cost(N+1, vector<int>(M+1));
	for (int i = 1; i <= N; ++i) {
		dp[i][0] = 100000000;
		for (int j = 1; j <= M; ++j) {
			cost[i][j] = cost[i-1][j] + dist[S[i-1]-'a'][j-1];
			if (i >= K) {
				dp[i][j] = min(dp[i-1][j] + dist[S[i-1]-'a'][j-1], dp[i-K][0] + cost[i][j] - cost[i-K][j]);
				dp[i][0] = min(dp[i][0], dp[i][j]);
			}
			else
				dp[i][j] = 100000000;
		}
	}
	cout << dp[N][0] << endl;
	return 0;
}