#include<bits/stdc++.h>
using namespace std;
#define pfc(x) printf("Case %d: ",x)
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sf4(x,y,z,m) scanf("%d%d%d%d",&x,&y,&z,&m)
#define pf1(x) printf("%d\n",x)
#define pf2(x,y) printf("%d %d\n",x,y)
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pf4(x,y,z,m) printf("%d %d %d %d\n",x,y,z,m)
#define pii pair<long long,long long>
#define pb push_back
struct lol
{
    int uu;
    int vv;
    int w;
};
class comp
{
public:
    bool operator()(lol a,lol b)
    {
        return a.w>b.w;
    }
};
int par[1000];
lol s[1000];
void makeset(int n)
{
    for(int i=1; i<=n; i++)par[i]=i;
}
int found(int n)
{
    if(par[n]==n)return n;
    else
    {
        par[n]=found(par[n]);
        return par[n];
    }
}
int mst(int n,int m)
{
    int coun=0,ans=0;
    for(int i=0; i<m; i++)
    {
        int u,v;
        u=found(s[i].uu);
        v=found(s[i].vv);
        if(u!=v)
        {
            coun++;
            ans+=s[i].w;
            par[v]=u;
            if(coun==n-1)
            {
                break;
            }
        }
    }
    return ans;
}
int main()
{
    int tst,t=0;
    int n,m;
    sf2(n,m);
    for(int i=0; i<m; i++)sf3(s[i].uu,s[i].vv,s[i].w);
    sort(s,s+m,comp());
    makeset(n);
    int ans=mst(n,m);
    pf1(ans);
    return 0;
}
/*
6 9
1 4 1
1 2 3
2 4 3
2 3 1
3 4 1
4 5 6
3 5 5
3 6 4
5 6 2

*/

