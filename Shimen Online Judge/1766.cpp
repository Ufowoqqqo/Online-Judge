#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 20 + 10;
const int MAXL = 15 + 10;
const int SIGMA_SIZE = 3;
const int MAXK = 1e3 + 100;

struct Trie {
	struct Node {
		int ch[SIGMA_SIZE << 1];
		int v, f, d;
	} nodes[MAXN * MAXL];
	int sz;
	Trie () { memset(nodes[0].ch, 0, sizeof nodes[0].ch); sz = 1; }
	int idx(char c) { return c - 'A'; }
	
	void insert(char *s) {
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
		++nodes[u].v;
	}
	
	void bfs() {
		queue <int> q;
		for (; !q.empty(); q.pop());
		nodes[0].f = nodes[0].d = 0;
		for (q.push(0); !q.empty(); ) {
			int u = q.front(); q.pop();
			for (int i = 0; i < SIGMA_SIZE; i++) {
				int v = nodes[u].ch[i];
				if (!v) { nodes[u].ch[i] = nodes[nodes[u].f].ch[i]; continue; } //(*)
				nodes[v].d = nodes[u].d + 1; q.push(v);
				if (nodes[v].d == 1) nodes[v].f = 0;
				else {
					int p = nodes[u].f;
					for (; p && !nodes[p].ch[i]; p = nodes[p].f);
					nodes[v].f = nodes[p].ch[i];
					nodes[v].v += nodes[nodes[v].f].v;
				}
			}
		}
	}
	
	int f[MAXK][MAXN * MAXL];
	int dp(int l) {
		memset(f, -0x3f, sizeof f); f[0][0] = 0; //(**)
		for (int i = 0; i < l; i++)
			for (int j = 0; j < sz; j++)
				for (int k = 0; k < SIGMA_SIZE; k++) {
					int j1 = nodes[j].ch[k];
					f[i + 1][j1] = max(f[i + 1][j1], f[i][j] + nodes[j1].v);
				}
//		debug_output(l);
		int ans = 0;
		for (int i = 0; i < sz; i++) ans = max(ans, f[l][i]);
		return ans;
	}
	
	void debug_output(int l) {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < SIGMA_SIZE; j++) printf("%d ", nodes[i].ch[j]);
			putchar('\n');
		}
		for (int i = 0; i < sz; i++) printf("%d ", nodes[i].v); putchar('\n');
		for (int i = 1; i <= l; i++) {
			for (int j = 0; j < sz; j++) printf("%d ", f[i][j]);
			putchar('\n');
		}
	}
} t;

char S[MAXN][MAXL];

int main(void) {
	freopen("1766.in", "r", stdin);
	freopen("1766.out", "w", stdout);
	int N, K; scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s", S[i]);
		t.insert(S[i]);
	}
	t.bfs();
	printf("%d\n", t.dp(K));
	return 0;
}
