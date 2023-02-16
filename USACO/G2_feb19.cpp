#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);

	int N; cin >> N;
	int topDish = 0;
	vector<deque<int>> stacks;

	for (int i = 0; i < N; ++i) {
		int id; cin >> id;

		if (id < topDish) {
			cout << i << endl;
			return 0;
		}

		if (stacks.empty() || id > stacks.back().back()) {
			stacks.push_back(deque<int>());
			stacks.back().push_front(id);
			continue;
		}

		bool flag = 0;
		for (int j = 0; j < size(stacks); ++j) {
			if (id < stacks[j].front()) {
				if (j == 0 || id > stacks[j - 1].back()) {
					stacks[j].push_front(id);
					flag = 1;
				}
				break;
			}
		}

		

		if (!flag) {
			for (int i = 0; i < size(stacks); ++i) {
				while (!stacks[i].empty() && id > stacks[i].front()) {
					topDish = stacks[i].front();
					stacks[i].pop_front();
				}

				if (!stacks[i].empty()) {
					stacks[i].push_front(id);
					break;
				} else {
					stacks.erase(begin(stacks) + i--);
				}
			}


		}
	}

	cout << N << endl;

	return 0;
}