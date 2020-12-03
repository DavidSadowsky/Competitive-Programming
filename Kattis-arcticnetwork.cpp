#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct outpost {
	int node;
	double x;
	double y;
	outpost() {
		node = 0;
		x = 0;
		y = 0;
	}
	outpost(double num, double x_cord, double y_cord) {
		node = num;
		x = x_cord;
		y = y_cord;
	}
};

struct edge {
	outpost p1;
	outpost p2;
	double d;

	edge() {
		d = 0;
	}
	edge(outpost a, outpost b) {
		d = sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
		p1 = a;
		p2 = b;
	}
	bool operator>(const edge& l) const {
		return d < l.d;
	}
};

struct DisjointSet {
	vector<double> parent;
	vector<double> rank;

	DisjointSet() {
		// no-op
	}
	DisjointSet(vector<outpost> outposts) {
		vector<double> parent_t(outposts.size());
		vector<double> rank_t(outposts.size(), 0);
		parent = parent_t;
		rank = rank_t;
		for (vector<outpost>::iterator it = outposts.begin(); it != outposts.end(); it++) {
			parent[it->node] = it->node;
		}
	}

	double find(double x) {
			if (x != parent[x]) {
				parent[x] = find(parent[x]);
			}
			return parent[x];
	}

	void merge(double a, double b) {
		a = find(a);
		b = find(b);
		if (rank[a] > rank[b]) parent[b] = a;
		else parent[a] = b;
		if (rank[a] == rank[b]) rank[b]++;
	}
};

vector<edge> kruskal(vector<edge> graph, vector<outpost> outposts) {
	double min_weight = 0;
	DisjointSet tree_components(outposts);
	vector<edge> edges;
	for (vector<edge>::iterator it = graph.begin(); it != graph.end(); it++) {
		double outpost_1 = it->p1.node;
		double outpost_2 = it->p2.node;
		int set_outpost_1 = tree_components.find(outpost_1);
		int set_outpost_2 = tree_components.find(outpost_2);
		if (set_outpost_1 != set_outpost_2) {
			min_weight += it->d;
			tree_components.merge(set_outpost_1, set_outpost_2);
			edges.push_back(*it);
		}
	}
	return edges;
}

int main()
{
	double n;
	cin >> n;
	double test_count = 0;
	while (test_count < n) {
		double s, p, x, y;
		double d = 0;
		cin >> s >> p;
		vector<outpost> outposts(p);
		vector<edge> edges(p * p);
		for (int i = 0; i < p; i++) {
			cin >> x >> y;
			outposts[i] = outpost(i, x, y);
		}
		int count = 0;
		for (int i = 0; i < p; i++) {
			for (int j = i + 1; j < p; j++) {
				edges[count] = edge(outposts[i], outposts[j]);
				count++;
			}
		}
		sort(edges.begin(), edges.end(), greater<edge>());
		vector<edge> mst = kruskal(edges, outposts);
		sort(mst.begin(), mst.end(), greater<edge>());
		d = mst[mst.size() - s].d;
		std::cout << std::setprecision(2) << std::fixed;
		cout << d << "\n";
		test_count++;
	}
}