//2394.cpp
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define lb(x) (x&(-x))

const int MAXN = 2e5 + 100;
const int INF = 0x7f7f7f7f;

struct Node {
	Node *c[2];
	int f, v;

	Node (int x) {
		c[0] = c[1] = NULL;
		f = rand(); v = x;
	}
};

struct Treap {
	Node *r;
	Treap () : r(NULL) {}

	void rotate(Node *&u, int d) {
		Node *t = u -> c[d ^ 1];
		u -> c[d ^ 1] = t -> c[d];
		t -> c[d] = u;
		u = t;
	}

	void ins(Node *&u, int x) {
		if (!u) { u = new Node(x); return; }
		int t = x > u -> v;
		ins(u -> c[t], x);
		if (u -> c[t] -> f < u -> f) rotate(u, t ^ 1);
	}

	int ask(Node *u, int x) {
		if (!u) return INF;
		if (u -> v < x) return ask(u -> c[1], x);
		if (u -> v == x) return x;
		if (u -> v > x) return min(u -> v, ask(u -> c[0], x));
	}
} tr[MAXN];

char o[MAXN];
int s[MAXN], a[MAXN];

pair <int, int> d[MAXN];

int main(void) {
	freopen("2394.in", "r", stdin);
	freopen("2394.out", "w", stdout);
	int N, Q; scanf("%d%d", &N, &Q);
	for (int i = 0; i < Q; i++) {
		char t[2]; scanf("%s%d%d", t, &s[i], &a[i]);
		o[i] = t[0]; d[i].first = s[i]; d[i].second = i;
	}
	sort(d, d + Q); int c = 1;
	for (int i = 0; i < Q; i++) {
		s[d[i].second] = c;
		c += d[i].first != d[i + 1].first;
	}
	for (int i = 0; i < Q; i++) {
//		printf("i = %d\n", i);
		if (o[i] == 'M')
			for (int j = s[i]; j <= Q; j += lb(j)) {
//				printf("add : %d\n", j);
				tr[j].ins(tr[j].r, a[i]);
			}
		if (o[i] == 'D') {
			int m = Q + 1;
			for (int j = s[i]; j; j -= lb(j)) {
//				printf("query : %d\n", j);
				m = min(m, tr[j].ask(tr[j].r, a[i]));
			}
			printf("%d\n", m == Q + 1 ? -1 : m);
		}
	}
	return 0;
}
