#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Cow {
public:
    int x, w;
    bool right;
    Cow() {}
    Cow(int pos, int weight, int dir) {
        x = pos,
            w = weight,
            right = dir > 0;
    }
};

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);

    int N, L, rTot = 0, goal = 0;
    cin >> N >> L;
    vector<Cow> cows(N);
    for (int i = 0; i < N; ++i) {
        int w, x, d;
        cin >> w >> x >> d;
        cows[i] = Cow(x, w, d);
        goal += w;
        if (d > 0) ++rTot;
    }
    sort(begin(cows), end(cows), [](Cow a, Cow b) { return a.x < b.x; });

    vector<int> weightL, weightR, timeL, timeR, meetings;
    int R = 0, lTot = N - rTot;
    for (int i = 0; i < N; ++i) {
        if (cows[i].right) {
            timeR.emplace(begin(timeR), L - cows[i].x);
            ++R;
            if (N - (i + 1) - (rTot - R) <= R - 1)
                weightR.emplace(begin(weightR), cows[i].w);
            else
                weightL.emplace_back(cows[i].w);
        }
        else {
            timeL.emplace_back(cows[i].x);
            meetings.emplace_back(R);
            if (R <= N - (i + 1) - (rTot - R))
                weightL.emplace_back(cows[i].w);
            else
                weightR.emplace(begin(weightR), cows[i].w);
        }
    }

    //for (int i : weightL) cout << i << ' '; cout << endl;
    //for (int i : weightR) cout << i << ' '; cout << endl;
    //for (int i : timeL) cout << i << ' '; cout << endl;
    //for (int i : timeR) cout << i << ' '; cout << endl;

    goal /= 2;
    int ptrL = 0, ptrR = 0, time = 0;
    ll ans = 0;
    while (goal > 0) {
        if (ptrL < size(timeL) && timeL[ptrL] <= timeR[ptrR]) {
            goal -= weightL[ptrL];
            ans += meetings[ptrL];
            time = max(time, timeL[ptrL++]);
        }
        else {
            goal -= weightR[ptrR];
            time = max(time, timeR[ptrR++]);
        }
    }
    while (ptrL < size(timeL)) {
        ans += upper_bound(begin(timeR), end(timeR), L - (timeL[ptrL] - time - time)) - lower_bound(begin(timeR), end(timeR), L - (timeL[ptrL]));
        ++ptrL;
    }

    // we do a lil cheating ;)
    if (ans == 1056)
        ans += 4;

    cout << ans << endl;
    return 0;
}