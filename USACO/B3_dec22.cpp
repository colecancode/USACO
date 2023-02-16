#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<string, char>> a(m);

    for (int i = 0; i < m; ++i)
        cin >> a[i].first >> a[i].second;

    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < n; ++i) {
            char zero = '\0', one = '\0';
            for (int j = 0; j < size(a); ++j) {
                if (a[j].first[i] == '0') {
                    if (!zero)
                        zero = a[j].second;
                    else if (a[j].second != zero)
                        zero = 'X';
                } else {
                    if (!one)
                        one = a[j].second;
                    else if (a[j].second != one)
                        one = 'X';
                }
            }
            if (zero && zero != 'X') {
                flag = true;
                for (int j = 0; j < size(a); ++j)
                    if (a[j].first[i] == '0')
                        a.erase(next(begin(a), j--));
            }
            if (one && one != 'X') {
                flag = true;
                for (int j = 0; j < size(a); ++j)
                    if (a[j].first[i] == '1')
                        a.erase(next(begin(a), j--));
            }
        }
    }
    cout << (a.empty() ? "OK\n" : "LIE\n");
}
int main() {
    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}