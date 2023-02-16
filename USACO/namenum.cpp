/*
ID: coledou1
TASK: namenum
LANG: C++
*/

// COLE MILLER
// 11 / 11 / 22

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

unordered_map<int, string> mp = {
	{2, "ABC"},
	{3, "DEF"},
	{4, "GHI"},
	{5, "JKL"},
	{6, "MNO"},
	{7, "PRS"},
	{8, "TUV"},
	{9, "WXY"}
};

int main() {
	ifstream fin("namenum.in");
	ifstream dict("dict.txt");
	ofstream fout("namenum.out");

	vi id;
	char c;
	while (fin >> c)
		id.push_back(c - '0');
	
	string first, last;
	for (int n : id) {
		first.push_back(mp[n].front());
		last.push_back(mp[n].back());
	}

	vs res;
	string name;
	while (dict >> name) {
		if (name > last) {
			if (res.empty())
				fout << "NONE" << endl;
			else
				for (string s : res)
					fout << s << endl;
			return 0;
		}
		else if (name.size() == id.size() && name >= first) {
			int i = 0;
			for (; i < name.size(); ++i) {
				if (mp[id[i]].find(name[i]) == string::npos)
					break;
			}
			if (i == name.size())
				res.push_back(name);
		}
	}

	return 0;
}