#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> have(n);
    for (auto& x : have) cin >> x;
    int k; cin >> k;
    vector<vector<int>> need(n);
    while (k--) {
        int want, m; cin >> want >> m;
        need[--want].resize(m);
        for (auto& x : need[want]) {
            cin >> x; x--;
        }
    }
    int ret = 0;
    while (true) {
        vector<int> consume(n);
        consume[n-1]++;
        bool good = true;
        for (int i=n-1; i>=0; i--) {
            if (consume[i] <= have[i]) {
                have[i] -= consume[i];
                continue;
            }
            if (need[i].size() == 0) {
                good = false;
                break;
            }
            int take = min(consume[i], have[i]);
            consume[i] -= take;
            have[i] -= take;
            for (int out : need[i]) consume[out] += consume[i];
        }
        if (good) ret++;
        else break;
    }
    cout << ret << endl;
}