#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int c[20];

int main(void) {
	freopen("2390.in", "r", stdin);
	freopen("2390.out", "w", stdout);
	int N, s = 0; scanf("%d", &N);
	for (int i = 2; i <= 9; i++) c[i] = 4;
	c[10] = 16;  c[11] = 4;
	for (int i = 0; i < N; i++) {
		int x; scanf("%d", &x);
		--c[x]; s += x;
	}
	int d = 21 - s, vuci = 0, dosta = 0;
	for (int i = 2; i <= d; i++) vuci += c[i];
	for (int i = d + 1; i <= 11; i++) dosta += c[i];
//	printf("%d %d\n", vuci, dosta);
	puts(vuci >= dosta ? "VUCI" : "DOSTA");
	return 0;
}
