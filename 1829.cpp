#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 10;
const int maxk = 30 + 5;
const int prime = 1e6 + 7;

int n, k;
int set[maxn];
int presum[maxn][maxk];
int diff[maxn][maxk];

vector <int> hash[prime];

bool issame(int x, int y) {
	for (int i = 0; i + 1 < k; i++)
		if (diff[x][i] != diff[y][i]) return false;
	return true;
}

int find(int num, int *arr) {
	int val = 0;
	for (int i = 0; i + 1 < k; i++) val = (val  + arr[i]) % prime*107LL %prime;
	//(val += 30000000) %= prime;
	hash[val].push_back(num);
	int len = hash[val].size(); int pos = num;
	for (int i = 0; i < len; i++)
		if (issame(num, hash[val][i])) pos = min(pos, hash[val][i]);
	return pos;
}

int main(void) {
	//freopen("1829.in", "r", stdin);
	//freopen("1829.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &set[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k; j++)
			presum[i][j] = presum[i - 1][j] + (bool)(set[i] & (1 << j));
	
	int ans = 0;
	for (int j = 1; j < k; j++) diff[0][j - 1] = 100000;
	find(0, diff[0]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < k; j++) diff[i][j - 1] = presum[i][j] - presum[i][j - 1] + 100000;
		ans = max(ans, i - find(i, diff[i]));
		//printf("%d\n", ans);
	}
	printf("%d\n", ans);
	return 0;
}
