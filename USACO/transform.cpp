/*
ID: coledou1
TASK: transform
LANG: C++
*/

// COLE MILLER
// 11 / 11 / 22

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
typedef vector<string> mt; //matrix

mt rotate(mt og, int turns) {
    if (!turns) return og;

    int n = og.size();
    mt res(n);

    for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j < n; j++)
            res[j].push_back(og[i][j]);

    return rotate(res, turns - 1);
}

mt mirror(mt og) {
    mt res;

    for (string row : og) {
        string s(row.rbegin(), row.rend());
        res.push_back(s);
    }

    return res;
}

int findTransformation(mt start, mt end) {
    // logic
    for (int i = 1; i < 4; ++i)
        if (rotate(start, i) == end)
            return i;

    mt mirrored = mirror(start);
    if (mirrored == end) return 4;
    for (int i = 1; i < 4; ++i)
        if (rotate(mirrored, i) == end)
            return 5;

    if (start == end) return 6;
    return 7;
}

int main() {
    ofstream fout("transform.out");
    ifstream fin("transform.in");

    // size
    int n; fin >> n;
    // start and end matrices
    mt start(n), end(n);

    // read to matrices
    for (int i = 0; i < n; ++i)
        fin >> start[i];
    for (int i = 0; i < n; ++i)
        fin >> end[i];

    fout << findTransformation(start, end) << endl;
}