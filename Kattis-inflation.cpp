#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	double n, f = 1, capacity, count = 0, temp = 1;
	cin >> n;
	vector<double> canisters(n);
	vector<double> balloons(n);
	for (int i = 0; i < n; i++) {
		cin >> canisters[i];
	}
	for (int i = 0; i < n; i++) {
		balloons[i] = i + 1;
	}
	sort(canisters.begin(), canisters.end());
	for (int i = 0; i < canisters.size(); i++) {
		if (canisters[i] > balloons[i]) {
			cout << "impossible" << "\n";
			return 0;
		}
		else {
			canisters[i] / balloons[i] < f ? f = canisters[i] / balloons[i] : f = f;
		}
	}
	cout << f << "\n";
}