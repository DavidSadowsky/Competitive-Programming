#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map> 

using namespace std;

int char_conversion(int num) {
    char curr;
    switch (num)
    {
    case 0:
        curr = '0';
        break;
    case 1:
        curr = '1';
        break;
    case 2:
        curr = '2';
        break;
    case 3:
        curr = '3';
        break;
    case 4:
        curr = '4';
        break;
    case 5:
        curr = '5';
        break;
    case 6:
        curr = '6';
        break;
    case 7:
        curr = '7';
        break;
    case 8:
        curr = '8';
        break;
    case 9:
        curr = '9';
        break;
    default:
        curr = ' ';
        break;
    }
    return curr;
}

int good(string s) {
    int min_dels = s.size() - 2;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int count = 0;
            int curr_char = i;
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == char_conversion(curr_char)) {
                    curr_char == i ? curr_char = j : curr_char = i;
                }
                else {
                    count++;
                }
            }
            curr_char == i ? min_dels = min(min_dels, count) : min_dels = min_dels;
        }
    }
    return min_dels;
}

int main()
{
    int t;
    string s;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        getline(cin, s);
        cout << good(s) << '\n';
    }
}