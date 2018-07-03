#include <algorithm>
//#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5;
const int MAXT = 30;

vector <int> v[MAXN], leaves;
int N, T = 17, l[MAXN], r[MAXN], cur, d[MAXN], f[MAXN][MAXT];

void dfs(int u, int p) {
//	printf("%d %d\n", u, p);
	if ((signed)v[u].size() == 1) leaves.push_back(u);
	l[u] = ++cur;
	f[u][0] = p; for (int i = 1; i <= T; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	for (int i = 0; i < (signed)v[u].size(); i++)
		if (v[u].at(i) != p) { d[v[u].at(i)] = d[u] + 1; dfs(v[u].at(i), u); }
	r[u] = cur;
}

bool cmp(int x, int y) { return d[x] < d[y]; }

int t[MAXN];
void add(int p, int v) { for (int i = p; i <= N; i += (i & -i)) t[i] += v; }
int ask(int p) { int s = 0; for (int i = p; i; i -= (i & -i)) s += t[i]; return s; }

int getp(int u, int d) {
	int p = u;
	for (int i = 0; i <= T; i++) if ((1 << i) & d) p = f[p][i];
	return p;
}

int main(void) {
	freopen("2537.in", "r", stdin);
	freopen("2537.out", "w", stdout);
	int K; scanf("%d%d", &N, &K); //T = log2(N); //printf("%d %d\n", N, T);
	for (int i = 1; i < N; i++) { int a, b; scanf("%d%d", &a, &b); v[a].push_back(b); v[b].push_back(a); }
	if ((signed)v[K].size() == 1) { puts("1"); return 0; }
	dfs(K, K); sort(leaves.begin(), leaves.end(), cmp); //puts("dfs");
	int ans = 0;
	for (int i = 0; i < (signed)leaves.size(); i++)
		if (!ask(l[leaves.at(i)])) {
			++ans; int x = getp(leaves.at(i), d[leaves.at(i)] >> 1);
//			printf("%d %d %d\n", x, l[x], r[x]);
			add(l[x], 1); add(r[x] + 1, -1);
//			for (int j = 0; j <= N; j++) printf("%d ", t[j]); putchar('\n');
		}
	printf("%d\n", ans);
	return 0;
}
