/*
ID: coledou1
TASK: ttwo
LANG: C++
*/

// COLE MILLER
// 2 / 4 / 23

#include <bits/stdc++.h>
using namespace std;

char grid[10][10];

int deltax[] = { 0, 1, 0, -1 };
int deltay[] = { -1, 0, 1, 0 };

void move(int* x, int* y, int* dir) {
	int nx = *x + deltax[*dir],
		ny = *y + deltay[*dir];

	if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || grid[ny][nx] == '*')
		*dir = (*dir + 1) % 4;
	else {
		*x = nx;
		*y = ny;
	}
}

int main() {
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	int i, x, y, cowx, cowy, johnx, johny, cowdir, johndir;

	cowx = cowy = johnx = johny = -1;

	for (y = 0; y < 10; y++) {
		for (x = 0; x < 10; x++) {
			cin >> grid[y][x];
			if (grid[y][x] == 'C') {
				cowx = x;
				cowy = y;
				grid[y][x] = '.';
			}
			if (grid[y][x] == 'F') {
				johnx = x;
				johny = y;
				grid[y][x] = '.';
			}
		}
	}

	cowdir = johndir = 0;
	for (i = 0; i < 160000 && (cowx != johnx || cowy != johny); i++) {
		move(&cowx, &cowy, &cowdir);
		move(&johnx, &johny, &johndir);
	}

	if (cowx == johnx && cowy == johny) cout << i << endl;
	else cout << "0\n";
	return 0;
}