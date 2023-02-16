#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define mp make_pair

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int n; cin >> n;
    vector<pair<ii, int>> v(n); // arrival, seniority, duration
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = n - i;
    }
    sort(v.begin(), v.end());

    int ptr = 0, maxTime = 0, timeStep = 0;
    while (ptr < n) {
        pair<ii, int> c = v[ptr++];
        maxTime = max(maxTime, timeStep - c.first.first);

        if (ptr == n) break;
        int origPtr = ptr - 1;
        if (c.first.first > timeStep)
            timeStep = c.first.first;
        timeStep += c.first.second;
        priority_queue<pair<int, ii>> pq;
        while (ptr < n && timeStep > v[ptr].first.first) {
            c = v[ptr++];
            pq.push(mp(c.second, c.first));
        }
        while (!pq.empty()) {
            pair<int, ii> tp = pq.top(); pq.pop();
            maxTime = max(maxTime, timeStep - tp.second.first);
            timeStep += tp.second.second;
            while (ptr < n && timeStep > v[ptr].first.first) {
                c = v[ptr++];
                pq.push(mp(c.second, c.first));
            }
        }
    }
    cout << maxTime << '\n';
}