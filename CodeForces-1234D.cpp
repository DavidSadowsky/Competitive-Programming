#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
#include <math.h>
#include <set>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	string s;
	int q, l, r, pos, query, num_distinct = 0;
	char c;
	cin >> s;
	vector<set<int>> char_indices(26);
	for (int i = 0; i < s.size(); i++) {
		char_indices[s[i] - 'a'].insert(i);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> query;
		if (query == 1) {
			cin >> pos >> c;
			char_indices[s[pos - 1] - 'a'].erase(pos - 1);
			char_indices[c - 'a'].insert(pos - 1);
			s[pos - 1] = c;	
		}
		else {
			cin >> l >> r;
			for (int j = 0; j < 26; j++) {
				if (char_indices[j].lower_bound(l - 1) != char_indices[j].end() && *(char_indices[j].lower_bound(l - 1)) <= r - 1) num_distinct++;
			}
			cout << num_distinct << '\n';
			num_distinct = 0;
		}
	}
}