#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define lowbit(x) (x&(-x))

const int MAXL = 1e5 + 100;
const int SIGMA_SIZE = 26; //modified when debugging
const int MAXM = 1e5 + 100;
const int MAXN = 1e5 + 100;

typedef pair <int, int> pii;

vector <pii> q[MAXN];
int ans[MAXM];

struct SegmentTree {
	struct Node {
		Node *c[2];
		int v;
		int l, r, m;
		Node (int x, int y): v(0), l(x), r(y), m(x + y >> 1) {}
		void pushup() { v = c[0] -> v + c[1] -> v; }
	} *r;
	SegmentTree (): r(NULL) {}
	
	void make(Node *&u, int l, int r) {
		u = new Node(l, r);
		if (l < r) { make(u -> c[0], l, u -> m); make(u -> c[1], u -> m + 1, r); }
	}
	
	void add(Node *&u, int p, int d) {
//		printf("%d %d\n", depth, u);
//		printf("look up %d in [%d, %d]\n", p, u -> l, u -> r);
		if (u -> l == p && u -> r == p) { u -> v += d; return; }
		add(u -> c[u -> m < p], p, d);
		u -> pushup();
	}
	
	int ask(Node *u, int l, int r) {
		if (r < u -> l || u -> r < l) return 0;
		if (l <= u -> l && u -> r <= r) return u -> v;
		return ask(u -> c[0], l, r) + ask(u -> c[1], l, r);
	}
} st;

struct Trie {
	struct Node {
		int ch[SIGMA_SIZE + 10], p;
		int v, f, d;
		char c;
	} nodes[MAXL];
	int sz, id;
	int rev[MAXL];
	int idx(char c) { return c - 'a'; }
	
	void insert(char *s) {
		int u = 0, n = strlen(s);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B') u = nodes[u].p;
			else if (s[i] == 'P') { nodes[u].v = 1;/*++nodes[u].v;*/ rev[++id] = u; } //(*)
			else {
				int c = idx(s[i]);
				if (!nodes[u].ch[c]) {
					memset(nodes[sz].ch, 0, sizeof nodes[sz].ch);
					nodes[sz].p = u; nodes[sz].v = 0; nodes[sz].c = s[i];
					nodes[u].ch[c] = sz++;
				}
				u = nodes[u].ch[c];
			}
		}
	}
	
	int e[MAXL], nxt[MAXL], c;
	int h[MAXL];
	void bfs() {
		queue <int> q;
		for (; !q.empty(); q.pop());
		nodes[0].f = nodes[0].d = 0;
		for (q.push(0); !q.empty(); ) { //mistaken: add 'q.pop()' in the end !!!
			int u = q.front(); q.pop();
			for (int i = 0; i < SIGMA_SIZE; i++) {
				int v = nodes[u].ch[i];
				if (!v) continue;
				nodes[v].d = nodes[u].d + 1; q.push(v);
				if (nodes[v].d == 1) nodes[v].f = 0;
				else {
					int p = nodes[u].f; //mistaken: nodes[u].f -> u
					for (; p && !nodes[p].ch[i]; p = nodes[p].f);
					nodes[v].f = nodes[p].ch[i];
//					nodes[v].v += nodes[nodes[v].f].v;
				}
			}
		}
		memset(e, 0, sizeof e); memset(nxt, 0, sizeof nxt); c = 0;
		memset(h, 0, sizeof h);
		for (int i = 1; i < sz; i++) { e[++c] = i; nxt[c] = h[nodes[i].f]; h[nodes[i].f] = c; }
	}
	
	int low[MAXL], high[MAXL], stamp;
	void dfs1(int u) {
		low[u] = high[u] = ++stamp;
		for (int i = h[u]; i; i = nxt[i]) 
		{ dfs1(e[i]); high[u] = max(high[u], high[e[i]]); }
	}
	
	void dfs2(int u, int d) {
//		printf("%d\n", d);
//printf("l %d %d\n",u,low[u]);
		st.add(st.r, low[u], 1);
//		printf("add %d at %d(t=%d)\n", nodes[u].v, u, low[u]);
		for (int i = 0; i < (signed)q[u].size(); i++) {
			//printf("%d %d\n", low[q[u].at(i).first], high[q[u].at(i).first]);
			ans[q[u].at(i).second] = st.ask(st.r, low[q[u].at(i).first], high[q[u].at(i).first]);
		}
		for (int i = 0; i < SIGMA_SIZE; i++) if (nodes[u].ch[i]) dfs2(nodes[u].ch[i], d + 1);
		st.add(st.r, low[u], -1);
//		printf("add %d at %d(t=%d)\n", -nodes[u].v, u, low[u]);
	}
	
	void init() {
		memset(nodes[0].ch, 0, sizeof nodes[0].ch); sz = 1; id = 0;
		memset(rev, 0, sizeof rev);
		memset(low, 0, sizeof low);
		memset(high, 0, sizeof high);
		stamp = 0;
//		memset(a, 0, sizeof a);
	}
	
	void debug_output() {
//		for (int i = 0; i < sz; i++) printf("%d %d %d\n", nodes[i].p, nodes[i].v, nodes[i].f);
		for (int i = 0; i < sz; i++) printf("%d %d\n", low[i], high[i]);
	}
	
	int path[MAXL];
	void print(int u) {
		int i = 0;
		for (; u; u = nodes[u].p) path[i++] = u;
		for (; i; ) putchar(nodes[path[--i]].c);
		putchar(' ');
	}
} t;

char cmd[MAXL];

int main(void) {
	freopen("1768.in", "r", stdin);
	freopen("1768.out", "w", stdout);
	t.init();
	scanf("%s", cmd);
	t.insert(cmd);
	t.bfs();
	
	//for(int i=0;i<t.sz;i++)cout<<t.rev[i];puts("");
	
	t.dfs1(0);
	//for(int i=0;i<4;i++)cout<<t.low[i]<<' '<<t.high[i]<<endl;
//	t.debug_output();
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		q[t.rev[y]].push_back(make_pair(t.rev[x], i)); //(*) mistaken q[t.rev[y]] -> q[y]
//		printf("%d %d\n", t.rev[x], t.rev[y]);
//		t.print(t.rev[x]); t.print(t.rev[y]); putchar('\n');
	}
	st.make(st.r, 1, t.stamp);
	t.dfs2(0, 0);
	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}
