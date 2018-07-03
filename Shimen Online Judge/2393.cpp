//2393.cpp
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 5e5 + 100;

typedef long long LL;

typedef pair <LL, LL> pll;

struct PART {
	LL k, l;
	int p;
	bool operator < (const PART y) const { return k > y.k; }
} skill[MAXN];
vector <PART> arr[10];

typedef pair <PART, int> MMP;

bool operator < (const MMP a, const MMP b) { return a.first.l > b.first.l; }

priority_queue <MMP> pq;

vector < pair < LL, pair <int, int> > > results;

int main(void) {
	freopen("2393.in", "r", stdin);
	freopen("2393.out", "w", stdout);
	LL M; int N; scanf("%lld%d", &M, &N);
	for (int i = 0; i < N; i++) { scanf("%lld%lld", &skill[i].k, &skill[i].l); skill[i].p = i; }
	sort(skill, skill + N);
//	for (int i = 0; i < N; i++) printf("%lld %lld %d\n", skill[i].k, skill[i].l, skill[i].p);
	LL Z = 0, j = 0;
	for (int i = 0; j < 6 * M; ) {
//		printf("%d %lld\n", i, j);
		if (j % M + skill[i].l <= M) {
			Z += skill[i].k * skill[i].l;
			arr[j / M].push_back((PART){skill[i].k, skill[i].l + j % M, skill[i].p});
			j += skill[i++].l;
		} else {
			long long dur = M - j % M;
			Z += skill[i].k * dur;
			skill[i].l -= dur;
			arr[j / M].push_back((PART){skill[i].k, M, skill[i].p});
			j += dur;
		}
	}
	/*
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < arr[i].size(); j++) printf("{%lld, %lld, %d}, ", arr[i][j].k, arr[i][j].l, arr[i][j].p);
		putchar('\n');
	}
	*/

	printf("%lld\n", Z);

	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i][0].p + 1);
		pq.push(make_pair(arr[i][0], i));
	}
	putchar('\n');

	int B = 0; int cur[10] = {0};
	for (; ; B++) {
		MMP u = pq.top(); pq.pop();
//		printf("u = {{%lld, %lld, %d}, %d}\n", u.first.k, u.first.l, u.first.p, u.second);
		if (u.first.l == M) break;
		results.push_back(make_pair(u.first.l, make_pair(u.first.p, arr[u.second][++cur[u.second]].p)));
		pq.push(make_pair(arr[u.second][cur[u.second]], u.second));
	}
	printf("%d\n", B);
	for (int i = 0; i < results.size(); i++) printf("%lld %d %d\n", results[i].first, results[i].second.first + 1, results[i].second.second + 1);

	return 0;
}
