#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	string a, b;
	int k, d = 1, c, w;
	cin >> a >> b >> k;
	vector<vector<int>> trie(a.size() * a.size(), vector<int>(b.size()));
	for (int i = 0; i < a.size(); i++) {
		w = 0, c = 1;
		for (int j = i; j < a.size(); j++) {
			if (b[a[j] - 'a'] == '0') w++;
			if (w > k) break;
			if (trie[c][a[j] - 'a'] == 0) {
				d++;
				trie[c][a[j] - 'a'] = d;
			}
			c = trie[c][a[j] - 'a'];
		}
	}
	cout << d - 1 << '\n';
}