// David Sadowsky, Alex Prascak, Jake Haskell

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>> pairs(110);
vector<int> students(110);
int main()
{
	int n, m, a, b, num_groups = 0;
	bool kicked_out = false;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		pairs[a].push_back(b);
		pairs[b].push_back(a);
		students[a]++;
		students[b]++;
	}
	do {
		vector<int> pair(110);
		kicked_out = false;
		for (int i = 0; i <= n; i++) {
			if (students[i] == 1) {
				students[i]--;
				for (int j = 0; j < pairs[i].size(); j++) {
					pair[pairs[i][j]]++;
				}
				kicked_out = true;
			}
		}
		if (kicked_out) {
			num_groups++;
		}
		for (int i = 0; i < pair.size(); i++) {
			students[i] -= pair[i];
		}
	} while (kicked_out);
	cout << num_groups << '\n';
}