//2391.cpp
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 15;

char m[MAXN][MAXN];

int main(void) {
	freopen("2391.in", "r", stdin);
	freopen("2391.out", "w", stdout);
	int N, M, a; scanf("%d%d", &N, &M);
	
	for (int i = 0; i < N; i++) scanf("%s", m[i]);
	
	a = 0;
	for (int i = 0; i + 1 < N; i++)
		for (int j = 0; j + 1 < M; j++)
			a += m[i][j] != '.' && m[i][j + 1] == m[i][j] && m[i + 1][j] == m[i][j] && m[i + 1][j + 1] == m[i][j];
	printf("%d\n", a);
	
	a = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j + 3 < M; j++)
			a += m[i][j] != '.' && m[i][j + 1] == m[i][j] && m[i][j + 2] == m[i][j] && m[i][j + 3] == m[i][j];
	for (int i = 0; i + 3 < N; i++)
		for (int j = 0; j < M; j++)
			a += m[i][j] != '.' && m[i + 1][j] == m[i][j] && m[i + 2][j] == m[i][j] && m[i + 3][j] == m[i][j];
	printf("%d\n", a);
	
	a = 0;
	for (int i = 0; i + 1 < N; i++)
		for (int j = 0; j + 2 < M; j++)
			a += m[i][j + 1] != '.' && m[i][j + 2] == m[i][j + 1] && m[i + 1][j] == m[i][j + 1] && m[i + 1][j + 1] == m[i][j + 1];
	for (int i = 0; i + 2 < N; i++)
		for (int j = 0; j + 1 < M; j++)
			a += m[i][j] != '.' && m[i + 1][j] == m[i][j] && m[i + 1][j + 1] == m[i][j] && m[i + 2][j + 1] == m[i][j];
	printf("%d\n", a);
	
	a = 0;
	for (int i = 0; i + 1 < N; i++)
		for (int j = 0; j + 2 < M; j++)
			a += m[i][j] != '.' && m[i][j + 1] == m[i][j] && m[i + 1][j + 1] == m[i][j] && m[i + 1][j + 2] == m[i][j];
	for (int i = 0; i + 2 < N; i++)
		for (int j = 0; j + 1 < M; j++)
			a += m[i][j + 1] != '.' && m[i + 1][j] == m[i][j + 1] && m[i + 1][j + 1] == m[i][j + 1] && m[i + 2][j] == m[i][j + 1];
	printf("%d\n", a);
	
	a = 0;
	for (int i = 0; i + 1 < N; i++)
		for (int j = 0; j + 2 < M; j++)
			a += m[i][j + 1] != '.' && m[i + 1][j] == m[i][j + 1] && m[i + 1][j + 1] == m[i][j + 1] && m[i + 1][j + 2] == m[i][j + 1];
	for (int i = 0; i + 2 < N; i++)
		for (int j = 0; j + 1 < M; j++)
			a += m[i][j] != '.' && m[i + 1][j] == m[i][j] && m[i + 1][j + 1] == m[i][j] && m[i + 2][j] == m[i][j];
	for (int i = 0; i + 1 < N; i++)
		for (int j = 0; j + 2 < M; j++)
			a += m[i][j] != '.' && m[i][j + 1] == m[i][j] && m[i][j + 2] == m[i][j] && m[i + 1][j + 1] == m[i][j];
	for (int i = 0; i + 2 < N; i++)
		for (int j = 0; j + 1 < M; j++)
			a += m[i][j + 1] != '.' && m[i + 1][j] == m[i][j + 1] && m[i + 1][j + 1] == m[i][j + 1] && m[i + 2][j + 1] == m[i][j + 1];
	printf("%d\n", a);
	
	return 0;
}
