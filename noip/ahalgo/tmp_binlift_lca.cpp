//倍增求LCA
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<queue>
#define nqp main

using namespace std;

const int maxn = 500010;
int head[maxn],f[maxn][21],deep[maxn];
int n,m,root,cur;

struct hzw
{
    int to,next;
}tree[maxn<<1];

void add(int u, int v)
{
    tree[++cur].next = head[u];
    tree[cur].to = v;
    head[u] = cur;
}

void dfs(int u, int fa)
{
    f[u][0] = fa;
    deep[u] = deep[fa] + 1;
    for(int i=head[u]; i; i=tree[i].next)
    {
        int v = tree[i].to;
        if(v == fa) continue;
        dfs(v,u);
    }
}

int LCA(int a, int b)
{
    if(deep[a] > deep[b]) swap(a,b);
    for(int i=20; i>=0; i--)
    {
        if(deep[a] <= deep[b] - (1<<i))
        {
            b = f[b][i];
        }
    }
    if(a == b) return a;
    for(int i=20; i>=0; i--)
    {
        if(f[a][i] == f[b][i]) continue;
        a = f[a][i];
        b = f[b][i];
    }
    return f[a][0];
}

int nqp()
{
    ios :: sync_with_stdio(false);
    cin >> n >> m >> root;
    for(int i=1; i<=n; i++)
    {
        int u,v;
        cin >> u >> v;
        add(u,v);
        add(v,u);
    }
    dfs(root,0);
    for(int i=1; i<=20; i++)
    {
        for(int j=1; j<=n; j++)
        {
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
    int ans = 0;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin >> a >> b;
        int ans = LCA(a,b);
        cout << ans << endl;
    }
    return 0;
}

