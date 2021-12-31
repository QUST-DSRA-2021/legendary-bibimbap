#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <cstdio>

using namespace std;

int read()
{
    char c = ' ';
    while(c<'0' || c>'9') c = getchar();
    int v = 0;
    while(c>='0' && c<='9')
    {
        v = v * 10 + c - '0';
        c = getchar();
    }
    return v;
}

const int maxn = 100010;
int head[maxn],cur,n,m,s,son[maxn],id[maxn],size[maxn],f[maxn],top[maxn],deep[maxn];

struct hzw
{
    int next,to;
}edge[maxn<<1];

void add(int u, int v)
{
    edge[++cur].next = head[u];
    edge[cur].to = v;
    head[u] = cur;
}

void dfs1(int u, int fa, int dep)
{
    size[u] = 1;
    deep[u] = dep;
    f[u] = fa;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v == fa) continue;
        dfs1(v,u,dep+1);
        size[u] += size[v];
        if(son[u] == -1 || size[v] > size[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int t)
{
    top[u] = t;
    if(son[u]==-1) return;
    dfs2(son[u],t);
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v == f[u] || v == son[u]) continue;
        dfs2(v,v); 
    }
}
int LCA(int x, int y)
{
    while(top[x] != top[y])
    {
        if(deep[top[x]] < deep[top[y]]) swap(x,y);
        x = f[top[x]];
    }    
    if(deep[x] > deep[y]) swap(x,y);
    return x;
}

int main()
{
    memset(son,-1,sizeof(son));
    memset(head,-1,sizeof(head));
    n = read(), m = read(), s = read();
    for(int i=1; i<=n-1; i++)
    {
        int a,b;
        a = read(), b = read();
        add(a,b);
        add(b,a);
    }
    dfs1(s,0,0);
    dfs2(s,s);
    for(int i=1; i<=m; i++)
    {
        int a,b;
        a = read(), b = read();
        cout << LCA(a,b) << endl;
    }
    return 0;
}

