#include <iostream>
using namespace std;

bool arr[200005];

int main() {
	int n, i=0; cin >> n;
	for(int j=0; j<n/2; ++j) {
		char a, b; cin >> a >> b;
		if(a=='G' && b=='H') arr[i++]=1;
		else if(a=='H' && b=='G') i++;
	}
	
	int ans=-arr[0];
	bool flag=1;
	for(int j=0; j<i; ++j) {
		if(arr[j]) {
			if(flag) ans += 2, flag=0;
		} else flag=1;
	}

	cout << ans << endl;
	return 0;
}