#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string S, T;
    cin >> S >> T;

    string R;
    for (int i = 0; i < S.size(); i++) {
        R += S[i];

        if (R.size() >= T.size() && R.substr(R.size() - T.size()) == T)
            R.resize(R.size() - T.size());
    }

    cout << R << endl;
    return 0;
}