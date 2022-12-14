class Solution {
public:
	int find(vector<int> &f, int u) {
		return u == f[u] ? u : f[u] = find(f, f[u]);
	}

	void merge(vector<int> &f, int a, int b) {
		int fa = find(f, a), fb = find(f, b);
		f[fa] = fb;
	}

	vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& es, vector<vector<int>>& qs) {
		sort(es.begin(), es.end(), [&](vector<int> i, vector<int> j){
			return i[2] < j[2];
		});
		vector<int> f(n);
		iota(f.begin(), f.end(), 0);
		vector<int> qis(qs.size());
		iota(qis.begin(), qis.end(), 0);
		sort(qis.begin(), qis.end(), [&](int i, int j){
			return qs[i][2] < qs[j][2];
		});
		vector<bool> res(qs.size());
		int k = 0;
		for (int i: qis) {
			while (k < es.size() && es[k][2] < qs[i][2]) {
				merge(f, es[k][0], es[k][1]);
				k++;
			}
			res[i] = find(f, qs[i][0]) == find(f, qs[i][1]);
		}
		return res;
	}
};