#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int palindrome(string word, int start, int end, vector<vector<int>> &ans) {
	if (start > end) return 0;
	if (start == end) return 1;
	if (word[start] == word[end]) {
		ans[start][end] = 2 + palindrome(word, start + 1, end - 1, ans); return ans[start][end];
	}
	if (ans[start][end] > 0) return ans[start][end];
	ans[start][end] = max(palindrome(word, start + 1, end, ans), palindrome(word, start, end - 1, ans));
	return ans[start][end];
}

int main()
{
	int t;
	string word;
	cin >> t;
	cin.ignore();
	for (int i = 0; i < t; i++) {
		getline(cin, word);
		vector<vector<int>> ans(word.size(), vector<int>(word.size(), -1));
		cout << palindrome(word, 0, word.size() - 1, ans) << '\n';
	}
}