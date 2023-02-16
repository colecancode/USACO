/*
ID: coledou1
TASK: sprime
LANG: C++
*/

// COLE MILLER
// 12 / 2 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int ln;
vector<int> res;

int toInt(vector<int>& n, int i = ln-1) {
	int sum = 0, mult = 1;
	for (int j = i; j >= 0; --j) {
		sum += n[j] * mult;
		mult *= 10;
	}
	return sum;
}

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

void gen(vector<int>& n, int i) {
	if (i == ln) res.push_back(toInt(n));
	else {
		for (int j = 1; j <= 9; ++j) {
			n[i] = j;
			if (isPrime(toInt(n, i))) gen(n, i + 1);
		}
	}
}

void sprime() {
	vector<int> n(ln);
	int i = ln - 1;
	for (int m : {2, 3, 5, 7}) {
		n[0] = m;
		gen(n, 1);
	}
}

int main() {
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");

	fin >> ln;
	sprime();

	for (int n : res) fout << n << endl;

	return 0;
}