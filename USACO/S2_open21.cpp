#include <bits/stdc++.h>
using namespace std;

int N, a, b, c, ab, bc, ac, abc;
vector<int> V;
set<tuple<int, int, int>> ans;

void check() {
    int A=a, B=b, C=c;
    if (!a) {
        if (bc && abc)    A = abc - bc;
        else if (b && ab) A = ab - b;
        else if (c && ac) A = ac - c;
    }
    if (!b) {
        if (ac && abc)    B = abc - ac;
        else if (a && ab) B = ab - a;
        else if (c && bc) B = bc - c;
    }
    if (!c) {
        if (ab && abc)    C = abc - ab;
        else if (a && ac) C = ac - a;
        else if (b && bc) C = bc - b;
    }

    if (
        1 <= A && A <= B && B <= C &&
        (!ab || A + B == ab) &&
        (!bc || B + C == bc) &&
        (!ac || A + C == ac) &&
        (!abc || A + B + C == abc) &&
        !ans.count(tuple<int, int, int> {A, B, C})
        ) ans.emplace(A, B, C);
}

void solve(int k) {
    if (k == N) { check(); return; }

    if (!a)   { a =   V[k]; solve(k + 1); a   = 0; }
    if (!b)   { b =   V[k]; solve(k + 1); b   = 0; }
    if (!c)   { c =   V[k]; solve(k + 1); c   = 0; }
    if (!ab)  { ab =  V[k]; solve(k + 1); ab  = 0; }
    if (!bc)  { bc =  V[k]; solve(k + 1); bc  = 0; }
    if (!ac)  { ac =  V[k]; solve(k + 1); ac  = 0; }
    if (!abc) { abc = V[k]; solve(k + 1); abc = 0; }
}

void solve() {
    cin >> N; ans.clear(); V.resize(N);
    a = b = c = ab = bc = ac = abc = 0;
    for (int& x : V) cin >> x;

    solve(0);
    cout << size(ans) << endl;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}