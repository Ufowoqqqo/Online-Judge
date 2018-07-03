#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXL = 32 + 10;
const int SIGMA_SIZE = 2 + 1;

struct Edge { int v, w; Edge *nxt; } e[MAXN << 1], *cur, *h[MAXN];

int d[MAXN];
void dfs(int u, int p) {
	for (Edge *i = h[u]; i; i = i -> nxt)
		if (i -> v != p) { d[i -> v] = d[u] ^ i -> w; dfs(i -> v, u); }
}

struct Trie {
	int sz, ch[MAXN * MAXL][SIGMA_SIZE], v[MAXN * MAXL];
	void init() { sz = 1; memset(ch, 0, sizeof ch); }
	void ins(int x, int y, int t) {
		if (y < 0) { v[x] = t; return; }
		int z = (t >> y) & 1; if (!ch[x][z]) ch[x][z] = ++sz;
		ins(ch[x][z], y - 1, t);
	}
	int match(int x, int y, int t) {
		if (y < 0) return v[x];
		int z = (t >> y) & 1;
		return match(ch[x][z ^ 1] ? ch[x][z ^ 1] : ch[x][z], y - 1, t);
	}
} t;

int main(void) {
	for (int n; ~scanf("%d", &n); ) {
		cur = e; memset(h, 0, sizeof h);
		for (int i = 1; i < n; i++) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w); ++u; ++v;
			*cur = (Edge){v, w, h[u]}; h[u] = cur++;
			*cur = (Edge){u, w, h[v]}; h[v] = cur++;
		}
		dfs(1, 0); t.init(); t.ins(1, 30, 0);
		int ans = 0;
		for (int i = 1; i <= n; i++) { ans = max(ans, d[i] ^ t.match(1, 30, d[i])); t.ins(1, 30, d[i]); }
		printf("%d\n", ans);
	}
	return 0;
}
