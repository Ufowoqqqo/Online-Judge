#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define INF 1000000001
using namespace std;

class Splay
{
public:
    class Node
    {
    public:
        Node *c[2], *p;
        int v, s, m, d;
        Node(Node *_p, int _v, int _d) : p(_p), v(_v), s(1), m(_v), d(_d)
        {
            c[0] = c[1] = NULL;

            return;
        }

        int relation(void)
        {
            return p->c[1] == this;
        }

        void setChild(Node *_c, int r)
        {
            c[r] = _c;
            if(_c)
                _c->p = this;

            return;
        }

        void maintain(void)
        {
            s = (c[0] ? c[0]->s : 0) + 1 + (c[1] ? c[1]->s : 0);
            m = max(v, max(c[0] ? c[0]->m : -INF, c[1] ? c[1]->m : -INF));

            return;
        }

        void rotate(void)
        {
            Node *_p;
            int r;

            _p = p;
            r = relation();
            p = _p->p;
            if(p)
                p->c[_p->relation()] = this;
            _p->setChild(c[r ^ 1], r);
            _p->maintain();
            setChild(_p, r ^ 1);
            maintain();

            return;
        }

        void out(void)
        {
            if(c[0])
                c[0]->out();
            if(v != -INF)
                printf("%d ", d);
            if(c[1])
                c[1]->out();

            return;
        }
    } *r;
    Splay(void) : r(NULL)
    {
        return;
    }

    void splay(Node *x, Node *p = NULL)
    {
        for(; x->p != p; x->rotate())
            if(x->p->p != p && x->relation() == x->p->relation())
                x->p->rotate();

        if(!p)
            r = x;

        return;
    }

    Node *find(Node *x, int k)
    {
        int t;

        if(!x || k < 1 || x->s < k)
            return NULL;

        t = x->c[0] ? x->c[0]->s : 0;
        if(k <= t)
            return find(x->c[0], k);
        if(k == t + 1)
            return x;

        return find(x->c[1], k - t - 1);
    }

    void insert(int k, int v, int d)
    {
        Node *x, *y, *z;

        x = find(r,     1);
        y = find(r, k + 1);
        splay(x);
        splay(y, x);

        z = new Node(r, v, d);
        z->setChild(y->c[0], 0);
        y->c[0] = NULL;
        y->maintain();

        z->setChild(y      , 1);
        z->maintain();

        r->setChild(z, 1);
        r->maintain();
        splay(z);

        return;
    }

    int query(int p, int q)
    {
        Node *x, *y;

        x = find(r, p - 1);
        y = find(r, q + 1);
        splay(x   );
        splay(y, x);

        return r->c[1]->c[0]->m;
    }
} g;

int main(void)
{
    int n;
    int i;
    int a, c;
    int l, r, m;

    freopen("t.in" , "r", stdin );
//    freopen("t.out", "w", stdout);

    scanf("%d", &n);
	g.r = new Splay::Node(NULL, -INF, 0);
	g.r->c[1] = new Splay::Node(g.r, -INF, 0);
	g.r->maintain();
    for(i = 1; i <= n; i ++)
    {
        scanf("%d %d", &a, &c);
        for(l = max(i - c - 1, 0), r = i; l + 1 < r; )
        {
            m = (l + r) >> 1;
            printf("[%d, %d] %d\n", m + 1, i, g.query(m + 1, i));
            (g.query(m + 1, i) < a ? r : l) = m;
        }
        g.insert(r, a, i);
    }
    g.r->out();

    return 0;
}
