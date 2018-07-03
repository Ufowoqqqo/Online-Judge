//2395.cpp
#include <algorithm>
//#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int MAXN = 12e4 + 5;

struct Sheet {
	int A, B, C, D;
	int p;
} s[MAXN << 1];

/*
struct Side {
	int y, x1, x2;
	int p, t;

	bool operator < (const Side x) const {
		if (y != x.y) return y < x.y;
		if (t == 2)
			if (x.t == 0)  return false; else if (x.t == 1) return true;
		return p < x.p;
	}

} si[MAXN << 1];
int si_p = 0;
*/

/*
bool cmp(Side a, Side b) {
	if (a.y != b.y) return a.y < b.y;
	if (a.t == 2) {
		if (b.t == 0) return false; else if (b.t == 1) return true;
	}
	return a.p < b.p;
}
*/

struct SegmentTree {
	struct SegNode {
		SegNode *c[2];
		int l, r, m;
		int v; bool d;
		SegNode (int a, int b, int x) : l(a), r(b), m((a + b) >> 1), v(x), d(false) { c[0] = c[1] = NULL; }
		void p() {
			c[0] -> v = c[1] -> v = v;
			c[0] -> d = c[1] -> d = true;
			d = false;
		}
	} *r;
	SegmentTree () { r = NULL; }
	void make(SegNode *&u, int l, int h) {
//		cerr << l << ' ' << h << endl;
		u = new SegNode(l, h, 0);
		if (l == h) return;
		make(u -> c[0], l, u -> m);
		make(u -> c[1], u -> m + 1, h);
	}
	int ask(SegNode *u, int p) {
		if (u -> l == p && u -> r == p) return u -> v;
		if (u -> d) u -> p();
		return ask(u -> c[p > u -> m], p);
	}
	void upd(SegNode *&u, int l, int h, int x) {
		if (l <= u -> l && u -> r <= h) { u -> v = x; u -> d = true; return; }
		if (h < u -> l || u -> r < l) return ;
		if (u -> d) u -> p();
		upd(u -> c[0], l, h, x); upd(u -> c[1], l, h, x);
	}
	void del(SegNode *&u) {
		if (!u) return;
		del(u -> c[0]); del(u -> c[1]);
		delete u;
	}
} st;

/*
struct Treap {
	struct TreapNode {
		TreapNode *c[2];
		int f, v, w;
		TreapNode (int x) : f(rand()), v(x), w(1) { c[0] = c[1] = NULL; }
		void upd() { w = (c[0] ? c[0] -> w : 0) + 1 + (c[1] ? c[1] -> w : 0); }
	} *r;
	Treap () { r = NULL; }
	void rotate(TreapNode *&u, int d) {
		TreapNode *s = u -> c[d ^ 1];
		u -> c[d ^ 1] = s -> c[d]; u -> upd();
		s -> c[d] = u; s -> upd();
		u = s;
	}
	void add(TreapNode *&u, int x) {
		if (!u) { u = new TreapNode(x); return; }
		if (x == u -> v) return ;
		int t = x > u -> v;
		add(u -> c[t], x);
		if (u -> c[t] -> f < u -> f) rotate(u, t ^ 1); else u -> upd();
	}
	void addto(TreapNode *&s, TreapNode *&d) {
		if (!s) return;
		add(d, s -> v);
		addto(s -> c[0], d); addto(s -> c[1], d);
		delete s;
	}
} tr[MAXN];
*/

pair <int, pair<int, int> > X[MAXN * 3], Y[MAXN * 3];
int X_p = 0, Y_p = 0;

int K[MAXN], p[MAXN << 1], ans[MAXN];

vector <int> f[MAXN << 1][3], h[MAXN], edges[MAXN];

set <int> tr[MAXN];

void solve(int cur) {
	for (int i = 0; i < (signed)h[cur].size(); i++) tr[cur].insert(K[h[cur][i]]);
//	tr[cur].add(tr[cur].r, 0);
	for (int i = 0; i < (signed)edges[cur].size(); i++) {
		int to = edges[cur][i]; solve(to);
		if (tr[cur].size() < tr[to].size()) swap(tr[cur], tr[to]);
		for (set<int>::iterator it = tr[to].begin(); it != tr[to].end(); it++) tr[cur].insert(*it);
		tr[to].clear();
//		tr[to].addto(tr[to].r, tr[cur].r);
	}
	ans[cur] = tr[cur].size();
}

int main(void) {
	freopen("2395.in", "r", stdin);
	freopen("2395.out", "w", stdout);
	int N, M, c; scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d%d%d", &s[i].A, &s[i].B, &s[i].C, &s[i].D); s[i].p = i;
		X[X_p++] = make_pair(s[i].A, make_pair(i, 0)); X[X_p++] = make_pair(s[i].C, make_pair(i, 2));
		Y[Y_p++] = make_pair(s[i].B, make_pair(i, 1)); Y[Y_p++] = make_pair(s[i].D, make_pair(i, 3));
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &s[N + i].A, &s[N + i].B, &K[i]);
		s[N + i].C = s[N + i].A; s[N + i].D = s[N + i].B; s[N + i].p = N + i;
		X[X_p++] = make_pair(s[N + i].A, make_pair(N + i, 0));
		Y[Y_p++] = make_pair(s[N + i].B, make_pair(N + i, 1));
	}
