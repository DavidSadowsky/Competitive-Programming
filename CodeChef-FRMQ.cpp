#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

int log2(int n) {
    return 32 - __builtin_clz(n) - 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int processedList[100010][18];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &processedList[i][0]);
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            processedList[i][j] = max(processedList[i][j - 1], processedList[i + (1 << (j - 1))][j - 1]);
        }
    }
    int m, x, y, k;
    scanf("%d%d%d", &m, &x, &y);
    unsigned long long int sum = 0;
    for (int i = 0; i < m; i++) {
        if (y > x) {
            k = log2(y - x + 1);
            sum += max(processedList[x][k], processedList[y - (1 << k) + 1][k]);
        }
        else {
            k = log2(x - y + 1);
            sum += max(processedList[y][k], processedList[x - (1 << k) + 1][k]);
        }
        x += 7;
        y += 11;
        if (x >= n - 1) {
            x %= (n - 1);
        }
        if (y >= n) {
            y %= n;
        }
        
    }
    printf("%llu\n", sum);
}