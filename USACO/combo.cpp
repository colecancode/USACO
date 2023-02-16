/*
ID: coledou1
TASK: combo
LANG: C++
*/

// COLE MILLER
// 11 / 13 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

// weird, messy code. But at least I found a way to not bruteforce it :)

int main() {
	ifstream fin("combo.in");
	ofstream fout("combo.out");

	int n, farmer[3], master[3];
	fin >> n;
	for (int i = 0; i < 3; ++i) fin >> farmer[i]; // 1 2 3
	for (int i = 0; i < 3; ++i) fin >> master[i]; // 3 4 5

	auto func = [&](int x) {
		while (x < 1) x += n;
		return (x-1) % n + 1;
	};

	auto dist = [&](int a, int b) {
		int mx = max(a, b), mn = min(a, b);
		return min(mx - mn, func(mn - mx));
	};

	int overlap = 1;
	for (int i = 0; i < 3; ++i) {
		int cnt(0);
		unordered_set<int> seen;
		for (int j = farmer[i] - 2; j <= farmer[i] + 2; ++j) {
			if (seen.count(func(j))==0 && dist(func(j), master[i]) <= 2) ++cnt;
			seen.insert(func(j));
		}
		overlap *= cnt;
	}

	fout << pow(min(5, n), 3)*2 - overlap << endl;
}