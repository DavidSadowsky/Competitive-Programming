#include <iostream> 
#include <string>
#include <vector>

using namespace std;

int merge(vector<int> &arr, int l, int r, int c) {
	int left_it = l;
	int right_it = c + 1;
	int copy_it = l;
	vector<int> copy(arr.size());
	int inversion_count = 0;
	while (left_it <= c && right_it <= r) {
		if (arr[left_it] <= arr[right_it]) {
			copy[copy_it] = arr[left_it];
			copy_it++;
			left_it++;
		}
		else {
			inversion_count += right_it - copy_it;
			copy[copy_it] = arr[right_it];
			copy_it++;
			right_it++;
		}
	}
	while (left_it <= c) {
		copy[copy_it] = arr[left_it];
		copy_it++;
		left_it++;
	}
	while (right_it <= r) {
		copy[copy_it] = arr[right_it];
		copy_it++;
		right_it++;
	}
	for (int i = l; i < copy_it; i++) {
		arr[i] = copy[i];
	}
	return inversion_count;
}

long sort(vector<int> &arr, int l, int r) {
	int c;
	long combined;
	long il = 0;
	long ir = 0;
	long inversion_count = 0;
	if (l < r) {
		c = (l + r) / 2;
		il = sort(arr, l, c);
		ir = sort(arr, c + 1, r);
		inversion_count = merge(arr, l, r, c);
	}
	combined = il + ir + inversion_count;
	return combined;
}

int main()
{
	int t, n;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<int> arr(n);
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		long output = sort(arr, 0, n - 1);
		for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
			cout << *it << " ";
		}
		cout << "\n" << output << "\n";
		arr.clear();
	}
}