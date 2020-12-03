#include <iostream> 
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;


int main()
{
	string cmd;
	int cmd_count, energy, gold, query;
	cin >> cmd_count;
	map<int, priority_queue<int>> v;
	for (int i = 0; i < cmd_count; i++) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> energy >> gold;
			v[energy].push(gold);
		}
		else {
			cin >> query;
			long sum = 0;
			int index = query;
			map<int, priority_queue<int>>::iterator it;
			bool check = false;
			while (v.upper_bound(query) != v.begin()) {
				it = v.upper_bound(query);
				--it;
				if (!it->second.empty()) {
					sum += it->second.top();
					query -= it->first;
					it->second.pop();
				}
				else {
					v.erase(it);
				}
			}
			cout << sum << "\n";
		}
	}
}