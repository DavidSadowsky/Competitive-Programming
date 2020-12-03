#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
#include <math.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (k == 1) {
        cout << *min_element(arr.begin(), arr.end()) << '\n';
    }
    else if (k == 2) {
        cout << max(arr[0], arr[arr.size() - 1]);
    }
    else {
        cout << *max_element(arr.begin(), arr.end()) << '\n';
    }
}