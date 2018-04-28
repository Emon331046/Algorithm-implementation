#include<bits/stdc++.h>
using namespace std;
#define pfc(x) printf("Case %d: ",x)
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sf4(x,y,z,m) scanf("%d%d%d%d",&x,&y,&z,&m)
#define pf1(x) printf(" %d",x)
#define pf2(x,y) printf("%d %d\n",x,y)
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pf4(x,y,z,m) printf("%d %d %d %d\n",x,y,z,m)
#define pii pair<long long,long long>
long long inf = 2147483647154869;
long long d[100005];
int parent[100005];
vector<pii>g[100005];
void dijkstra(int source)
{
    d[1]=0;
    int i;
    priority_queue<pii> q;
    q.push(pii(1,0));
    while(!q.empty())
    {
        long long u,c;
        u=q.top().first;
        c=q.top().second;
        q.pop();
        if(d[u]<c)continue;
        for(i=0; i<g[u].size(); i++)
        {
            long long w,v;
            v=g[u][i].first;
            w=g[u][i].second;
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                q.push(pii(v,d[v]));
                parent[v]=u;
            }
        }
    }
}
void prntpath(int temp)
{
    if(temp==1)
    {
        printf("1");
        return;
    }
    prntpath(parent[temp]);
    printf(" %d",temp);
}
int main()
{
    int n,m;
    sf2(n,m);
    int u,v,w,i;
    for(i=0; i<=n; i++)
    {
        d[i]=2147483647154869;
        g[i].clear();
    }
    while(m--)
    {
        sf3(u,v,w);

        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
    }
    dijkstra( n);
    if(d[n]==2147483647154869)printf("-1");
    else
    {
        prntpath(n);
    }
    printf("\n");
    return 0;
}
