#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int MAXR = 2e6;
const int MAXT = 2e3;

int belong[MAXR];

queue <int> whole, each[MAXT];

int main(void) {
	for (int t, kase = 1; ~scanf("%d", &t) && t; kase++) {
		for (int i = 0; i < t; i++) {
			int c; scanf("%d", &c); for (int j = 0; j < c; j++) { int x; scanf("%d", &x); belong[x] = i; } for (; !each[i].empty(); each[i].pop());
		}
		char op[10]; scanf("%s", op); for (; !whole.empty(); whole.pop());
		printf("Scenario #%d\n", kase);
		for (; strcmp(op, "STOP"); ) {
			if (!strcmp(op, "ENQUEUE")) { int x; scanf("%d", &x); if (each[belong[x]].empty()) whole.push(belong[x]); each[belong[x]].push(x); }
			if (!strcmp(op, "DEQUEUE")) { printf("%d\n", each[whole.front()].front()); each[whole.front()].pop(); if (each[whole.front()].empty()) whole.pop(); }
			scanf("%s", op);
		}
		putchar('\n');
	}
	return 0;
}
