//2392.cpp
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 2e4 + 100;
const int MAXL = 20;

struct Node {
	char v[MAXL];
	Node *c[2];
	int fix, w;

	Node (const char *t, int l) {
		memcpy(v, t, l * sizeof(char)); v[l] = '\0';
		c[0] = c[1] = NULL; fix = rand(); w = 1;
	}
};

struct Treap {
	Node *r;
	Treap () : r(NULL) {}

	void clear() { r = NULL; }

	void rotate(Node *&u, int d) {
		Node *ch = u -> c[d ^ 1];
		u -> c[d ^ 1] = ch -> c[d];
		ch -> c[d] = u;
		u = ch;
	}

	void insert(Node *&u, char *v, int l) {
		if (!u) { u = new Node(v, l); return; }
		int cmp = strcmp(v, u -> v);
		if (!cmp) ++(u -> w); else insert(u -> c[cmp > 0], v, l);
	}

	int count(Node *u, char *v) {
		if (!u) return 0;
		int cmp = strcmp(v, u -> v);
		return cmp ? count(u -> c[cmp > 0], v) : u -> w;
	}

} t1, t2;

char p[MAXN][MAXL];
int l[MAXN];

int main(void) {
	freopen("2392.in", "r", stdin);
	freopen("2392.out", "w", stdout);
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", p[i]);
		l[i] = strlen(p[i]); //printf("%s %d\n", p[i], l[i]);
		t1.insert(t1.r, p[i], l[i]);
	}
	int a = 0;
	for (int i = 0; i < N; i++) {
		t2.clear();
		for (int j = 0; j < l[i]; j++) {
			char s[MAXL];
			for (int k = 0; j + k < l[i]; k++) {
				s[k] = p[i][j + k]; s[k + 1] = '\0';
				if (!t2.count(t2.r, s)) {
					t2.insert(t2.r, s, k + 1);
					a += t1.count(t1.r, s);
				}
			}
		}
		--a;
	}
	printf("%d\n", a);
	return 0;
}
