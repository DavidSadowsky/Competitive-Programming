#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
vector<int> segmentTree(4 * 100003, INT_MAX);

int query(int l, int r, int n) {
    int res = INT_MAX;
    while (l < r) {
        if (l % 2 == 1) {
            res = min(res, segmentTree[l]);
            l++;
        }
        if (r % 2 == 1) {
            r--;
            res = min(res, segmentTree[r]);
        }
        l /= 2;
        r /= 2;
    }
    return res;
}

void update(int node, int val, int n) {
    segmentTree[node] = val;
    while (node > 1) {
        node /= 2;
        segmentTree[node] = min(segmentTree[node * 2], segmentTree[node * 2 + 1]);
    }
}

int main()
{
    int n, q, param1, param2;
    cin >> n >> q;
    int com;
    for (int i = 0; i < q; i++) {
        cin >> com >> param1 >> param2;
        if (com == 0) {
            update(param1 + n, param2, n);
        }
        else {
            cout << query(param1 + n, param2 + n + 1, n) << '\n';
        }
    }
}