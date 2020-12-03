#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

struct Interval {
	double left;
	double right;

	Interval() {
		left = 0;
		right = 0;
	}

	Interval(double l, double r) {
		left = l;
		right = r;
	}
};

int main()
{
	int sprinkler_count, count, index = 0;
	double n, l, w, left, right, x, r, max_r, max_r1;
	while (cin >> n >> l >> w) {
		map<double, double> maxes;
		maxes[0] = -1;
		for (int i = 0; i < n; i++) {
			cin >> x >> r;
			left = x - sqrt((r * r) - ((w / 2) * (w / 2)));
			left < 0 ? left = 0 : left = left;
			right = x + sqrt(((r * r) - ((w / 2) * (w / 2))));
			right > maxes[left] ? maxes[left] = right : maxes[left] = maxes[left];
		}
		if (maxes[0] == -1) {
			cout << -1 << "\n";
		}
		else {
			max_r = maxes[0];
			sprinkler_count = 1;
			count = 1;
			bool assigned = false;
			bool end = false;
			double max_r1 = maxes[0];
			for (map<double, double>::iterator it = maxes.begin()++; it != maxes.end(); it++) {
				if (it->first > max_r) {
					break;
				}
				while (it->first <= max_r) {
					if (it->second > max_r) {
						max_r1 = max(max_r1, it->second);
						assigned = true;
					}
					if (it == maxes.end() || max_r1 >= l) {
						end = true;
						break;
					}
					it++;
				}
				if (assigned) {
					sprinkler_count++;
					assigned = false;
				}
				if (max_r1 > max_r) {
					max_r = max_r1;
				}
				if (max_r >= l) {
					break;
				}
				if (end) {
					break;
				}
				it--;
			}
			max_r >= l ? cout << sprinkler_count << "\n" : cout << -1 << "\n";
		}
	}
}