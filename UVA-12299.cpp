#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;
vector<int> arr(1000003);
vector<int> segmentTree(4 * 1000003, INT_MAX);
vector<int> ops(50);

void build(int n) {
    for (int i = 0; i < n; i++) {
        segmentTree[n + i] = arr[i];
    }
    for (int i = n - 1; i > 0; --i) {
        segmentTree[i] = min(segmentTree[i * 2],segmentTree[i * 2 + 1]);
    }
}

int query(int l, int r, int n) {
    int res = INT_MAX;
    while (l < r) {
        if(l % 2 == 1) {
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
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(n);
    string op;
    for (int i = 0; i < q; i++) {
        cin >> op;
        if (op[0] == 'q') {
            int param1, param2;
            string p1 = "", p2 = "";
            for (int j = 0; j < op.size(); j++) {
                if (p1.size() == 0) {
                    while (isdigit(op[j])) {
                        p1 += op[j];
                        j++;
                    }
                }
                else {
                    while (isdigit(op[j])) {
                        p2 += op[j];
                        j++;
                    }
                }
            }
            param1 = stoi(p1);
            param2 = stoi(p2);
            cout << query(param1 + n - 1, param2 + n, n) << '\n';
        }
        else {
            int count = 0;
            for (int j = 0; j < op.size(); j++) {
                string temp = "";
                while (j < op.size() && isdigit(op[j])) {
                    temp += op[j];
                    j++;
                }
                if (temp.size() > 1) {
                    ops[count] = stoi(temp);
                    count++;
                }
                else if (temp.size() > 0) {
                    ops[count] = temp[0] - '0';
                    count++;
                }
            }
            vector<int> valsToShift(count + 1);
            for (int j = 0; j < count; j++) {
                valsToShift[j] = segmentTree[ops[j] + n - 1];;
            }
            
            for (int j = 0; j < count; j++) {
                update(ops[j] + n - 1, valsToShift[(j + 1) % count], n);
            }
        }
    }
}