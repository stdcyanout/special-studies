#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define lc 2 * id + 1
#define rc 2 * id + 2

template <class ...T> void debug(T ...args)
{
    int cnt = sizeof...(T);
    ((cerr << "\e[1;31m"), ..., (cerr << args << (--cnt ? " " : "\e[0m\n")));
}
template <class T> void orange(T L, T R)
{
    cerr << "\e[1;31m";
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\e[0m\n";
}

const int INF = 1e9;
struct node
{
    pii val;
    int tag = 0;
};

int n, m, i, j;
int MIN, tp;
int dp[51][51];

void pull(node* seg, int id)
{
    seg[id].val = min(seg[lc].val, seg[rc].val);
}

void push(node* seg, int id)
{
    seg[lc].val.F += seg[id].tag;
    seg[rc].val.F += seg[id].tag;
    seg[lc].tag += seg[id].tag;
    seg[rc].tag += seg[id].tag;
    seg[id].tag = 0;
}

void init(node* seg, int L, int R, int id)
{
    if(L == R - 1)
    {
        seg[id].val = mp(0, L);
        return;
    }
    int M = (L + R) / 2;
    init(seg, L, M, lc);
    init(seg, M, R, rc);
    pull(seg, id);
}

void update(node* seg, int L, int R, int id, int l, int r, int v)
{
    if(R <= l || r <= L)
        return;
    if(l <= L && R <= r)
    {
        seg[id].val.F += v;
        seg[id].tag += v;
        return;
    }
    int M = (L + R) / 2;
    push(seg, id);
    update(seg, L, M, lc, l, r, v);
    update(seg, M, R, rc, l, r, v);
    pull(seg, id);
}

pii query(node* seg, int L, int R, int id, int l, int r)
{
    if(R <= l || r <= L)
        return mp(INF, 0);
    if(l <= L && R <= r)
        return seg[id].val;
    int M = (L + R) / 2;
    push(seg, id);
    return min(query(seg, L, M, lc, l, r), query(seg, M, R, rc, l, r));
}

int at(node* seg, int L, int R, int id, int pos)
{
    if(L == R - 1)
        return seg[id].val.F;
    int M = (L + R) / 2;
    push(seg, id);
    if(pos < M)
        return at(seg, L, M, lc, pos);
    else
        return at(seg, M, R, rc, pos);
}

void block(node* seg, int h, int k, int c)
{
    int l, t;
    c = c + 1;
    if(c < MIN)
    {
        l = 0;
        t = at(seg, 0, m, 0, h);
        while(h + l < m && k + l <= n && t >= at(seg, 0, m, 0, h + l))
        {
            assert(t == at(seg, 0, m, 0, h + l));
            l = l + 1;
            update(seg, 0, m, 0, h, h + l, l);
            if(h + l < m && t >= at(seg, 0, m, 0, h + l))
                block(seg, h + l, k, c);
            else
            {
                pii p = query(seg, 0, m, 0, 0, m);
                p.F += 1;
                if(p.F <= n)
                    block(seg, p.S, p.F, c);
                else
                    MIN = min(c, MIN);
                update(seg, 0, m, 0, h, h + l, -l);
                return;
            }
            update(seg, 0, m, 0, h, h + l, -l);
        }
    }
}

int f(int a, int b)
{
    int k;
    memset(dp, 0x3F, sizeof(dp));
    for(i = 1; i <= a; i++)
        for(j = 1; j <= b; j++)
        {
            if(i == j)
                dp[i][j] = 0;
            else
            {
                for(k = 1; k < i; k++)
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                for(k = 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    return dp[a][b] + 1;
}

signed main()
{
    clock_t a, b;
    node s[205];
    cin >> n >> m;
    init(s, 0, m, 0);
    tp = f(n, m);
    cout << "F = " << tp << "\n";
    MIN = tp;
    a = clock();
    block(s, 0, 1, 0);
    b = clock();
    cout << "MIN = " << MIN << "\n";
    cout << double(b - a) / CLOCKS_PER_SEC << "\n";
}