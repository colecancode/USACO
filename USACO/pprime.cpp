/*
ID: coledou1
TASK: pprime
LANG: C++
*/

// COLE MILLER
// 12 / 1 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int lb, ub;

void palindromes(int digits, int idx, vector<int>& n, vector<int>& res) {
	if (idx > (digits - 1) / 2) { // second half of palindrome
		int m(0), i(0);
		// construct palindromic number
		for (; i < digits / 2; ++i) {
			m += n[i] * pow(10, digits - i - 1) + n[i] * pow(10, i);
		}
		if (digits & 1) m += n[i] * pow(10, i); // odd # of digits
		if (m >= lb && m <= ub) res.emplace_back(m);
	}
	else {
		for (int i = 0; i <= 9; ++i) {
			n[idx] = i;
			palindromes(digits, idx + 1, n, res);
		}
	}
}

vector<int> palindromes(int digits) {
	vector<int> n(digits, 0), res;
	for (int i = 1; i <= 9; i += 2) {
		n[0] = i;
		palindromes(digits, 1, n, res);
	}
	return res;
}

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}

int main() {
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");

	fin >> lb >> ub;

	// generate palindromes in [s, e]
	int n = log10(lb)+1, m = log10(ub)+1;
	vector<int> res;
	for (int i = n; i <= m; ++i) {
		vector<int> nums = palindromes(i);
		for (int k : nums) if (isPrime(k)) res.emplace_back(k);
	}

	for (int k : res)
		fout << k << endl;

	return 0;
}