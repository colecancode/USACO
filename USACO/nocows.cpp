/*
ID: coledou1
TASK: nocows
LANG: C++
*/

// COLE MILLER
// 1 / 8 / 23

#include <fstream>
#include <iostream>
#define MOD 9901
#define ll long long
using namespace std;

unsigned ll table[105][205], N, K;
unsigned ll smalltrees[105][205];

int main() {
    ifstream fin("nocows.in");
    ofstream fout("nocows.out");
    fin >> N >> K;
    table[1][1] = 1;
    for (int i = 2; i <= K; i++) {
        for (int j = 1; j <= N; j += 2) {
            for (int k = 1; k <= j - 1 - k; k += 2) {
                int m = 2 * k == j - 1 ? 1 : 2;
                table[i][j] += m * (
                    smalltrees[i - 2][k] * table[i - 1][j - 1 - k]      // left subtree smaller than i-1
                    + table[i - 1][k] * smalltrees[i - 2][j - 1 - k]    // right smaller
                    + table[i - 1][k] * table[i - 1][j - 1 - k]);       // both i-1 table[i][j] %= MOD;
                table[i][j] %= MOD;
            }
        }
        for (int k = 0; k <= N; k++) {                                          // we ensure that smalltrees[i-2][j] in the next
                smalltrees[i - 1][k] += table[i - 1][k] + smalltrees[i - 2][k]; // iteration contains the number
                smalltrees[i - 1][k] %= MOD;                                    // of trees smaller than i-1 and with j nodes
        }
    }

    fout << table[K][N] % MOD << endl;
    return 0;
}