#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> l, r;

int main() {
	int n; cin >> n;
	while(n--) {
		char c; cin >> c;
		int m; cin >> m;
		if(c=='L') l.emplace_back(m);
		else r.emplace_back(m);
	}

	sort(begin(l), end(l));
	sort(begin(r), end(r));

	int ans = 1000;
	auto itR = begin(r);
	for(auto it=begin(l); it!=end(l); ++it) {
		itR = upper_bound(itR, end(r), *it);
		int lying = end(r) - itR;
		if (itR != begin(r))
			lying += upper_bound(begin(l), it, *(itR - 1)) - begin(l);
		ans = min(ans, lying);
	}
	
	cout << ans << endl;
	return 0;
}