#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 200020
#define T 20
using namespace std;

int s[N];
int n, w, a[N], c[N], h[N][T], r[N], p[N], q[N];

inline int query(int x, int y)
{
	int d;

	if(y < x)
		return w - 1;

	d = log2(y - x + 1);

	return min(h[x][d], h[y - (1 << d) + 1][d]);
}

int findl(void)
{
	int l, r, m;

	for(l = 0, r = ::r[n - w + 2]; l + 1 < r; )
	{
		m = (l + r) >> 1;
		(w <= query(m + 1, ::r[n - w + 2]) + 1 ? r : l) = m;
	}

	return r;
}

int findr(void)
{
	int l, r, m;

	for(l = ::r[n - w + 2], r = n + 1; l + 1 < r; )
	{
		m = (l + r) >> 1;
		(w <= query(::r[n - w + 2] + 1, m) + 1 ? l : r) = m;
	}

	return l;
}

int main(void)
{
	int m, t;
	int i, j, k, l, p;
	int *x, *y;
	vector<int> v;

	freopen("t.in", "r", stdin);

	scanf("%d %d", &n, &w);

	for(i = 1; i <= n; i ++)
		scanf("%d", &::p[i]);
	for(i = 1; i <= w; i ++)
		scanf("%d", &q[i]);

	for(i = 1; i < n; i ++)
		::p[i] = ::p[i + 1] - ::p[i] + 1000000000;
	for(::p[n] = 2000000001, i = n + 1; i < n + w; i ++)
		::p[i] = q[i - n + 1] - q[i - n] + 1000000000;
	n += w - 1;

	v.clear();
	for(i = 1; i <= n; i ++)
		v.push_back(::p[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(i = 1; i <= n; i ++)
		::p[i] = lower_bound(v.begin(), v.end(), ::p[i]) - v.begin() + 1;

	for(i = 1, m = 0, x = ::p, y = q; i <= n; i ++)
	{
		m = max(m, x[i]);
		++ c[x[i]];
		s[i] = x[i];
	}
	for(i = 1; i <= m; i ++)
		c[i] += c[i - 1];
	for(i = n; i; i --)
		a[c[x[i]] --] = i;

	for(l = 1; l <= n; l <<= 1)
	{
		for(p = 0, i = n - l + 1; i <= n; i ++)
			y[++ p] = i;
		for(i = 1; i <= n; i ++)
			if(l < a[i])
				y[++ p] = a[i] - l;

		memset(c, 0, sizeof c);
		for(i = 1; i <= n; i ++)
			++ c[x[y[i]]];
		for(i = 1; i <= m; i ++)
			c[i] += c[i - 1];
		for(i = n; i; i --)
			a[c[x[y[i]]] --] = y[i];

		swap(x, y);
		x[a[1]] = m = 1;
		for(i = 2; i <= n; i ++)
			if(y[a[i]] == y[a[i - 1]] && y[a[i] + l] == y[a[i - 1] + l])
				x[a[i]] = m;
			else
				x[a[i]] = ++ m;
		if(m == n)
			break;
	}

	for(i = 1; i <= n; i ++)
		r[a[i]] = i;

	for(i = 1, k = 0; i <= n; i ++)
	{
		if(k) -- k;
		if(r[i])
			while(s[i + k] == s[a[r[i] - 1] + k])
				++ k;
		h[r[i]][0] = k;
	}

	for(i = 1, t = log2(n); i <= t; i ++)
		for(j = 1; j + (1 << i) <= n + 1; j ++)
			h[j][i] = min(h[j][i - 1], h[j + (1 << (i - 1))][i - 1]);

	printf("%d\n", findr() - findl());

	return 0;
}