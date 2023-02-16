#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int A[100000];
int mod;

bool cmp(int a, int b)
{
	return (a % mod) > (b % mod);
}

int main()
{
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
	cin >> N >> K;
	int M = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		M = max(M, A[i]);
	}
	int best = 0;
	for (int b = 1; b <= M; b++)
	{
		int full = 0;
		for (int i = 0; i < N; i++)
			full += A[i] / b;
		if (full < K / 2)
			break;
		if (full >= K)
		{
			best = max(best, b * (K / 2));
			continue;
		}
		mod = b;
		sort(A, A + N, cmp);
		int cur = b * (full - K / 2);
		for (int i = 0; i < N && i + full < K; i++)
			cur += A[i] % b;
		best = max(best, cur);
	}
	cout << best << '\n';
}