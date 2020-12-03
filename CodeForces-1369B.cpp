#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int t, n;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin.ignore();
		getline(cin, s);
		int zero_count = count(s.begin(), s.end(), '0');
		int one_count = count(s.begin(), s.end(), '1');
		for (int j = 0; j < s.size(); j++) {
			if (zero_count == 0) {
				break;
			}

			else if (s[j] == '1' && s[j + 1] == '1') {
				// no-op
			}
			else if (s[j] == '1' && s[j + 1] == '0' && zero_count > 1) {
				while (s[j + 1] == '0' && zero_count > 1) {
					s.erase(s.begin() + j + 1);
					zero_count--;
				}
			}
			else if (s[j] == '0') {
				zero_count--;
			}
			if (s[j] == '1' && s[j + 1] == '0' && zero_count == 1) {
				int count = j;
				while (s[count] == '1' && count != 0) {
					s.erase(s.begin() + count);
					count--;
				}
				if (s[0] == '1') {
					s.erase(0, 1);
				}
				break;
			}

		}
		cout << s << '\n';
	}
}