#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 5e4 + 100;

int n;
long long a[MAXN];

int main(void) {
	freopen("2247.in", "r", stdin);
	freopen("2247.out", "w", stdout);
	scanf("%d", &n);
	long long sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	sum /= n;
	for (int i = 0; i + 1 < n; i++) {
		if (a[i] != sum) {
			ans += abs(a[i] - sum);
			if (a[i] < sum) a[i + 1] -= (sum - a[i]); else a[i + 1] += (a[i] - sum);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
