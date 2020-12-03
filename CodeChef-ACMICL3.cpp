#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

int main()
{
    int t, n;
    string name;
    cin >> t;
    for (int i = 0; i < t; i++) {
        map<string, int> nameFreq;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> name;
            nameFreq[name]++;
        }
        int numPeople = 0;
        for (map<string, int>::iterator it = nameFreq.begin(); it != nameFreq.end(); it++) {
            if (it->second % 2) numPeople++;
        }
        cout << numPeople << '\n';
    }
}