//	for (int i = 0; i < X.size(); i++) printf("%d %d %d\n", X[i].first, X[i].second.first, X[i].second.second);
	sort(X, X + X_p); sort(Y, Y + Y_p);
//	cerr << "input";
	c = 1;
	for (int i = 0; i < X_p; i++) {
//		printf("%d %d %d\n", X[i].first, X[i].second.first, X[i].second.second);
		int t = X[i].second.second, po = X[i].second.first;
		if (t == 0) s[po].A = c; if (t == 2) s[po].C = c;
		c += X[i].first != X[i + 1].first;
	}
	int maxx = c - 1; c = 1;
	for (int i = 0; i < Y_p; i++) {
		int t = Y[i].second.second, po = Y[i].second.first;
		if (t == 1) s[po].B = c; if (t == 3) s[po].D = c;
		c += Y[i].first != Y[i + 1].first;
	}
	int maxy = c - 1;
	for (int i = 1; i <= N; i++) {
//		si[si_p++] = (Side){s[i].B, s[i].A, s[i].C, i, 0};
		f[s[i].B][0].push_back(i);
//		si[si_p++] = (Side){s[i].D, s[i].A, s[i].C, i, 1};
		f[s[i].D][1].push_back(i);
	}
	for (int i = 1; i <= M; i++)
		f[s[N + i].B][2].push_back(i); //si[si_p++] = (Side){s[N + i].B, s[N + i].A, s[N + i].A, N + i, 2};
//	for (int i = 0; i < N; i++) printf("%d %d %d %d\n", s[i].A, s[i].B, s[i].C, s[i].D);
//	for (int i = 0; i < M; i++) printf("%d %d\n", s[N + i].A, s[N + i].B);

	/*
	printf("%d\n", si_p);
	for (int i = 0; i < si_p; i++) printf("%d %d %d %d %d\n", si[i].y, si[i].x1, si[i].x2, si[i].p, si[i].t); putchar('\n');
	st.make(st.r, 1, X[X_p - 1].first); //sort(si, si + si_p);
	for (int i = 0; i + 1 < si_p; i++)
		for (int j = i + 1; j < si_p; j++)
			if (!(si[i] < si[j])) swap(si[i], si[j]);
	printf("%d\n", si_p);
	for (int i = 0; i < si_p; i++) printf("%d %d %d %d %d\n", si[i].y, si[i].x1, si[i].x2, si[i].p, si[i].t); putchar('\n');
	for (int i = 0; i < si_p; i++) {
		printf("%d %d %d %d %d\n", si[i].y, si[i].x1, si[i].x2, si[i].p, si[i].t);
		if (si[i].t == 0) {
			p[si[i].p] = st.ask(st.r, si[i].x1);
			++de[p[si[i].p]];
			st.upd(st.r, si[i].x1, si[i].x2, si[i].p);
		}
		if (si[i].t == 1) st.upd(st.r, si[i].x1, si[i].x2, p[si[i].p]);
		if (si[i].t == 2) { p[si[i].p] = st.ask(st.r, si[i].x1); ++de[p[si[i].p]]; }
	}
	st.del(st.r);
	*/
//	cerr << "lsh"; printf("%d\n", maxx); //return 0;
	st.make(st.r, 1, maxx);
	for (int i = 1; i <= maxy; i++) {
//		cerr << i;
		int po;
		for (int j = 0; j < (signed)f[i][0].size(); j++) {
			po = f[i][0][j];
			p[po] = st.ask(st.r, s[po].A); edges[p[po]].push_back(po);
			st.upd(st.r, s[po].A, s[po].C, po);
		}
		for (int j = 0; j < (signed)f[i][2].size(); j++) {
			po = f[i][2][j];
			p[N + po] = st.ask(st.r, s[N + po].A);
			h[p[N + po]].push_back(po);
		}
		for (int j = 0; j < (signed)f[i][1].size(); j++) {
			po = f[i][1][j];
			st.upd(st.r, s[po].A, s[po].C, p[po]);
		}
	}
	st.del(st.r);
//	for (int i = 1; i <= N + M; i++) printf("%d ", p[i]);
//	cerr << "smx";
	/*
	queue <int> q; for (; !q.empty(); q.pop());
	for (int i = 1; i <= M; i++) {
		q.push(N + i); //printf("%d\n", q.front());
		tr[N + i].add(tr[N + i].r, K[i]);
	}
	for (int i = 1; i <= N; i++) if (!de[i]) --de[p[i]];
	for (; !q.empty(); ) {
		int u = q.front();
		q.pop();
		ans[u] = tr[u].r -> w;
		if (p[u]) { tr[u].addto(tr[u].r, tr[p[u]].r); if (!(--de[p[u]]) && p[u]) q.push(p[u]); }
//		printf("%d\n", u);
	}
	*/
	
	solve(0);
	for (int i = 1; i <= N; i++) printf("%d\n", ans[i]);
	return 0;
}
