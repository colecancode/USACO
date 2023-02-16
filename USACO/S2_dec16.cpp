#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main() {
	ifstream fin("citystate.in");
	ofstream fout("citystate.out");

	int n; fin >> n;
	map<string, map<string, int>> mp;
	while (n--) {
		string city, state;
		fin >> city >> state;
		++mp[city.substr(0, 2)][state];
	}

	int cnt = 0;
	for (auto [state, tbl] : mp) {
		for (auto [state2, n] : tbl) { // n = amt of cities starting with state2 in state1
			if (state != state2) {
				cnt += n * mp[state2][state];
				mp[state2][state] = 0;
			}
		}
	}

	fout << cnt << endl;

	return 0;
}