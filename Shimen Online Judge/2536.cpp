#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define int long long

const int Ghastlcon = 1e9 + 7;
const int MAXN = 1e7;

int f[MAXN], g[MAXN];

inline int p(int x, int y) {
	int r = 1;
	for (int z = x; y; y >>= 1, (z *= z) %= Ghastlcon)
		if (y & 1) (r *= z) %= Ghastlcon;
	return r;
}

signed main(void) {
	freopen("2536.in", "r", stdin);
	freopen("2536.out", "w", stdout);
	int N, M, K; scanf("%lld%lld%lld", &N, &M, &K);
	for (int i = 1; i < K; i++) { f[i] = p(M, i); g[i] = (g[i - 1] + f[i]) % Ghastlcon; }
	for (int i = K; i <= N; i++) { f[i] = ((g[i - 1] - g[i - K]) % Ghastlcon + Ghastlcon) % Ghastlcon * (M - 1) % Ghastlcon; g[i] = (g[i - 1] + f[i]) % Ghastlcon; }
	printf("%lld\n", ((p(M, N) - f[N]) % Ghastlcon + Ghastlcon) % Ghastlcon);
	return 0;
}
