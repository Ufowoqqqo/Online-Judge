#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int SIGMA_SIZE = 30;
const int MAXN = 200 + 100;
const int MAXL = 10 + 10;
const int MAXM = 2e5 + 100;

int maxl;

struct Trie {
	struct Node {
		int ch[SIGMA_SIZE];
		bool v;
	} nodes[MAXN * MAXL];
	int sz;
	Trie () { memset(nodes[0].ch, 0, sizeof nodes[0].ch); sz = 1; }
	int idx(char c) { return c - 'A'; }
	
	void insert(char *s) {
		int u = 0, n = strlen(s); maxl = max(maxl, n);
		for (int i = 0; i < n; i++) {
			int c = idx(s[i]);
			if (!nodes[u].ch[c]) {
				memset(nodes[sz].ch, 0, sizeof nodes[sz].ch);
				nodes[sz].v = false;
				nodes[u].ch[c] = sz++;
			}
			u = nodes[u].ch[c];
		}
		nodes[u].v = true;
	}
	
	bool query(char *s, int n) {
		int u = 0;
		for (int i = 0; i < n; i++) {
			int c = idx(s[i]);
			if (!nodes[u].ch[c]) return false;
			u = nodes[u].ch[c];
		}
		return nodes[u].v;
	}
} t;

char tmp[MAXL], str[MAXM];

bool f[200100];

int main(void) {
	freopen("2504.in", "r", stdin);
	freopen("2504.out", "w", stdout);
	for (; ~scanf("%s", tmp) && strcmp(tmp, "."); ) t.insert(tmp);
	int l = 0;
	for (; ~scanf("%s", str + l); l += strlen(str + l));
	int ans = 0;
	for (int i = 0; i < l; i++)
		for (int j = max(i - maxl, -1); j <= i; j++)
			if ((j == -1 || f[j]) && t.query(str + j + 1, i - j)) { //(*)
				f[i] = true;
				ans = i + 1;
				break;
			}
	printf("%d\n", ans);
	return 0;
}
