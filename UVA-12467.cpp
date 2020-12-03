#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

char* a[1000010], b[1000010];

int main()
{
    int t, i, j, len;
    string a, b;
    cin >> t;
    while (t) {
        cin >> b;
        a = b;
        reverse(b.begin(), b.end());
        vector<int> table(a.size() + 1);
        table[0] = -1;
        i = 0;
        j = -1;
        len = 0;
        while (i < a.size()) {
           // cout << "test" << endl;
            while (j > -1 && a[i] != a[j]) j = table[j];
            i++;
            j++;
            table[i] = j;
        }
        // cout << "test1" << endl;
        i = 0, j = 0;
        while (i < a.size()) {
           // cout << "test2" << endl;
            while (j > -1 && b[i] != a[j]) j = table[j];
            i++;
            j++;
            len = max(len, j);
        }
        len--;
        while (len >= 0) {
            cout << a[len];
            len--;
        }
        cout << '\n';
        t--;
    }
}