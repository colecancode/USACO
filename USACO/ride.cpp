/*
ID: coledou1
TASK: ride
LANG: C++
*/

// COLE MILLER
// 11 / 11 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int main() {
	ifstream fin("ride.in");
	ofstream fout("ride.out");

	string comet, group; fin >> comet >> group;
	int n = 1, m = 1;

	for (char c : comet)
		n *= c - 'A' + 1;
	for (char c : group)
		m *= c - 'A' + 1;

	if (n % 47 == m % 47) fout << "GO" << endl;
	else fout << "STAY" << endl;

	return 0;
}