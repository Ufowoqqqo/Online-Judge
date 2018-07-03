//2392.cpp
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MAXL = 15;
const int MAXN = 2e4 + 100;
const int MAXP = 3e5 + 1;

struct Data {
	char s[MAXL];
	int l, h, v, t;
	bool operator < (const Data x) const { return l < x.l || l == x.l && strcmp(s, x.s) < 0; }
} user[MAXN];

int calc(char *str, int l) {
	int r = 1;
	for (int i = 0; i < l; i++) r = (r * 26 % MAXP + str[i] - 'a') % MAXP;
	return r;
}

vector <Data> hash[MAXP];

int ask(char *str, int l, int tick) {
	int h = calc(str, l);
	for (int i = 0; i < hash[h].size(); i++)
		if (hash[h][i].l == l && hash[h][i].t != tick) {
			bool b = true;
			for (int j = 0; j < l; j++) if (str[j] != hash[h][i].s[j]) { b = false; break; }
			if (b) { hash[h][i].t = tick; return hash[h][i].v; }
		}
	return 0;
}

void add(int id) {
	for (int i = 0; i < hash[user[id].h].size(); i++)
		if (hash[user[id].h][i].l == user[id].l && !strcmp(user[id].s, hash[user[id].h][i].s)) { ++hash[user[id].h][i].v; return ; }
	hash[user[id].h].push_back(user[id]);
}

int main(void) {
	freopen("2392.in", "r", stdin);
	freopen("2392.out", "w", stdout);
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", user[i].s);
		user[i].l = strlen(user[i].s);
		user[i].h = calc(user[i].s, user[i].l);
		user[i].v = 1;
	}
	sort(user, user + N);
	int a = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < user[i].l; j++)
			for (int k = 0; j + k < user[i].l; k++) {
				int a_ = ask(user[i].s + j, k + 1, i + 1);
				if (!j && k + 1 == user[i].l) a += a_ * 2; else a += a_;
			}
		add(i);
//		printf("%d\n", a);
	}
	printf("%d\n", a);
	return 0;
}
