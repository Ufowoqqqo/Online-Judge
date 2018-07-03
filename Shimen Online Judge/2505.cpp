#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1e3 + 100;
const int MAXM = 3e5 + 100;
const int LEN = 31; //remember to recover here before submit
const int SIGMA_SIZE = 2;

struct Trie {
	struct Node {
		int ch[SIGMA_SIZE], p;
		int v;
	} nodes[MAXM * LEN * 2];
	int r[MAXM];
	int sz;
	Trie(): sz(1) { memset(nodes[0].ch, 0, sizeof nodes[0].ch); nodes[0].p = -1; memset(r, 0, sizeof r); }
	
	void ins(int u, int v, int s) {
		int t = 1 << LEN - 1; bool ok = true;
		int c;
		for (int i = 0; i + 1 < LEN; i++) {
			c = (bool)(s & t);
//			if (nodes[u].ch[c] && ok) { nodes[v].ch[c] = nodes[u].ch[c];  nodes[nodes[u].ch[c]].p = v; }
//			else {
				memset(nodes[sz].ch, 0, sizeof nodes[sz].ch);
				nodes[sz].p = v; nodes[sz].v = 0; nodes[v].ch[c] = sz++;
//			}
			if (ok) { nodes[v].ch[c ^ 1] = nodes[u].ch[c ^ 1]; if (nodes[u].ch[c ^ 1]) nodes[nodes[u].ch[c ^ 1]].p = v; }
			if (!nodes[u].ch[c]) ok = false; if (ok) u = nodes[u].ch[c];
			v = nodes[v].ch[c];
			t >>= 1;
		}
		c = (bool)(s & t);
		memset(nodes[sz].ch, 0, sizeof nodes[sz].ch);
		nodes[sz].p = v; nodes[sz].v = nodes[u].ch[c] && ok ? nodes[nodes[u].ch[c]].v + 1 : 1; nodes[v].ch[c] = sz++;
		if (ok) { nodes[v].ch[c ^ 1] = nodes[u].ch[c ^ 1]; if (nodes[u].ch[c ^ 1]) nodes[nodes[u].ch[c ^ 1]].p = v; }
		for (; v != -1; v = nodes[v].p)
			nodes[v].v = (nodes[v].ch[0] ? nodes[nodes[v].ch[0]].v : 0) + (nodes[v].ch[1] ? nodes[nodes[v].ch[1]].v : 0);
	}
	
	int calc(int u, int x, int k) {
//		printf("calc(%d, %d, %d)\n", u, x, k);
//		printf("%d(10) = ", k);
		int t = 1 << LEN - 1, cnt = 0;
		for (int i = 0; i < LEN; i++) {
			int ck = (bool)(k & t), cx = (bool)(x & t);
//			putchar(ck + '0');
			if (!ck)
				if (nodes[u].ch[cx]) u = nodes[u].ch[cx]; else { /*puts("(2)");*/ return cnt; }
			else {
				if (nodes[u].ch[cx]) cnt += nodes[nodes[u].ch[cx]].v;
//				printf("cnt += %d at node %d\n", nodes[nodes[u].ch[cx]].v, u);
				if (nodes[u].ch[cx ^ 1]) u = nodes[u].ch[cx ^ 1]; else { /*puts("(2)");*/ return cnt; }
			}
//			printf("cnt = %d\n", cnt);
			t >>= 1;
		}
//		puts("(2)");
		return cnt;
	}
	
	void debug_output() {
		for (int i = 0; i < sz; i++) printf("%d ", nodes[i].v); putchar('\n');
	}
} t;

int x[MAXN], y[MAXM];

int main(void) {
	freopen("2505.in", "r", stdin);
	freopen("2505.out", "w", stdout);
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &y[i]); t.r[i] = t.sz++; t.nodes[t.r[i]].p = -1;
		t.ins(t.r[i - 1], t.r[i], y[i]);
//		t.debug_output();
	}
	int p; scanf("%d", &p);
	for (int i = 0; i < p; i++) {
		int U, D, L, R, K; scanf("%d%d%d%d%d", &U, &D, &L, &R, &K);
//		printf("%d %d\n", L, R);
		K = (D - U + 1) * (R - L + 1) - K + 1;
		long long l = 0, r = 0x7fffffff;
		for (; l + 1 < r; ) {
			long long mid = l + r >> 1; int s = 0;
			for (int i = U; i <= D; i++) {
//				printf("%I64d %I64d %d %d\n", l, r, L, R);
				int res_r = t.calc(t.r[R], x[i], mid), res_l = t.calc(t.r[L - 1], x[i], mid);
				/*
				printf("There are %d number(s) less than %d", res_r, mid);
				printf(" in row %d, col[%d, %d]\n", R, U, D);
				printf("There are %d number(s) less than %d", res_l, mid);
				printf(" in row %d, col[%d, %d]\n", L - 1, U, D);
				printf("There are %d number(s) less than %d", res_r - res_l, mid);
				printf("  in row [%d, %d], col[%d, %d]\n", U, D, L, R);
				*/
				s += res_r - res_l;
			}
			if (s >= K) r = mid; else l = mid;
		}
		printf("%I64d\n", l);
	}
	return 0;
}
