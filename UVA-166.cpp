#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

int min_coins(vector<pair<double,double>> coin_count, vector<int>& ans, double val) {
	if ((val < 0.00001 && val > -0.00001) || val == 0) return 0;
	if (val > 5) return 1000000;
	if (ans[val * 100 + 500] != 1000000) {
		return ans[val * 100 + 500];
	}
	int minimum1 = 1000000;
	int minimum2 = 1000000;
	for (int i = coin_count.size() - 1; i >= 0; i--) {
		if (val < 0) {
			minimum1 = min(minimum1, min_coins(coin_count, ans, val + coin_count[i].first) + 1);
		}
		if (coin_count[i].second > 0) {
				coin_count[i].second--;
				minimum2 = min(minimum2, min_coins(coin_count, ans, val - coin_count[i].first) + 1);
		}
	}
	
	ans[val * 100 + 500] = min(ans[val*100+500], min(minimum1, minimum2));
	return ans[val * 100 + 500];
}

int main()
{
	int five, ten, twenty, fifty, dollar, two_dollar;
	double val;
	while (cin >> five >> ten >> twenty >> fifty >> dollar >> two_dollar) {
		if (five == 0 && ten == 0 && twenty == 0 && fifty == 0 && dollar == 0 && two_dollar == 0) {
			return 0;
		}
		cin >> val;
		vector<pair<double, double>> coin_count(6);
		coin_count[0] = make_pair(.05, five);
		coin_count[1] = make_pair(.10, ten);
		coin_count[2] = make_pair(.20, twenty);
		coin_count[3] = make_pair(.50, fifty);
		coin_count[4] = make_pair(1, dollar);
		coin_count[5] = make_pair(2, two_dollar);
		int total_coins = five + ten + twenty + fifty + dollar + two_dollar;
		vector<int> ans(2001, 1000000);
		cout << right << setw(3) << min_coins(coin_count, ans, val) << '\n';
	}
}