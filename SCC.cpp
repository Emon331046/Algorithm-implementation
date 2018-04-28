#include<bits/stdc++.h>
using namespace std;
#define pfc(x) printf("Case %d: ",x)
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sf4(x,y,z,m) scanf("%d%d%d%d",&x,&y,&z,&m)
#define pf1(x) printf(" %d\n",x)
#define pf2(x,y) printf("%d %d\n",x,y)
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pf4(x,y,z,m) printf("%d %d %d %d\n",x,y,z,m)
#define pii pair<long long,long long>
stack<int>st,rt;
int col[1000],vis[1000],cnt;
vector<int>g[1000],f[1000],r[1000];
void dfs(int u)
{
    col[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v;
        v=g[u][i];
        if(col[v]==0)
        {
            dfs(v);
        }
    }
    st.push(u);
}
void dfs2(int u)
{
    vis[u]=1;
    for(int i=0; i<f[u].size(); i++)
    {
        int v=f[u][i];
        if(vis[v]==0)
        {
            dfs2(v);
        }
    }
    r[cnt].push_back(u);
}
int main()
{
    int n,m,d;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        f[b].push_back(a);

    }
    for(int i=1; i<=n; i++)
    {
        if(col[i]==0)dfs(i);
    }
    while(!st.empty())
    {
        int top;
        top=st.top();
        if(vis[top]==0)
        {
            cnt++;
            dfs2(top);
        }
        st.pop();
    }
    cout<<cnt<<endl;
    return 0;
}

