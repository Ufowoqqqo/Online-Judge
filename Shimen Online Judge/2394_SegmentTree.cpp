//2394.cpp
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int INF = 0x7fffffff;

struct Node {
	int v;
	int l, r, m;
	Node *c[2];
	Node () : v(INF) { c[0] = c[1] = NULL; }
	Node (int x, int y) : v(INF), l(x), r(y), m((x + y) >> 1) { c[0] = c[1] = NULL; }
};

struct SegmentTree {
	Node *r;
	SegmentTree () : r(NULL) {}

	void make(Node *&u, int l, int r) {
		if (!u) u = new Node(l, r);
		if (l == r) return;
		make(u -> c[0], l, u -> m);
		make(u -> c[1], u -> m + 1, r);
	}

	void upd(Node *&u, int p, int x) {
		if (u -> l == p && u -> r == p) u -> v = x;
		else {
			int d = p > u -> m;
			upd(u -> c[d], p, x);
			u -> v = min(u -> v, u -> c[d] -> v);
		}
	}

	int ask(Node *u, int p, int x) {
		if (u -> v > x || u -> r < p) return -1;
		if (u -> l == u -> r) return u -> l;
		if (u -> c[0] -> v <= x) {
			int r = ask(u -> c[0], p, x);
			if (r != -1) return r; else return ask(u -> c[1], p, x);
		} else return ask(u -> c[1], p, x);
	}
} t;

int main(void) {
	freopen("2394.in", "r", stdin);
	freopen("2394.out", "w", stdout);
	int N, Q; scanf("%d%d", &N, &Q);
	t.make(t.r, 1, N);
	for (int i = 0; i < Q; i++) {
		char s[5]; scanf("%s", s);
		if (s[0] == 'M') {
			int X, A; scanf("%d%d", &X, &A);
			t.upd(t.r, A, X);
		}
		if (s[0] == 'D') {
			int Y, B; scanf("%d%d", &Y, &B);
			printf("%d\n", t.ask(t.r, B, Y));
		}
	}
	return 0;
}
