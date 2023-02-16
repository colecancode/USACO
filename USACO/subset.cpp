/*
ID: coledou1
TASK: subset
LANG: C++
*/

// COLE MILLER
// 12 / 21 / 22

#include <fstream>
using namespace std;
int n, target;
long long dp[400];

int main() {
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	fin >> n;
	target = n * (n + 1) / 2;
	if (target % 2) {
		fout << 0 << endl;
		return 0;
	}

	dp[0] = 1;
	target /= 2;
	for (int i = 1; i <= n; ++i)
		for (int j = target; j >= i; --j)
			dp[j] += dp[j - i];

	fout << dp[target] / 2 << endl;
	return 0;
}