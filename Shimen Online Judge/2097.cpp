#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 3e5;
const int SIGMA_SIZE = 2;
const int LEN = 31; //remember to recover here befor submit

typedef pair <int, int> pii;

vector <pii> g[MAXN];
int dis[MAXN];

bool vis[MAXN];
void bfs() { //in order to avoid RE
	memset(vis, false, sizeof vis); vis[0] = true;
	queue <int> q; for (; !q.empty(); q.pop());
	for (q.push(0); !q.empty();) {
		int u = q.front(); q.pop();
		for (int i = 0; i < (signed)g[u].size(); i++) {
			int v = g[u].at(i).first;
			if (!vis[v]) { vis[v] = true; dis[v] = dis[u] ^ g[u].at(i).second; q.push(v); }
		}
	}
}

int main(void) {
	freopen("2097.in", "r", stdin);
	freopen("2097.out", "w", stdout);
	int N, K; scanf("%d%d", &N, &K);
	for (int i = 1; i < N; i++) {
		int u, v, L; scanf("%d%d%d", &u, &v, &L);
		g[u].push_back(make_pair(v, L));
		g[v].push_back(make_pair(u, L));
	}
	bfs(); sort(dis, dis + N); long long ans = 0;
	for (int i = 0; i < LEN; i++) { //前 (LEN - i - 1) 位为公共前缀
		if (K & 1) { //令当前位为 x ^ y 与 k 不同的最高位，且该位上 k 为 1，x ^ y 为 0
			for (int j = 0; j < N; j++) {
				int y = dis[j] ^ (K & ~1); //将当前位置为 0 并推出相应公共前缀
				pair <int*, int*> range = equal_range(dis, dis + N, y); //统计具有这种前缀的数的个数
				ans += range.second - range.first - (dis[j] == y); //注意可能要减去自身，(1,1)不是一对点
			} 
		}
		K >>= 1; //当前位向前移
		if (!K) break;
		for (int j = 0; j < N; j++) dis[j] >>= 1;
	}
	printf("%lld\n", ans >> 1); //(1,2)和(2,1)算作同一对点
	return 0;
}
