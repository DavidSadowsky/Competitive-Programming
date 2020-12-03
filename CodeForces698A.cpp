#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Juror {
	int pi;
	int di;
	int num;

	Juror() {
		pi = 0;
		di = 0;
		num = -1;
	}
	Juror(int p, int d, int n) {
		pi = p;
		di = d;
		num = n;
	}
	bool operator>(const Juror& j) const {
		if (abs(pi - di) > abs(j.pi - j.di)) return true;
		if (abs(pi - di) == abs(j.pi - j.di)) {
			if (pi + di < j.pi + j.di) return true;
			else return false;
		}
		return false;
	}
};

struct jnum {
	int num;
	jnum() {
		num = -1;
	}
	jnum(int n) {
		num = n;
	}
	bool operator>(const jnum& j) const {
		return num > j.num;
	}
};

int main()
{
	int n, m, pi, di, count, dval, pval, jury_count = 1;
	while (cin >> n >> m) {
		count = 1;
		dval = 0;
		priority_queue<Juror, vector<Juror>, greater<Juror>> pq;
		priority_queue<jnum, vector<jnum>, greater<jnum>> pqn;
		pval = 0;
		while (cin >> pi >> di) {
			if (pi == 0 && di == 0) {
				break;
			}
			pq.push(Juror(pi, di, count));
			count++;
		}
		while (m > 0) {
			cout << pq.top().pi << endl;
			pval += pq.top().pi;
			dval += pq.top().di;
			pqn.push(pq.top().num);
			pq.pop();
			m--;
		}
		cout << "Jury #" << jury_count << "\nBest jury has value " << pval << " for prosecution and value " << dval << " for defence:\n";
		while (!pqn.empty()) {
			cout << pqn.top().num << " ";
			pqn.pop();
		}
		cout << '\n';
		jury_count++;
	}
}