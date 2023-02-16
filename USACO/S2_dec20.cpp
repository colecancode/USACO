#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;
bool ycomp(Point p, Point q) { return p.second < q.second; }

const int MAX_N = 2500;
int N, Psum[MAX_N + 1][MAX_N + 1];
Point P[MAX_N];

int rsum(int x1, int y1, int x2, int y2)
{
    return Psum[x2 + 1][y2 + 1] - Psum[x2 + 1][y1] - Psum[x1][y2 + 1] + Psum[x1][y1];
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        P[i] = make_pair(x, y);
    }
    sort(P, P + N);
    for (int i = 0; i < N; i++) P[i].first = i + 1;
    sort(P, P + N, ycomp);
    for (int i = 0; i < N; i++) P[i].second = i + 1;
    for (int i = 0; i < N; i++) Psum[P[i].first][P[i].second] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            Psum[i][j] += Psum[i - 1][j] + Psum[i][j - 1] - Psum[i - 1][j - 1];
    long long answer = 0;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++) {
            int x1 = min(P[i].first, P[j].first) - 1;
            int x2 = max(P[i].first, P[j].first) - 1;
            answer += rsum(0, i, x1, j) * rsum(x2, i, N - 1, j);
        }
    cout << answer + 1 << "\n";

}