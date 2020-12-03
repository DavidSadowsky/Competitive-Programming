#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, x, y, mid_y, mid_x, output = 0;
	cin >> n;
	vector<int> x_arr(n);
	vector<int> y_arr(n);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		x_arr[i] = x;
		y_arr[i] = y;
	}
	sort(x_arr.begin(), x_arr.end());
	for (int i = 0; i < n; i++) {
		x_arr[i] -= i;
	}
	sort(x_arr.begin(), x_arr.end());
	sort(y_arr.begin(), y_arr.end());

	mid_x = x_arr[(n - 1) / 2];
	mid_y = y_arr[(n - 1) / 2];
	for (int i = 0; i < n; i++) {
		output += abs(x_arr[i] - mid_x);
		output += abs(y_arr[i] - mid_y);
	}
	cout << output << "\n";
}