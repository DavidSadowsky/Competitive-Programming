#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t, n, x;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> x;
		int wealthy_count = 0, max_wealthy, burles;
		long long int total_burles = 0;
		vector<int> citizens_wealth(n);
		bool reformed = false;
		for (int j = 0; j < n; j++) {
			cin >> burles;
			if (burles >= x) {
				wealthy_count++;
			}
			total_burles += burles;
			citizens_wealth[j] = burles;
		}
		sort(citizens_wealth.begin(), citizens_wealth.end());
		for (int k = 0; k < n; k++) {
			if (total_burles / (n - k) >= x) {
				cout << n - k << "\n";
				reformed = true;
				break;
			}
			else {
				total_burles -= citizens_wealth[k];
			}
		}
		if (!reformed) {
			cout << wealthy_count << "\n";
		}
	}
}