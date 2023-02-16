/*
ID: coledou1
TASK: milk2
LANG: C++
*/

// NOT MY CODE
// ?? / ?? / ??

#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

#define forit(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

bool cmp(const ii& left, const ii& right) {
	return (left.first < right.first);
}

int main() {

	ofstream fout("milk2.out");
	ifstream fin("milk2.in");

	vii vec;
	int n; fin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; fin >> a >> b;
		vec.pb(mp(a, b));
	}

	sort(vec.begin(), vec.end(), cmp);

	int idle = 0;
	int left = vec[0].first; int current_greatest = vec[0].second;
	int cont = current_greatest - left;

	for (int i = 1; i < n; i++) {
		if (vec[i].first > current_greatest) {
			if (current_greatest - left > cont) cont = current_greatest - left;
			if (vec[i].first - current_greatest > idle) idle = vec[i].first - current_greatest;
			current_greatest = vec[i].second;
			left = vec[i].first;
		}
		if (vec[i].second > current_greatest) current_greatest = vec[i].second;
	}
	if (current_greatest - left > cont) cont = current_greatest - left;

	fout << cont << " " << idle << "\n";

	return 0;
}