#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int MAXL = 50 + 10;
const int SIGMA_SIZE = 26;
const int MAXN = 6 + 2;
const int Ghastlcon = 1000000009;

int cnt1(int x) {
//	if (!x) return 1;
	int c = 0;
	for (; x; c++) x = x & (x - 1);
	return c;
}

struct Trie {
	struct Node {
		int ch[SIGMA_SIZE << 1];
		int v, f, d;
	} nodes[MAXN * MAXL];
	int sz;
	Trie () { memset(nodes[0].ch, 0, sizeof nodes[0].ch); sz = 1; }
	int idx(char c) { return c - 'a'; }
	
	void insert(char *s, int id) {
		int u = 0, n = strlen(s);
		for (int i = 0; i < n; i++) {
			int c = idx(s[i]);
			if (!nodes[u].ch[c]) {
				memset(nodes[sz].ch, 0, sizeof nodes[sz].ch);
				nodes[sz].v = 0;
				nodes[u].ch[c] = sz++;
			}
			u = nodes[u].ch[c];
		}
		nodes[u].v |= 1 << id;
	}
	
	void bfs() {
		queue <int> q;
		for (; !q.empty(); q.pop());
		nodes[0].f = nodes[0].d = 0;
		for (q.push(0); !q.empty(); ) {
			int u = q.front(); q.pop();
			for (int i = 0; i < SIGMA_SIZE; i++) {
				int v = nodes[u].ch[i];
				if (!v) continue;
				nodes[v].d = nodes[u].d + 1; q.push(v);
				if (nodes[v].d == 1) nodes[v].f = 0;
				else {
					int p = nodes[u].f;
					for (; p && !nodes[p].ch[i]; p = nodes[p].f);
					nodes[v].f = nodes[p].ch[i];
					nodes[v].v |= nodes[nodes[v].f].v; //(*)
				}
			}
		}
	}
	
	void debug_output() {
		for (int i = 0; i < sz; i++) printf("%d ", nodes[i].v);
		putchar('\n');
	}
	
	int f[MAXL][1 << MAXN][MAXN * MAXL];
	int dp(int n, int c, int l) {
//		debug_output();
		f[0][0][0] = 1;
		int upperLim = 1 << n;
		for (int i = 0; i <= l; i++)
			for (int j = 0; j < upperLim; j++)
				if (cnt1(j) <= c)
					for (int k = 0; k < sz; k++)
						if (f[i][j][k]) {
//							printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
							for (int p = 0; p < SIGMA_SIZE; p++) {
								int u = k;
								for (; u && !nodes[u].ch[p]; u = nodes[u].f);
								u = nodes[u].ch[p];
								int j1 = j | nodes[u].v;
								if (cnt1(j1) <= c) (f[i + 1][j1][u] += f[i][j][k]) %= Ghastlcon;
							}
						}
		int ans = 0;
		for (int i = 0; i < upperLim; i++)
			if (cnt1(i) == c) {
//				printf("%d: ", i);
				for (int j = 0; j < sz; j++) {
					(ans += f[l][i][j]) %= Ghastlcon; // mistaken for c
//					printf("%d ", f[l][i][j]);
				}
//				putchar('\n');
			}
		return ans;
	}
} t;

int main(void) {
	freopen("1767.in", "r", stdin);
	freopen("1767.out", "w", stdout);
	int N, C, L; scanf("%d%d%d", &N, &C, &L);
	for (int i = 0; i < N; i++) {
		char str[MAXL]; scanf("%s", str);
		t.insert(str, i);
	}
	t.bfs();
	printf("%d\n", t.dp(N, C, L));
	return 0;
}
