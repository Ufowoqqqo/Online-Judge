#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = 2000 + 10;
const int prime = 1000007;

struct Data { LL value; int info; }; //数值和位置

int n;
LL a[maxn];


#define inf 1000000000 //最大值，越界就不必考虑了

vector <Data> hash[prime];

void insert1(LL val, int pos) { //往 hash 表中插入值
    int y = (val + inf) % prime;
    hash[y].push_back((Data){val, pos});
}

int find1(LL val) {
    int y = (val + inf) % prime; //注意差值可能为负数，统一加上偏移量！
    int ret = n;
    int len = hash[y].size();
    for (int i = 0; i < len; i++)
        if (hash[y][i].value >= val) ret = min(ret, hash[y][i].info); //贪心思想：如果有多个数，找最前面的一个
    if (ret == n) return -1; else return ret; //编号为 0~n-1，若扫完一遍仍为 n 则说明找不到
}

int main(void) {
    freopen("1827.in", "r", stdin);
    freopen("1827.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        insert1(a[i], i);
    }
    int ans = 1;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            LL c = a[j] - a[i]; //数列公差
            int sum = 2; //数列长度，至少有 a[i] 和 a[j] 这两项
            LL num = a[j] + c;
            int p = j; //迭代用
            int t = find1(num);
            while (t > p) {
                sum++;
                p = t;
                num += c;
                if (num>inf||num<0)break; //越界处理
                t = find1(num);
            }
            ans = max(ans, sum);
        }
    }

    printf("%d\n", ans);
    return 0;
}
