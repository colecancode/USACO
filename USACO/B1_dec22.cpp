#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int n;
ll a[100005];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i) cin >> a[i];

	ll price=0, profit=0;
	sort(a, a+n);
	for(int i=0; i<n; ++i)
	if((i==0 || a[i]!=a[i-1]) && (n-i)*a[i] > profit) {
		profit = (n-i)*a[i];
		price = a[i];
	}

	cout << profit << ' ' << price << endl;
	return 0;
}