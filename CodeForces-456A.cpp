#include <iostream> 
#include <string>
#include <vector>
 
using namespace std;

int main()
{
	int n, p, q;
	int laptops_checked = 0;

	// read in # of laptops
	cin >> n;

	// Declare key-value array to link dorms with their associated # of rooms
	vector<int> laptops(n);

	// Assign laptop price to quality in order
	while (laptops_checked < n) {
		cin >> p >> q;
		laptops[p - 1] = q;
		laptops_checked++;
	}

	// Main algorithm
	for (int i = 1; i < n; i++) {
		if (laptops[i] < laptops[i - 1]) {
			cout << "Happy Alex";
			return 0;
		}
	}
	cout << "Poor Alex";
}